# The webserv-Roadmap

## Phase 1: The "Hello World" of Sockets
Your first goal is to get a browser to spin indefinitely, and then successfully send it a hardcoded string. Forget classes, config files, and multiple clients for now. 

* **What to learn:** Socket creation, configuration, binding, and listening.
* **Why to learn it:** Sockets act as the endpoint for communication between clients and your server. You need to understand how to convert your local port variables to Network Byte Order using `htons`. You also need to configure the socket with `SO_REUSEADDR` to prevent "Address already in use" errors during your inevitable crashes and restarts.
* **How to get there quickly:**
    * Write a single `main.cpp` file. 
    * Implement the standard system call flow: `socket()` -> `bind()` -> `listen()` -> `accept()`. 
    * When `accept()` returns a new file descriptor, use `write()` to send back a hardcoded HTTP response (e.g., `HTTP/1.1 200 OK\r\n\r\nHello Web!`). 
    * Test it by opening `localhost:<your_port>` in your browser.

## Phase 2: The Brain — High-Performance I/O Multiplexing
Right now, your server hangs on `accept()` or `read()`, serving only one person at a time. This is where most 42 students get stuck. We are going to bypass the older `poll()` methods and use Linux's modern event notification facility.

* **What to learn:** Asynchronous/Non-blocking I/O and polling mechanisms, specifically `epoll`.
* **Why to learn it:** A web server must handle multiple clients concurrently; if it blocks waiting for one client, it cannot serve anyone else. `epoll` is a highly efficient Linux-specific alternative that scales $O(1)$ by only returning the specific file descriptors that have active events, saving CPU cycles.
* **How to get there quickly:**
    * Create an `epoll` instance using `epoll_create()`.
    * Use `epoll_ctl()` with `EPOLL_CTL_ADD` to start monitoring your main listening socket for `EPOLLIN` (ready to read/accept) events.
    * Implement an infinite loop using `epoll_wait()` to pause the server until the OS hands you an array of active events.
    * Dynamically add new client sockets to your `epoll` instance as they are accepted.
    * *Test:* Open multiple terminal tabs and use `telnet` or `nc` to connect to your server simultaneously. Your server should be able to accept all connections without freezing.

## Phase 3: Speaking HTTP/1.1
Now that your server can effortlessly juggle multiple connections using `epoll`, it needs to actually understand what the clients are asking for.

* **What to learn:** HTTP/1.1 message structure and parsing.
* **Why to learn it:** You need to distinguish between different request methods like `GET`, `POST`, and `DELETE`. You also need to separate the headers from the body payload.
* **How to get there quickly:**
    * Inside your `epoll_wait()` loop, when a client socket has a read event, process the incoming data.
    * Write a parser that reads until it hits the CRLF (`\r\n\r\n`) sequence, which denotes the end of the headers.
    * Extract the Request URI and HTTP Version from the start line.
    * Create a routing mechanism to fetch the requested local file (e.g., `index.html`) and format the response line with the correct Status Code and Status Message.

## Phase 4: The Map — Nginx Configuration
Your server is working efficiently, but it's hardcoded. It's time to make it dynamic using an Nginx-style config file.

* **What to learn:** File parsing and mapping configuration blocks to C++ objects.
* **Why to learn it:** The server must be configurable via a text file utilizing Nginx-style syntax. This allows you to define virtual servers (`server {}`), set listening ports (`listen`), map specific routes (`location`), and define custom error pages (`error_page`).
* **How to get there quickly:**
    * Build a parser that tokenizes the config file.
    * Create a `ServerConfig` class that stores vectors of `Location` structs.
    * Link your Phase 2 `epoll` logic to this config parser so that your server dynamically calls `socket()`, `bind()`, and `listen()` for every port defined by a `listen` directive, and adds all of those listening sockets to your single `epoll` instance.

## Phase 5: The Beast — CGI & Chunking
This is the final polish to make your server robust against large data and capable of dynamic content.

* **What to learn:** Common Gateway Interface (CGI) and HTTP chunking.
* **Why to learn it:** Chunking prevents freezes by processing large payloads in `BUFFER_SIZE` increments. CGI allows your server to execute external programs to generate dynamic content instead of just serving static HTML.
* **How to get there quickly:**
    * For chunking, implement a loop that continuously calls `read(socket, buffer, BUFFER_SIZE)` until the data is fully received.
    * For CGI, use standard Unix system calls (`fork`, `execve`, `pipe`). Route specific file extensions (like `.py` or `.php`) to execute the script and send the script's standard output back to the client socket.

---

## The Diagram

graph TD
    subgraph Configuration_Layer [Phase 4: Configuration]
        CFG_File[Nginx-style Config File] --> Parser[Config Parser]
        Parser --> SrvObj[ServerConfig Objects]
    end

    subgraph Network_Layer [Phase 1 & 2: I/O Multiplexing]
        SrvObj --> Init[Socket/Bind/Listen]
        Init --> Epoll[epoll_create & epoll_wait]
        Epoll --> NewConn{New Connection?}
        NewConn -- Yes --> Accept[accept & add to epoll]
        NewConn -- No --> HandleEvent[Process Client Socket]
    end

    subgraph Logic_Layer [Phase 3 & 5: Protocol & Execution]
        HandleEvent --> Read[read in BUFFER_SIZE chunks]
        Read --> RequestParser[HTTP Request Parser]
        RequestParser --> Router{Route Found?}
        
        Router -- Static File --> FileReader[Read File System]
        Router -- CGI (.py/.php) --> CGIEngine[fork / pipe / execve]
        Router -- No --> ErrorPages[404 / 500 Custom Pages]
        
        FileReader --> ResponseGen[Build HTTP Response]
        CGIEngine --> ResponseGen
        ErrorPages --> ResponseGen
        
        ResponseGen --> Write[send/write to Socket]
        Write --> Epoll
    end

    style Configuration_Layer fill:#f9f,stroke:#333,stroke-width:2px
    style Network_Layer fill:#bbf,stroke:#333,stroke-width:2px
    style Logic_Layer fill:#bfb,stroke:#333,stroke-width:2px
