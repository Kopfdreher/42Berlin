#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Please declare an input: ./RPN \"num num expr\"" << std::endl;
    return 1;
  }

  try {
    RPN rpn;
    rpn.processInput(argv[1]);
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }
}
