#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

// A simple struct to hold our parsed data
struct HttpRequest {
  std::string method;
  std::string uri;
  std::string version;
};

// 1. Parsing the Request
HttpRequest parseRequest(const std::string &raw_request) {
  HttpRequest req;

  // Find the end of the first line (the request-line)
  size_t line_end = raw_request.find("\r\n");
  if (line_end == std::string::npos)
    return req;

  std::string request_line = raw_request.substr(0, line_end);

  // Extract Method, URI, and Version using string streams
  std::istringstream iss(request_line);
  iss >> req.method >> req.uri >> req.version;

  return req;
}

// 2. Generating the Response
std::string handleRequest(const HttpRequest &req) {
  // We only support GET for now
  if (req.method != "GET") {
    return "HTTP/1.1 405 Method Not Allowed\r\nContent-Length: 0\r\n\r\n";
  }

  // Default to index.html if the root is requested
  std::string filepath = (req.uri == "/") ? "index.html" : req.uri.substr(1);

  // Try to open the requested file
  std::ifstream file(filepath.c_str(), std::ios::in | std::ios::binary);

  if (!file.is_open()) {
    // If file doesn't exist, send a 404 response-line
    std::string body = "<html><body><h1>404 Not Found</h1></body></html>";
    std::ostringstream response;
    response << "HTTP/1.1 404 Not Found\r\n"
             << "Content-Type: text/html\r\n"
             << "Content-Length: " << body.length() << "\r\n"
             << "\r\n" // The empty line separating headers and body
             << body;
    return response.str();
  }

  // Read the file content
  std::ostringstream file_content;
  file_content << file.rdbuf();
  std::string body = file_content.str();

  // Craft the successful 200 OK response
  std::ostringstream response;
  response << "HTTP/1.1 200 OK\r\n"
           << "Content-Type: text/html\r\n"
           << "Content-Length: " << body.length() << "\r\n"
           << "\r\n" // CRLF to end headers
           << body;
  return response.str();
}
