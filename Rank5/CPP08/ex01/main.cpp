#include "Span.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

int main() {
  std::srand(std::time(NULL));
  std::cout << "\n--- 5 Number Test ---" << std::endl;
  try {
    Span sp = Span(5);
    sp.addNumber(3);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    // sp.addNumber(11);
    std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
    std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    int amount = 10000;
    std::vector<int> vec(amount, 42);
    Span sp(amount);
    sp.addNumber(vec.begin(), vec.end());
    std::cout << "\n--- " << amount << " Number Test ---" << std::endl;
    {
      std::cout << "shortestSpan: " << sp.shortestSpan() << std::endl;
      std::cout << "longestSpan: " << sp.longestSpan() << std::endl;
    }
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
