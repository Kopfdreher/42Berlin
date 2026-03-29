#ifndef DEFINES_HPP
#define DEFINES_HPP

#include <map>
#include <string>
#include <vector>

// Represents a "location <URI> {}" block
struct LocationConfig {
  std::string uri;                          // e.g., "/", "/images"
  std::vector<std::string> allowed_methods; // e.g., "GET", "POST"
  std::string root;                         // Root directory for files
  std::string index;                        // Default file to serve
  bool autoindex;         // Directory listing if no index file is found
  std::string return_uri; // HTTP redirection

  LocationConfig() : autoindex(false) {} // C++98 constructor for defaults
};

// Represents a "server {}" block
struct ServerConfig {
  int listen_port;             // Port number to listen on
  std::string root;            // Global root
  std::string index;           // Global index
  size_t client_max_body_size; // Limits the size of incoming client requests
  std::map<int, std::string> error_pages; // Custom error pages mapped by code
  std::vector<LocationConfig> locations;  // The nested location blocks

  ServerConfig()
      : listen_port(80), root("."), index("index.html"),
        client_max_body_size(1048576) {} // Defaults
};

std::vector<std::string> tokenizeConfig(const std::string &filename);
std::vector<ServerConfig> parseConfigFile(const std::string &filename);

#endif
