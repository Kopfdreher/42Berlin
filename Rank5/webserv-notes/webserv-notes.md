### Introduction Webserv
42 probably added this webserv in C++98 to deepen the understanding of how C++ is implemented and where it's coming from history-wise.

#### A non-blocking server
Blocking refers to one thread being blocked due to waiting for an operation to be completed, leading to performance bottlenecks, especially whit multiple concurrent connections.

Most issue occur when dealing with input/output (I/O) operation, like reading from / writing to sockets.

To address this, we'll use asynchronous I/O, allowing the server to continue with other tasks, while waiting. (using system calls like `select`, `poll`, `epoll`)

#### select system call
`poll` and `epoll` are simpler alternatives to `select`, while `select` is more portable. Here's an overview of how `select` works:

1. Initialization of fd_set
    - we init separate fd_set structures for each type of event (read / write)
    - they serve as bit masks, representing sets of file descriptors
2. Populating the fd_set
    - fds of interest are added to the fd_set using macros like `FD_SET`
3. Setting the Timeout
    - set a timeout value for maximum duration `select` should wait for an event
4. Calling `select`
    - ...
5. Blocking or Returning
    - `select` enters blocking state, awaiting events on monitored file descriptors or till timeout
    - returns control to the program
6. Checking the fd_set
    - the program examines the fd_sets to identify which file descriptors are ready for the specified events, by using macros like `FD_ISSET`
7. Handling Events
    - respond to events by executing the required actions
8. Looping or Exiting
    - often using loops to repeat the monitoring, allowing continuous asunchronous handling of events on multiple file descriptors

`poll` and `epoll` are recommended due to it's monitor limit of 1024 file descriptors

#### Implementing HTTP/1.1
HTTP messages consist of a request or response line, headers an empty line(CRLF or \r\n), and an optional message body


### Foundational Knowledge

#### What is a Webserver?
- A webserver is basically a computer (server) that recieves data from other computers. (clients)
- Recieves request from clients, processes them and sends an appropriate response

#### What is HTTP?

##### HTTP - TL:DR
- short for **Hypertext Transfer Protocol**
- A Protocol refers to a set of rules governing communication between two entities
- HTTP enables servers and clients to communicate

##### Requests <> Response
- two main parts of request / response, containing **header & body**
    - header: contains context information
    - body: contains content
    - start- & end-string: \r\n\r\n
- **Request**
    - starts with request-line: GET /index.html HTTP/1.1
    - request-line contains: request method, request URI and HTTP version
    - request-line might be followed by header fields, describing the context
    - some requests might contain content in the body
- **Request-Methods**
    - GET: client request information from the server
    - POST: client sends information to the server
    - DELETE: client request deletion of specified resource
- **Response**
    - starts with response-line: HTTP/1.1 200 OK
    - response-line contains: HTTP version, status code and status message
    - response-line might be followed by more header fields and body

#### Workings of a Webserver

##### Sockets & Network Functions
Client/server connections are facilitated by sockets, a socket is a file descriptor using:

```c++
int socket(int domain, int type, int protocol);
```

- int domain: specifies communication domains (e.g. AD_INET)
- int type: socket-type (e.g. SOCK_STREAM)
- int protocol: socket-protocol (usually 0)

###### Two main socket types
1. Stream Sockets: SOCK_STREAM
    - two-way communication streams, using **Transmission Control Protocol (TCP)**
    - usually used by HTTP, slow, data quality over speed
2. Datagram Sockets: SOCK_DGRAM
    - connectionless sockets, using **User Datagram Protocol (UDP)**
    - data may or may not arrive
    - connectionless cause it doesn't require an open connection
    - speed is the priority, commonly used by games, video, audio

###### Binding Sockets
When a socket descriptor was created, we need to bind it to a computer port, with:

```c++
int bind(int sockfd, const struct sockaddr *addr, socklen_t addrlen);
```

- a sockaddr is required in the parameters, this is a simpler version of it:

```c++
struct sockaddr_in {
    short int           sin_family; // Address family, AF_INET
    unsigned short int  sin_port;   // Port number
    struct in_addr      sin_addr;   // Internet address
    unsigned char       sin_zero[8]; // Same size as struct sockaddr
}
```

The struct contains socket address information

```c++
address.sin_family = domain; // domain
address.sin_port = htons(port_numbers); // port number
address.sin_addr.s_addr = htonl(interface); // ip address
```

###### Big- / Little-Endian

**htons & htonl**
```c++
uint16_t htons(uint16_t hostshort);
uint32_t htonl(uint32_t hostlong);
```

- htons: host to network short
- htonl: host to network long

- Some computers store bytes in revers order (little-endian)
- storing bytes in correct order is called big-endian
- we pass values through htons and htonl so that it changes the value from Host Byte Order to Network Byte Order

###### Configuring Sockets
Using setsockipt for socket-config:

```c++
int setsockopt(int sockfd, int level, int optname, const void *optval, socklen_t optlen);
```

A webserver wants to reuse porst that were previusly used:

```c++
const int enable = 1;
if (setsockopt(this->sock, SOL_SOCKET, SO_REUSEDDR, &enable, sizeof(int)) < 0)
    std::cerr << "setsockopt(SO_REUSEADDR) failed" << endl;
```

Socket can be used to connect to a remote host with `connect`, in this case we want to listen to incoming connections with `listen`:

```c++
int listen(int sockfd, int backlog);
```

- backlog refers to the amount of cennections that can be put on hold
- this way other computers can use `connect` to connect to our `listen`ing machine

Incoming connections will be queued, and can be accepted with accept:

```c++
int accept(int sockfd, struct sockaddr *addr, socklen_t *addrlen);
```

We can read from socket using `read`/`recv`, and write using `send`/`write`, flow of system calls:

```c++
socket();
bind();
listen();
accept();
read() || recv() && send() || write() // accordingly
```

#### Multiple Clients
- A webserver needs to handle multiple clients
- we can achieve that by having an array of socket descriptors

1. poll the whole array
2. check and handle new connections
3. handle current connections,  POLLIN (read data), POLLOUT (write data)

##### Polling
- what happens if we try to read from a socket with no data? It just sits there waiting for data to read -> this is called blocking
- how can we know what sockets are able to be read / written to?
    - we use polling: it tells us what sockets have the data ready

```c++
int poll(struct pollfd fds[], nfds_t nfds, int timeout);
```

Pollfd structs are required for this:

```c++
struct pollfd {
    int     fd;         // the socket descriptor
    short   events;     // bitmap of events we're interested in
    short   revents;    // when poll() returns, bitmap of events that occurred
};
```

We set events to define what event we care about

```c++
pollfd1.events = POLLIN;    // tell me when data is ready to recieve
pollfd2.events = POLLOUT;   // tell me when I can send data without blocking
```

After that, poll returns the revents values.

##### Chunking
- to prevent freezes caused by large data amounts, we use chunking
- we use defined BUFFER_SIZES to only read a specific length of buffer size

```c++
read(socket, buffer, BUFFER_SIZE);
```

Chunking can be use for:
- large responses to GET requests
- post request with large body

##### CGI
**CGI (Common Gateway Interface)** is an interface specification for webservers to be able to execute external programs.


### Documentation

#### Server Configuration
The config is based on nginx's server config format, two types are supported: server & location blocks.

Server block definition:
```c++
server {
    ...
}
```

Location block definition:
```c++
location <URI> {
    ...
}
```

There are directives within the blocks

`listen`: Defines the the port number to listen to
```c++
port <port_number>;
port 80;
```

`root`: Sets the root directory for requests
```c++
root <path>;
root html;
```

`index`: Defines files that will be used as an index
```c++
index <file 1> <file 2> <file 3> ...;
index index.html;
```

`error_page`: To define potential error pages
```c++
error_page <error_code> <rror_page>;
error_page 404 404.html;
```

`autoindex`: Automatically generates a directory listing if an index page isn't specified
```c++
autoindex on | off;
```

`allowed_methods`: Defines the allowed request methods for a specific location. Supports `POST`, `GET`, `DELETE`
```c++
allowed_methods <method 1> <method 2>;
allowed_methods POST GET DELETE;
```

`return`: Defines a specified URI / page to return to the client.
```c++
return <URI>;
return https://google.com;
```

`client_max_body_size`: Defines the max size of a client request body.
```c++
client_max_body_size <size>; # B, MB, KB, GB
client_max_body_size 1MB;
```

# Sources
[Webserv: A C++ Webserver by Iaian](https://hackmd.io/@laian/SJZHcOsmT)
[RFC: Hypertext Transfer Protocol -- HTTP/1.1](https://datatracker.ietf.org/doc/html/rfc2616#section-9.4)
[socket(2) - Linux man page](https://linux.die.net/man/2/socket)
[](https://m4nnb3ll.medium.com/webserv-building-a-non-blocking-web-server-in-c-98-a-42-project-04c7365e4ec7


# Questions
- what is the RFC (Request For Comments)?
- what is the request URI?
- the interface is a special value loaded into the struct's ip address to make it auto-fill the address with the current host, what does that mean?
- what does poll mean? and what does it mean to poll the whole array of socket descriptors?
- what is the difference between events and revents?
- what does this mean: Calling select:
The program invokes the select function, providing the "highest file descriptor value" + 1 (man select), the three fd_sets, and the timeout; We can set NULL as value for events that we are not interested in, or for timeout if we wish select to block indefinitely until an event occurs.
- 
