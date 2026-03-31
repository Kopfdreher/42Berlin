#include "defines.hpp"
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <netinet/in.h>
#include <sstream>
#include <string>
#include <sys/epoll.h>
#include <sys/socket.h>
#include <unistd.h>

size_t getContentLength(const std::string &raw_request) {
  size_t pos = raw_request.find("Content-Length: ");
  if (pos != std::string::npos) {
    // Move the position to the start of the actual number
    pos += 16;
    size_t end_pos = raw_request.find("\r\n", pos);
    std::string length_str = raw_request.substr(pos, end_pos - pos);
    return std::atoi(length_str.c_str());
  }
  return 0; // If no Content-Length header, the body size is 0
}

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

std::string handleRequest(const HttpRequest &req, const ServerConfig &config,
                          const std::string &body) {

  // Build the dynamic filepath using the config!
  std::string filepath =
      config.root + (req.uri == "/" ? "/" + config.index : req.uri);

  // CGI Routing
  // If the URI ends with ".py", we route it to the CGI executor
  if (filepath.length() >= 3 &&
      filepath.substr(filepath.length() - 3) == ".py") {
    // Check if the file actually exiss before running it
    if (access(filepath.c_str(), F_OK) == -1) {
      return "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
    }
    return executeCGI(filepath, req, body);
  }

  // NEW: Delete Routing
  if (req.method == "DELETE") {
    // std::remove takes a const char * and returns 0 on success
    if (std::remove(filepath.c_str()) == 0) {
      // 204 No Content is the standard HTTP response for a successful DELETE
      // that doesn't return a message body.
      return "HTTP/1.1 204 No Content\r\nContent-Length: 0\r\n\r\n";
    } else {
      // If std::remove returns non-zero, the file didn't exist or we lacked
      // permission
      return "HTTP/1.1 404 Not Found\r\nContent-Length: 0\r\n\r\n";
    }
  }

  // Static File Routing
  if (req.method != "GET") { // Client requests information from the server
    return "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
  }

  std::ifstream file(filepath.c_str(), std::ios::in | std::ios::binary);
  if (!file.is_open()) {
    std::string err_body = "<html><body><h1>404 Not Found</h1></body></html>";
    std::ostringstream response;
    response << "HTTP/1.1 404 Not Found\r\nContent-Length: "
             << err_body.length() << "\r\n\r\n"
             << err_body;
    return response.str();
  }

  std::ostringstream file_content;
  file_content << file.rdbuf();
  std::string file_body = file_content.str();

  std::ostringstream response;
  // Messages consist of a start line, headers, an empty line (\r\n), and an
  // optional body
  response << "HTTP/1.1 200 OK\r\n"
           << "Content-Type: text/html\r\n"
           << "Content-Length: " << file_body.length() << "\r\n\r\n"
           << file_body;
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
  std::map<int, std::string> client_buffers;

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
        // We define a BUFFER_SIZE and read data in chunks
        char buffer[8192] = {0};
        int bytes_read = read(current_fd, buffer, sizeof(buffer));

        if (bytes_read < 0) {
          std::cerr << "Read error on FD " << current_fd << std::endl;
          client_sockets.erase(current_fd);
          client_buffers.erase(current_fd);
          close(current_fd);
        } else if (bytes_read == 0) {
          std::cout << "Client disconnected normally." << std::endl;
          client_sockets.erase(current_fd);
          client_buffers.erase(current_fd);
          close(current_fd);
        } else {
          // 1. Accumulate the chunk! Append the new bytes to this specific
          // client's buffer
          client_buffers[current_fd].append(buffer, bytes_read);

          std::string &current_buffer =
              client_buffers[current_fd]; // Reference for cleaner code

          // 2. Do we have the full headers yet?
          // Messages consist of a start line, headers, an empty line (\r\n),
          // and an optional body.
          size_t header_end = current_buffer.find("\r\n\r\n");

          if (header_end != std::string::npos) {
            // We have the headers! Let's check how much body we are expecting.
            size_t header_size =
                header_end + 4; // +4 to include the \r\n\r\n itself
            size_t expected_body_size = getContentLength(current_buffer);
            size_t actual_body_size = current_buffer.length() - header_size;

            // 3. Security Check: Client Max body Size Limit
            ServerConfig active_config = client_sockets[current_fd];
            if (expected_body_size > active_config.client_max_body_size) {
              std::string error_response =
                  "HTTP/1.1 413 Payload Too Large\r\nContent-Length: 0\r\n\r\n";
              write(current_fd, error_response.c_str(),
                    error_response.length());

              client_sockets.erase(current_fd);
              client_buffers.erase(current_fd);
              close(current_fd);
              continue; // Skip to the next event
            }

            // 4. Have we received the entire body?
            if (actual_body_size >= expected_body_size) {
              // YES! The request is 100% complete. Now we process it.
              std::cout << "Full request received! Total size: "
                        << current_buffer.length() << "bytes." << std::endl;

              HttpRequest parsed_req = parseRequest(current_buffer);

              // Extract the body payload to send to CGI
              // header_size was calculated just above as header_end + 4
              std::string actual_body = current_buffer.substr(header_size);

              // Pass actual_body as the 3rd argument
              std::string http_response =
                  handleRequest(parsed_req, active_config, actual_body);

              // Note: If response is massive, you will need to chunk the
              // write() call as well!
              write(current_fd, http_response.c_str(), http_response.length());

              // Cleanup the maps and close the connection (HTTP/1.0 style)
              client_sockets.erase(current_fd);
              client_buffers.erase(current_fd);
              close(current_fd);
            } else {
              // NO. We have the headers, but the body is incomplete.
              // We simply do nothing and let the loop continue.
              // epoll will wake us up again when the next chunk arrives.
              std::cout << "Chunk received. Waiting for rest of body..."
                        << std::endl;
            }
          }
          // If header_end == std::string::npos, we don't even have full headers
          // yet. Do nothing, wait for the next epoll trigger!
        }
      }
    }
  }
  close(epoll_fd);
  return 0;
}
