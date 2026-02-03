#include "Sample.hpp"
#include <iostream>

Sample::Sample() { std:: << "Constructor called" << std::endl; }

Sample::~Sample() { std:: << "Destructor called" << std::endl; }

void Sample::bar(char const c) const {
  std::cout << "Member function bar called with char overload" << std::endl;
}

void bar(int const n) const {
  std::cout << "Member function bar called with int overload" << std::endl;
}

void bar(float const z) const {
  std::cout << "Member function bar called with float overload" << std::endl;
}

void bar(Sample const &i) const {
  std::cout << "Member function bar called with Sample overload" << std::endl;
}
