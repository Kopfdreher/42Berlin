#include "defines.hpp"
#include <cstring>
#include <fstream>
#include <iostream>
#include <netinet/in.h>
#include <sstream>
#include <string>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

#define PORT 8080
#define MAX_EVENTS 10 // Max events epoll_wait will return at once

// HTTP Parsing Structures & Functions

struct HttpRequest {
  std::string method;
  std::string uri;
  std::string version;
};

HttpRequest parseRequest(const std::string &raw_request) {
  HttpRequest req;

  // Find the end of the start line
  size_t line_end = raw_request.find("\r\n");
  if (line_end == std::string::npos)
    return req;

  std::string request_line = raw_request.substr(0, line_end);

  // Extract Method, URI, and Version from the start line
  std::istringstream iss(request_line);
  iss >> req.method >> req.uri >> req.version;

  return req;
}

std::string handleRequest(const HttpRequest &req, const ServerConfig &config) {
  if (req.method != "GET") { // Client requests information from the server
    return "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
  }

  // Build the dynamic filepath using the config!
  std::string filepath =
      config.root + (req.uri == "/" ? "/" + config.index : req.uri);

  std::ifstream file(filepath.c_str(), std::ios::in | std::ios::binary);
  if (!file.is_open()) {
    std::string body = "<html><body><h1>404 Not Found</h1></body></html>";
    std::ostringstream response;
    response << "HTTP/1.1 404 Not Found\r\nContent-Length: " << body.length()
             << "\r\n\r\n"
             << body;
    return response.str();
  }

  std::ostringstream file_content;
  file_content << file.rdbuf();
  std::string body = file_content.str();

  std::ostringstream response;
  // Messages consist of a start line, headers, an empty line (\r\n), and an
  // optional body
  response << "HTTP/1.1 200 OK\r\n"
           << "Content-Type: text/html\r\n"
           << "Content-Length: " << body.length() << "\r\n\r\n"
           << body;
  return response.str();
}
// Main Server Logic

int main(int argc, char **argv) {
  // 1. CONFIGURATION PHASE (Throw exceptions here)
  std::string config_path = (argc == 2) ? argv[1] : "webserv.conf";
  std::vector<ServerConfig> servers;

  try {
    servers = parseConfigFile(config_path);
  } catch (const std::exception &e) {
    std::cerr << "FATAL: Config Error: " << e.what() << std::endl;
    return 1; // Crash gracefully before the server even starts
  }

  // 2. EPOLL SETUP
  int epoll_fd = epoll_create(1);
  if (epoll_fd == -1) {
    std::cerr << "Failed to create epoll file descriptor" << std::endl;
    return 1;
  }

  // maps to track our sockets
  std::map<int, ServerConfig> server_sockets; // Maps a server_fd to its config
  std::map<int, ServerConfig>
      client_sockets; // Maps a client_fd to the server config it connected to

  // 3. DYNAMIC SOCKET SETUP (The Nginx-style logic)
  for (size_t i = 0; i < servers.size(); ++i) {
    int s_fd = socket(AF_INET, SOCK_STREAM, 0);
    int enable = 1;
    setsockopt(s_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));

    struct sockaddr_in address;
    std::memset(&address, 0, sizeof(address));
    address.sin_family = AF_INET;

    // Use the port number parse from the listen directive
    address.sin_port = htons(servers[i].listen_port);
    address.sin_addr.s_addr = htonl(INADDR_ANY);

    bind(s_fd, (struct sockaddr *)&address, sizeof(address));
    listen(s_fd, 10);

    std::cout << "Server spawnd on port " << servers[i].listen_port
              << std::endl;

    // Add this specific server socket to epoll
    struct epoll_event event;
    event.events = EPOLLIN;
    event.data.fd = s_fd;
    epoll_ctl(epoll_fd, EPOLL_CTL_ADD, s_fd, &event);

    // Save it to our map so we recognize it later
    server_sockets[s_fd] = servers[i];
  }

  // 4. THE EVENT LOOP (Use std::cerr and continue here)
  struct epoll_event events[10]; // MAX_EVENTS

  while (true) {
    int event_count = epoll_wait(epoll_fd, events, 10, -1);
    if (event_count == -1) {
      std::cerr << "epoll_wait failed, continuing..." << std::endl;
      continue;
    }

    for (int i = 0; i < event_count; ++i) {
      int current_fd = events[i].data.fd;

      // Case A: Is the triggered FD one of our listening Server sockets?
      // .count() checks if the key exists in the map
      if (server_sockets.count(current_fd) > 0) {
        struct sockaddr_in client_address;
        socklen_t client_addrlen = sizeof(client_address);

        int new_client_fd = accept(
            current_fd, (struct sockaddr *)&client_address, &client_addrlen);
        if (new_client_fd >= 0) {
          std::cout << "New connection accepted on port "
                    << server_sockets[current_fd].listen_port << std::endl;

          struct epoll_event event;
          event.events = EPOLLIN;
          event.data.fd = new_client_fd;
          epoll_ctl(epoll_fd, EPOLL_CTL_ADD, new_client_fd, &event);

          // Link the new client to the specific server configuration they
          // connected to!
          client_sockets[new_client_fd] = server_sockets[current_fd];
        }
      }
      // Case B: The event happened on a connected Client socket
      else {
        char buffer[1024] = {0};
        int bytes_read = read(current_fd, buffer, sizeof(buffer));

        if (bytes_read <= 0) {
          std::cout << "Client disconnected." << std::endl;
          client_sockets.erase(current_fd); // Clean up the map
          close(current_fd);
        } else {
          std::string raw_request(buffer, bytes_read);
          HttpRequest parsed_req = parseRequest(raw_request);

          // Pass the specific ServerConfig to handleRequest so it knows which
          // root/index to use
          ServerConfig active_config = client_sockets[current_fd];
          std::string http_response = handleRequest(parsed_req, active_config);

          write(current_fd, http_response.c_str(), http_response.length());

          client_sockets.erase(current_fd); // Clean up
          close(current_fd);
        }
      }
    }
  }
  close(epoll_fd);
  return 0;
}
