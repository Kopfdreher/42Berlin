#include "PmergeMe.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc > 3200) {
    std::cerr << "Error: too many numbers"<< std::endl;
    return 1;
  }
  if (argc != 2) {
    std::cerr << "Please declare an input: ./PmergeMe num num ..."<< std::endl;
    return 1;
  }

  try {
    PmergeMe calc;
    calc.processInput(argc, argv);
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
