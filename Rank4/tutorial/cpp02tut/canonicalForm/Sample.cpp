#include "Sample.hpp"
#include <iostream>

Sample::Sample() : _foo(0) {

  std::cout << "Default Constructor called" << std::endl;
}

Sample::Sample(int const n) : _foo(n) {

  std::cout << "Parametric Constructor called" << std::endl;
}

Sample::Sample(Sample const & src) {

  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Sample::~Sample() {

  std::cout << "Destructor called" << std::endl;
}

int Sampe::getFoo() const {

  return _foo;
}

Sample &Sample::operator=(Sample const &rhs) {

  std::cout << "Assignment operator called" << std::endl;
  if (this != &rhs)
    _foo = rhs.getFoo();
}
