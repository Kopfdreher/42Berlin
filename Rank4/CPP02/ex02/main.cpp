#include "Fixed.hpp"
#include <iostream>

int main() {
  Fixed a;
  Fixed b(10);
  Fixed c(42.42f);
  Fixed d(b);

  a = Fixed(1234.4321f);

  std::cout << "a is " << a << std::endl;
  std::cout << "b is " << b << std::endl;
  std::cout << "c is " << c << std::endl;
  std::cout << "d is " << d << std::endl;

  std::cout << "a is " << a.toInt() << " as interger" << std::endl;
  std::cout << "b is " << b.toInt() << " as interger" << std::endl;
  std::cout << "c is " << c.toInt() << " as interger" << std::endl;
  std::cout << "d is " << d.toInt() << " as interger" << std::endl;
}
