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
  if(!(iss >> req.method >> req.uri >> req.version)) {
    // Handle 400 Bad Request errorconfig 
  }

  return req;
}

std::string handleRequest(const HttpRequest &req) {
  // Only handle GET requests: Client requests information from the server
  if (req.method != "GET") {
    return "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
  }

  // Route to index.html if the root is requested
  std::string filepath = (req.uri == "/" ? "index.html" : req.uri.substr(1));

  // Try to open the requested file (using .c_str() for C++98 fstream
  // compatability)
  std::ifstream file(filepath.c_str(), std::ios::in | std::ios::binary);

  if (!file.is_open()) {
    // File not found: send 404 response-line
    std::string body = "<html><body><h1>404 Not Found</h1><p>The file doesn't "
                       "exist.</p></body></html>";
    std::ostringstream response;
    response << "HTTP/1.1 404 Not Found\r\n"
             << "Content-Type: text/html\r\n"
             << "Content-Length: " << body.length() << "\r\n"
             << "\r\n" // Empty line denotes end of headers
             << body;
    return response.str();
  }

  // Read the file content into our body payload
  std::ostringstream file_content;
  file_content << file.rdbuf();
  std::string body = file_content.str();

  // Craft the successful response starting with the response-line
  std::ostringstream response;
  response << "HTTP/1.1 200 OK\r\n"
           << "Content-Type: text/html\r\n"
           << "Content-Length: " << body.length() << "\r\n"
           << "\r\n" // Empty ine denotes end of headers
           << body;

  return response.str();
}

// Main Server Logic

int main() {
  // 1. Standard Socket Setup
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  int enable = 1;
  setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int));

  struct sockaddr_in address;
  std::memset(&address, 0, sizeof(address));
  address.sin_family = AF_INET;
  address.sin_port = htons(PORT);
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  bind(server_fd, (struct sockaddr *)&address, sizeof(address));
  listen(server_fd, 10);
  std::cout << "Server listening on port " << PORT << "..." << std::endl;

  // 2. EPOLL Setup
  // epoll_create() takes a size hint. Since LInux 2.6.8, the size is ignored,
  // but it must e greater than 0 for C++98/older kernel compatibility.
  int epoll_fd = epoll_create(1);
  if (epoll_fd == -1) {
    std::cerr << "Failed to create epoll file descriptor" << std::endl;
    return 1;
  }

  struct epoll_event event;
  struct epoll_event
      events[MAX_EVENTS]; // Array to hold the eventss triggered by OS

  // Add our server (listening) socket to the epoll instance
  event.events = EPOLLIN;    // We want to know when it's ready to read (accept)
  event.data.fd = server_fd; // Link it to our server socket

  // EPOLL_CTL_ADD tells epoll to start monitoring this file descriptor
  if (epoll_ctl(epoll_fd, EPOLL_CTL_ADD, server_fd, &event) == -1) {
    std::cerr << "Failed to add server_fd to epoll" << std::endl;
    return 1;
  }

  // 3. The Event Loop
  while (true) {
    // epoll_wait blocks until at least one event occurs.
    // It populates our 'events; array with ONLY the sockets that are ready.
    int event_count = epoll_wait(epoll_fd, events, MAX_EVENTS, -1);

    if (event_count == -1) {
      std::cerr << "epoll_wait failed" << std::endl;
      break;
    }

    // Notice we only loop up to 'event_count', not through all connected
    // clients!
    for (int i = 0; i < event_count; ++i) {

      // Case A: The event happened on the SERVER soket (New client connecting)
      if (events[i].data.fd == server_fd) {
        struct sockaddr_in client_address;
        socklen_t client_addrlen = sizeof(client_address);

        int new_client_fd = accept(
            server_fd, (struct sockaddr *)&client_address, &client_addrlen);
        if (new_client_fd >= 0) {
          std::cout << "New connection accepted! FD: " << new_client_fd
                    << std::endl;

          // Tell epoll to monitor this new client soket for read events
          event.events = EPOLLIN;
          event.data.fd = new_client_fd;
          epoll_ctl(epoll_fd, EPOLL_CTL_ADD, new_client_fd, &event);
        }
      }
      // Case B; The event happened on a CLIENT socket (Data received)
      else {
        int client_fd = events[i].data.fd;
        char buffer[1024] = {0};
        int bytes_read = read(client_fd, buffer, sizeof(buffer));

        if (bytes_read <= 0) {
          // Client disconnected or error
          std::cout << "Client disconnected. FD: " << client_fd << std::endl;

          // When you close() a file descriptor, it is automatically
          // removed from the epoll set. No manual deletion neded!
          close(client_fd);
        } else {
          // 1. Convert buffer to string
          std::string raw_request(buffer, bytes_read);

          // 2. Parse the request
          HttpRequest parsed_req = parseRequest(raw_request);
          std::cout << "Handling " << parsed_req.method << " request for "
                    << parsed_req.uri << std::endl;

          // 3. Generate the response based on the file requested
          std::string http_response = handleRequest(parsed_req);

          // 4. Send the response back to the client
          write(client_fd, http_response.c_str(), http_response.length());

          // 5. Close the connection (HTTP/1.0 style behavior to keeps things simple for now)
          close(client_fd);
        }
      }
    }
  }
  close(server_fd);
  close(epoll_fd);
  return 0;
}
