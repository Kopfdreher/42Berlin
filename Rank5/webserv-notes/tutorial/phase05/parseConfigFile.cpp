#include "defines.hpp"
#include <cstdlib> // For std::atoi
#include <stdexcept> // For throwing parsing errors
#include <string>
#include <vector>

// (Assume ServerConfig, LocationConfig, and tokenizeConfig are defined here as
// shown previously)

std::vector<ServerConfig> parseConfigFile(const std::string &filename) {
  // 1. Get our clean array of words and symbols
  std::vector<std::string> tokens = tokenizeConfig(filename);
  std::vector<ServerConfig> servers;

  // 2. Iterate through the tokens
  for (size_t i = 0; i < tokens.size(); ++i) {

    // We found a virtual server block!
    if (tokens[i] == "server") {
      // Look ahead: the very next token MUST be a '{'
      if (++i >= tokens.size() || tokens[i] != "{") {
        throw std::runtime_error("Parse error: Expected '{' after 'server'");
      }

      ServerConfig current_server;

      // 3. Enter the Server Block Loop
      // Keep parsing until we hit the closing '}' of the server block
      while (++i < tokens.size() && tokens[i] != "}") {

        // Parse 'listen' directive
        if (tokens[i] == "listen") {
          if (++i >= tokens.size())
            throw std::runtime_error("Parse error: Missing port");
          current_server.listen_port =
              std::atoi(tokens[i].c_str()); // Convert string to int

          if (++i >= tokens.size() || tokens[i] != ";") {
            throw std::runtime_error(
                "Parse error: Expected ';' after listen port");
          }
        }
        // Parse global 'root' directive
        else if (tokens[i] == "root") {
          if (++i >= tokens.size())
            throw std::runtime_error("Parse error: Missing root path");
          current_server.root = tokens[i];

          if (++i >= tokens.size() || tokens[i] != ";")
            throw std::runtime_error("Parse error: ';' after root path");
        }
        // Parse 'location' block
        else if (tokens[i] == "location") {
          if (++i >= tokens.size())
            throw std::runtime_error("Parse error: Missing location URI");

          LocationConfig current_location;
          current_location.uri = tokens[i]; // Store the URI

          if (++i >= tokens.size() || tokens[i] != "{")
            throw std::runtime_error(
                "Parse error: Expected '{' after location URI");

          // 4. Enter the Location Block Loop (Nested)
          while (++i < tokens.size() && tokens[i] != "}") {
            if (tokens[i] == "root") {
              if (++i >= tokens.size())
                throw std::runtime_error("Parse error: Missing location root");
              current_location.root = tokens[i];
              if (++i >= tokens.size() || tokens[i] != ";")
                throw std::runtime_error("Parse error: Expected ';'");
            } else if (tokens[i] == "autoindex") {
              if (++i >= tokens.size())
                throw std::runtime_error(
                    "Parse error: Missing autoindex value");
              current_location.autoindex = (tokens[i] == "on");
              if (++i >= tokens.size() || tokens[i] != ";")
                throw std::runtime_error("Parse error: Expected ';'");
            }
            // Note: You would add allowed_methods and others here
            else {
              // Skip unkown location directives safely until the next semicolon
              while (i < tokens.size() && tokens[i] != ";" &&
                     tokens[i] != "}") {
                ++i;
              }
            }
          }

          // Add this fully populated location block to our server!
          current_server.locations.push_back(current_location);
        } else {
          // Skip unknown server directives safely until the next semicolon
          while (i < tokens.size() && tokens[i] != ";" && tokens[i] != "}") {
            ++i;
          }
        }
      }

      // The server block is fully parsed, add it to our master list
      servers.push_back(current_server);
    }
  }

  return servers;
}
