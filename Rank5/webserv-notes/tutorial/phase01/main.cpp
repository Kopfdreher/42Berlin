#include <cstring> // For memset()
#include <iostream>
#include <netinet/in.h> // For sockaddr_in, htons(), htonl()
#include <sys/socket.h> // For socket(), bind(), listen(), accept()
#include <unistd.h>     // For close(), write()

#define PORT 8080
#define ERROR -1

int main() {
  // 1. Creating a Socket
  // AF_INET is for IPv4, SOCK_STREAM is for TCP (two-way communication used by
  // HTTP), and 0 lets the OS choose the default protocol.
  int server_fd = socket(AF_INET, SOCK_STREAM, 0);
  if (server_fd == ERROR) {
    std::cerr << "Socket creation failed" << std::endl;
    return 1;
  }

  // 2. Configuring Socket
  // We use SO_REUSEADDR to avoid "Address already in use" errors if we restart
  // the server quickly.
  int enable = 1;
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) <
      0) {
    std::cerr << "setsockopt(SO_REUSEDADDR) failed" << std::endl;
    return 1;
  }

  // 3. Binding Sockets
  // Setting up the sockaddr_in struct.
  struct sockaddr_in address;
  std::memset(&address, 0,
              sizeof(address)); // C++98 compliant way to zero out the struct

  address.sin_family = AF_INET;
  // We must use htons() and htonl() to convert our local variables to
  // Big-Endian Network Byte Order.
  address.sin_port = htons(PORT);
  address.sin_addr.s_addr = htonl(INADDR_ANY);

  // Bind the socket to the specific IP and port.
  if (bind(server_fd, (struct sockaddr *)&address, sizeof(address)) < 0) {
    std::cerr << "Bind failed" << std::endl;
    return 1;
  }

  // 4. Listening and Accepting
  // Mark the socket as passive to accept incoming requests, with a backlog
  // queue of 10.
  if (listen(server_fd, 10) < 0) {
    std::cerr << "Listen failed" << std::endl;
    return 1;
  }

  std::cout << "Server is listening on port " << PORT << "..." << std::endl;

  // accept() extracts the first connection request and returns a new connected
  // socket descriptor.
  struct sockaddr_in client_address;
  socklen_t client_addrlen = sizeof(client_address);

  // Note: The server will BLOCK (wait indefinitely) here until a client
  // connects.
  int new_socket =
      accept(server_fd, (struct sockaddr *)&client_address, &client_addrlen);
  if (new_socket < 0) {
    std::cerr << "Accept failed" << std::endl;
    return 1;
  }

  std::cout << "Connection accepted!" << std::endl;

  // 5. Sending the HTTP Response
  // Responses must start with a response-line and end the headers with
  // \r\n\r\n.
  std::string http_response =
      "HTTP/1.1 200 OK\r\nContent-Type : text/plain\r\nContent-Length: "
      "14\r\n\r\nHello Webserv!";

  write(new_socket, http_response.c_str(), http_response.length());

  // Clean up
  close(new_socket);
  close(server_fd);
}


class Server {
  port;
  server_name;
  path;
  std::map locations = {};

  locations(key: /, value: {inside})
  locations(key: /something, 

  somethingnew.hmtl

  config location /somethingnew
};
