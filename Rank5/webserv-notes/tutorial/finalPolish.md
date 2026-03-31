### The "42 Subject" Edge Case Checklist:



* **1. The `DELETE` Method:** Right now, your server only handles `GET` and `POST`. You need to add a quick block in `handleRequest` that checks for `DELETE`, uses the C++ `std::remove(filepath.c_str())` function to delete the target file, and returns a `204 No Content` or `200 OK` response.



* **2. Directory Listing (`autoindex`):** If a user requests a directory (like `/images/`) and there is no `index.html` file there, your config says `autoindex on;`. You need to use the `<dirent.h>` library to read the folder contents and dynamically generate an HTML page listing all the files as clickable links.



* **3. Non-Blocking `write()` (Write Chunking):** Remember this comment in your code? `// Note: If response is massive, you will need to chunk the write() call as well!`. If someone downloads a 1GB video from your server, you can't push 1GB into `write()` at once. You have to track outbound buffers in your `epoll` loop using `EPOLLOUT`, sending it in 8KB chunks just like you did for reading!



* **4. Zombie Connection Timeouts:** If a client connects via `nc` but literally never types anything, they will hold that socket open forever. You usually need to track the "last active time" for each client and periodically drop connections that have been idle for too long.



* **5. Server Names:** The config parser needs to handle `server_name` (e.g., `server_name example.com;`). This allows you to host two completely different websites on the *exact same port*. You route the request by looking at the `Host: example.com` header the browser sends!



**The Verdict:**

You are 90% of the way there. The hardest architectural hurdles are completely behind you. Everything left on this list is just adding standard C++ logic to the beautiful framework you've already built.
