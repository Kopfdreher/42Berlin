#include "Array.hpp"
#include <iostream>
#include <string>

int main(void) {
  std::cout << "\nInt-Array" << std::endl;
  try {
    Array<int> arr(100);
    arr[4] = 123;
    arr[3] = arr[4];
    // arr[-3] = arr[4];
    std::cout << "arr[4]: " << arr[4] << std::endl;
    std::cout << "arr[3]: " << arr[3] << std::endl;
    std::cout << "arr[2]: " << arr[2] << std::endl;
    std::cout << "arr[1]: " << arr[1] << std::endl;
    std::cout << "arr[0]: " << arr[0] << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "\nString-Array" << std::endl;
  try {
    Array<std::string> arr(100);
    arr[4] = "hello";
    arr[3] = "world";
    arr[2] = arr[4];
    arr[1] = arr[3];
    // arr[-3] = arr[4];
    std::cout << "arr[4]: " << arr[4] << std::endl;
    std::cout << "arr[3]: " << arr[3] << std::endl;
    std::cout << "arr[2]: " << arr[2] << std::endl;
    std::cout << "arr[1]: " << arr[1] << std::endl;
    std::cout << "arr[0]: " << arr[0] << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "\nArray-Array" << std::endl;
  try {
    Array<std::string> arr(100);
    arr[4] = "hello";
    arr[3] = "world";
    Array< Array<std::string> > arrArr(100);
    arrArr[42] = arr;
    arrArr[42][4] = arr[4];
    arrArr[42][3] = arr[3];
    std::cout << "arrArr[42][4]: " << arrArr[42][4] << std::endl;
    std::cout << "arrArr[42][3]: " << arrArr[42][3] << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
