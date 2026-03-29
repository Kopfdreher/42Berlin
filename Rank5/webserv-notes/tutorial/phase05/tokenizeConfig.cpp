#include "defines.hpp"
#include <cctype> // For isspace()
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

std::vector<std::string> tokenizeConfig(const std::string &filename) {
  std::vector<std::string> tokens;
  // .c_str() is required in C++98 to open a file with a std::string
  std::ifstream file(filename.c_str());

  if (!file.is_open()) {
    std::cerr << "Error: Could not open config file." << std::endl;
    return tokens;
  }

  char c;
  std::string current_token = "";

  // Read the file one single character at a time
  while (file.get(c)) {
    // Handle comments (ignore everything until the end of the line)
    if (c == '#') {
      std::string ignore_line;
      std::getline(file, ignore_line);
      continue;
    }

    // 1. If we hit whitespace (space, tab, newline)
    if (std::isspace(c)) {
      // If we were building a word, save it and clear the buffer
      if (!current_token.empty()) {
        tokens.push_back(current_token);
        current_token.clear();
      }
    }
    // 2. If we hit a control character, it is its own token!
    else if (c == '{' || c == '}' || c == ';') {
      // Save whatever word we were building first (e.g., the "8080" in "8080;")
      if (!current_token.empty()) {
        tokens.push_back(current_token);
        current_token.clear();
      }
      // Save the control character as a single-character string
      tokens.push_back(std::string(1, c));
    }
    // 3. Otherwise, it's a normal character, keep building the current word
    else {
      current_token += c;
    }
  }

  // Catch any leftover token at the very end of the file
  if (!current_token.empty()) {
    tokens.push_back(current_token);
  }

  return tokens;
}
