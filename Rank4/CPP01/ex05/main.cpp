#include "Harl.hpp"
#include <iostream>

int main(int argc, char **argv) {

  if (argc != 2)
  {
    std::cerr << "Invalid Arg-Count!" << std::endl;
    return (1);
  }

  Harl harl;
  harl.complain(argv[1]);
}
