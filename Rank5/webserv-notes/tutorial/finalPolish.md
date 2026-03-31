### The "42 Subject" Edge Case Checklist:

* **1. The `DELETE` Method:** Right now, your server only handles `GET` and `POST`. You need to add a quick block in `handleRequest` that checks for `DELETE`, uses the C++ `std::remove(filepath.c_str())` function to delete the target file, and returns a `204 No Content` or `200 OK` response.



* **2. Directory Listing (`autoindex`):** If a user requests a directory (like `/images/`) and there is no `index.html` file there, your config says `autoindex on;`. You need to use the `<dirent.h>` library to read the folder contents and dynamically generate an HTML page listing all the files as clickable links.



* **3. Non-Blocking `write()` (Write Chunking):** Remember this comment in your code? `// Note: If response is massive, you will need to chunk the write() call as well!`. If someone downloads a 1GB video from your server, you can't push 1GB into `write()` at once. You have to track outbound buffers in your `epoll` loop using `EPOLLOUT`, sending it in 8KB chunks just like you did for reading!



* **4. Zombie Connection Timeouts:** If a client connects via `nc` but literally never types anything, they will hold that socket open forever. You usually need to track the "last active time" for each client and periodically drop connections that have been idle for too long.



* **5. Server Names:** The config parser needs to handle `server_name` (e.g., `server_name example.com;`). This allows you to host two completely different websites on the *exact same port*. You route the request by looking at the `Host: example.com` header the browser sends!

---

## The Diagram

graph TD
    subgraph Configuration_Layer [Phase 4 & 5: Config & Virtual Hosts]
        CFG_File[Config File] --> Parser[Config Parser]
        Parser --> SrvObj[ServerConfig Objects]
        SrvObj --> VHost{Host Header Check}
        note1[Handles server_name & Port Multiplexing] --- VHost
    end

    subgraph Event_Loop [Phase 2 & Edge Case 4: The Heartbeat]
        Epoll[epoll_wait] --> TimeoutCheck[Timeout Monitor]
        TimeoutCheck -- Idle > 30s --> CloseConn[Close FD & Cleanup]
        TimeoutCheck -- Active --> NewConn{New Event?}
    end

    subgraph Request_Processing [Phase 3 & Edge Case 1 & 2]
        NewConn -- EPOLLIN --> Read[read into Buffer]
        Read --> RequestParser[HTTP Parser]
        
        RequestParser --> MethodSwitch{Method?}
        MethodSwitch -- GET --> PathCheck{File or Dir?}
        MethodSwitch -- POST --> CGIEngine
        MethodSwitch -- DELETE --> DeleteLogic[std::remove file]
        
        PathCheck -- Directory & autoindex --> DirListing[dirent.h HTML Gen]
        PathCheck -- File --> FileReader[Open File Stream]
    end

    subgraph Response_Management [Edge Case 3: Outbound Chunking]
        FileReader --> Buffering[Load Response into Outbound Buffer]
        DirListing --> Buffering
        CGIEngine --> Buffering
        DeleteLogic --> Buffering
        
        Buffering --> RegisterOut[Modify epoll: EPOLLOUT]
        RegisterOut --> Epoll
        
        NewConn -- EPOLLOUT --> ChunkWrite[write 8KB Chunk]
        ChunkWrite -- More Data? --> Epoll
        ChunkWrite -- Finished --> Done[Clear Buffer / Keep-Alive]
    end

    style Event_Loop fill:#fdd,stroke:#333,stroke-width:2px
    style Response_Management fill:#fff4dd,stroke:#d4a017,stroke-width:2px
