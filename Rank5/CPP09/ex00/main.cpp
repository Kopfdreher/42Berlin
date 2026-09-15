#include "BitcoinExchange.hpp"
#include <iostream>

int main(int argc, char *argv[]) {
  if (argc != 2) {
    std::cerr << "Please declare an input: ./btc <file>" << std::endl;
    return 1;
  }

  try {
    BitcoinExchange btc;
    btc.loadDatabase("data.csv");
    btc.processInputFile(argv[1]);
  } catch (std::exception const &e) {
    std::cerr << e.what() << std::endl;
    return 1;
  }

  return 0;
}
