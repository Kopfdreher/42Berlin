#include "iter.hpp"
#include <iostream>

int main(void) {
  int arrI[] = {1, 2, 3, 4, 5, 6};
  char arrC[] = {'h', 'e', 'l', 'l', 'o'};
  float const arrF[] = {1, 2, 3, 4, 5, 6};

  std::cout << "\nInt-Array:\n";
  printArr<int>(arrI, 6);
  std::cout << "Int-Array (iterated):\n";
  iter(arrI, 6, add<int>);
  printArr<int>(arrI, 6);

  std::cout << "\nChar-Array:\n";
  printArr<char>(arrC, 5);
  std::cout << "Char-Array (iterated):\n";
  iter(arrC, 5, add<char>);
  printArr<char>(arrC, 5);

  std::cout << "\nFloat-Array:\n";
  printArr<float const>(arrF, 6);
  // iter(arrF, 5, add<float>);
}
