#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>
#include <poll.h> // For poll() and struct pollfd
#include <vector> // C++98 standard container

#define PORT 8080

int main() {
  // PHASE 1 RECAP: Setup, Bind, Listen
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

  // PHASE 2: The Polling Loop

  // Create a vector to hold our pollfd structures.
  std::vector<struct pollfd> fds;

  // The first socket we monitor is our server/listening socket.
  struct pollfd server_pollfd;
  server_pollfd.fd = server_fd; // The socket descriptor
  server_pollfd.events = POLLIN; // Bitmap of events we are interested in (ready to read/accept)
  server_pollfd.revents = 0; // Bitmap filled by OS
  
  fds.push_back(server_pollfd);

  while (true) {
    // poll() blocks here until at least one file descriptor has an event, or it times out.
    // The first parameter is the underlying array of our vector, second is the size, third is timeout (-1 means wait indefinitely).
    int poll_count = poll(&fds[0], fds.size(), -1);

    if (poll_count < 0) {
      std::cerr << "Poll failed" << std::endl;
      break;
    }

    // Loop through all file descriptors to see which ones have events
    for (size_t i = 0; i < fds.size(); ++i) {

      // Check the revents bitmap to see if the event actually occurred
      if (fds[i].revents & POLLIN) {

        // Case A: The event happened on the SERVER socket (A new client is connecting)
        if (fds[i].fd == server_fd) {
          struct sockaddr_in client_address;
          socklen_t client_addrlen = sizeof(client_address);

          int new_client_fd = accept(server_fd, (struct sockaddr *)&client_address, &client_addrlen);
          if (new_client_fd >= 0) {
            std::cout << "New connection accepted! FD: " << new_client_fd << std::endl;

            // Add the new client socket to our polling array
            struct pollfd client_pollfd;
            client_pollfd.fd = new_client_fd;
            client_pollfd.events = POLLIN;
            client_pollfd.revents = 0;
            fds.push_back(client_pollfd);
          }
        }
        // Case B: The event happened on a CLIENT socket (An existing client sent us data)
        else {
          char buffer[1024] = {0};
          int bytes_read = read(fds[i].fd, buffer, sizeof(buffer));

          if (bytes_read <= 0) {
            // Client disconnected or error
            std::cout << "Client disconnected. FD: " << fds[i].fd << std::endl;
            close(fds[i].fd);
            fds.erase(fds.begin() + i);
            --i; // Adjust index after erasure
          } else {
            // We received data! For now, just print it and send back our greeting.
            std::cout << "Received data from FD " << fds[i].fd << ":\n" << buffer << std::endl;

            std::string http_response = "HTTP/1.1 200 OK\r\nContent-Type: text/plain\r\nContent-Length: 17\r\n\r\nHello Multiplexing!";
            write(fds[i].fd, http_response.c_str(), http_response.length());

            // HTTP/1.1 usually keeps connections alive, but to keep this simple, we'll close it after replying.
            close(fds[i].fd);
            fds.erase(fds.begin() + i);
            --i;
          }
        }
      }
    }
  }
  close(server_fd);
}
