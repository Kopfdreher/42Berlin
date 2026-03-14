#include "ScalarConverter.hpp"
#include <iostream>

int main(int argc, char **argv) {
  try {
    if (argc == 2)
      ScalarConverter::convert(argv[1]);
    else
      std::cerr << "Error: Invalid-Arg-Count" << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
