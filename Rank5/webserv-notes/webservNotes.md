# Webserv: Building a C++98 Webserver

## I. Introduction to Webserv
The goal of this project is to build a custom HTTP/1.1 web server in C++98. 42 requires this older standard to deepen our understanding of how C++ is implemented under the hood and to appreciate the historical context of network programming.

## II. Core Concepts: Web Servers & HTTP

### What is a Webserver?
* A computer/program that receives requests from other computers (clients).
* It processes these requests and sends back an appropriate response.

### What is HTTP?

* Short for **Hypertext Transfer Protocol**.
* A protocol is a set of rules governing communication between two entities. HTTP enables servers and clients to communicate.
* **Structure:** Messages consist of a start line, headers, an empty line (`\r\n`), and an optional body.
    * **Header:** Contains metadata and context information.
    * **Body:** Contains the actual content (payload).
    * **CRLF:** The start and end strings are denoted by carriage return and line feed (`\r\n\r\n`).

#### Requests vs. Responses
* **Request:**
    * Starts with a request-line (e.g., `GET /index.html HTTP/1.1`).
    * Contains: Request Method, Request URI, and HTTP Version.
    * **Methods:**
        * `GET`: Client requests information from the server.
        * `POST`: Client sends information to the server.
        * `DELETE`: Client requests the deletion of a specified resource.
* **Response:**
    * Starts with a response-line (e.g., `HTTP/1.1 200 OK`).
    * Contains: HTTP Version, Status Code, and Status Message.

## III. Network Programming & Sockets
Client/server connections are facilitated by sockets. A socket is an endpoint for communication, represented as a file descriptor in Unix-like systems.



### 1. Creating a Socket
```cpp
int socket(int domain, int type, int protocol);
```
* `domain`: Communication domain (e.g., `AF_INET` for IPv4).
* `type`: Socket type (e.g., `SOCK_STREAM`).
* `protocol`: Usually `0` to let the OS choose the default protocol for the given type.

**Two Main Socket Types:**
1.  **Stream Sockets (`SOCK_STREAM`):** Two-way communication streams using **TCP**. Slow but prioritizes data integrity and order. Used by HTTP.
2.  **Datagram Sockets (`SOCK_DGRAM`):** Connectionless sockets using **UDP**. Prioritizes speed over data integrity (data may or may not arrive). Used by games, live video, and audio.

### 2. Configuring Sockets
A web server needs to reuse ports that were previously used to avoid "Address already in use" errors if the server crashes or restarts quickly.
```cpp
const int enable = 1;
if (setsockopt(this->sock, SOL_SOCKET, SO_REUSEADDR, &enable, sizeof(int)) < 0)
    std::cerr << "setsockopt(SO_REUSEADDR) failed" << endl;
```

### 3. Binding Sockets
Once created, a socket must be bound to a specific IP address and port on the machine.

```cpp
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

**The `sockaddr_in` struct** (used for IPv4):
```cpp
struct sockaddr_in {
    short int          sin_family;  // Address family, AF_INET
    unsigned short int sin_port;    // Port number
    struct in_addr     sin_addr;    // Internet address
    unsigned char      sin_zero[8]; // Padding to match struct sockaddr
};
```

**Endianness (Network Byte Order):**
Different computers store bytes in different orders (Little-Endian vs. Big-Endian). Networks standardize on Big-Endian (Network Byte Order). We must convert our local variables using `htons` (host to network short) and `htonl` (host to network long).

```cpp
address.sin_family = AF_INET;
address.sin_port = htons(port_numbers);
address.sin_addr.s_addr = htonl(INADDR_ANY); // Interface
```

### 4. Listening and Accepting
* `listen()`: Marks the socket as a passive socket that will be used to accept incoming connection requests. The `backlog` parameter defines the queue size for pending connections.
    ```cpp
    int listen(int sockfd, int backlog);
    ```

* `accept()`: Extracts the first connection request on the queue of pending connections, creates a *new* connected socket, and returns a new file descriptor referring to that socket.
    ```cpp
    int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
    ```

**Standard System Call Flow:**
`socket()` -> `bind()` -> `listen()` -> `accept()` -> `read()`/`recv()` -> `write()`/`send()`

## IV. Handling Multiple Clients (I/O Multiplexing)
A web server must handle multiple clients concurrently. If a server waits (`blocks`) for a client to send data, it cannot serve anyone else. We solve this using **Asynchronous/Non-blocking I/O**.



### Polling Mechanisms
To prevent blocking, we use polling. Polling allows us to monitor an array of socket descriptors and asks the OS: "Which of these are ready to be read from or written to?"

#### 1. The `poll()` System Call
`poll` monitors an array of `pollfd` structures.
```cpp
int poll(struct pollfd fds[], nfds_t nfds, int timeout);

struct pollfd {
    int   fd;      // The socket descriptor
    short events;  // Bitmap of events we are interested in (e.g., POLLIN, POLLOUT)
    short revents; // Bitmap of events that actually occurred (filled by OS)
};
```

#### 2. The `select()` System Call
`select` is older and highly portable, but generally limited to monitoring 1024 file descriptors.
1.  **Initialize `fd_set`**: Create separate bitmasks for read/write events.
2.  **Populate**: Add file descriptors of interest using `FD_SET`.
3.  **Timeout**: Set a max duration to wait.
4.  **Call `select`**: Blocks until an event occurs or it times out.
5.  **Check `fd_set`**: Use `FD_ISSET` to see which FDs are ready.
6.  **Handle Events & Loop**: Read/write data, then loop back to monitor again.

*(Note: `epoll` is a highly efficient Linux-specific alternative, though often restricted depending on the specific 42 subject rules).*

## V. Advanced Request Handling

### Chunking
To prevent freezes caused by massive payloads, we define a `BUFFER_SIZE` and read data in chunks.
```cpp
read(socket, buffer, BUFFER_SIZE);
```

Used for: Large responses to `GET` requests, or `POST` requests with large bodies.

### CGI (Common Gateway Interface)
An interface specification that allows the web server to execute external programs (like Python or PHP scripts) to generate dynamic content, rather than just serving static HTML files.

## VI. Server Configuration (Nginx Style)
The server should be configurable via a text file utilizing Nginx-style syntax.

* **`server {}`**: Defines a virtual server.
* **`location <URI> {}`**: Defines rules for specific routes.
* **`listen <port>`**: Port number to listen on (e.g., `listen 80;`).
* **`root <path>`**: Root directory for files (e.g., `root html;`).
* **`index <files>`**: Default file to serve (e.g., `index index.html;`).
* **`error_page <code> <file>`**: Custom error pages (e.g., `error_page 404 /404.html;`).
* **`autoindex on|off`**: Directory listing if no index file is found.
* **`allowed_methods <methods>`**: e.g., `allowed_methods GET POST;`.
* **`return <URI>`**: HTTP redirection.
* **`client_max_body_size <size>`**: Limits the size of incoming client requests (e.g., `1MB`).

---

# Sources
[Webserv: A C++ Webserver by Iaian](https://hackmd.io/@laian/SJZHcOsmT)
[RFC: Hypertext Transfer Protocol -- HTTP/1.1](https://datatracker.ietf.org/doc/html/rfc2616#section-9.4)
[socket(2) - Linux man page](https://linux.die.net/man/2/socket)
[M4nnb3ll on Webserv](https://m4nnb3ll.medium.com/webserv-building-a-non-blocking-web-server-in-c-98-a-42-project-04c7365e4ec7

