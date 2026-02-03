#include "Integer.hpp"
#include <iostream>

Integer::Integer(int const n) : _n(n) {
  std::cout << "Constructor called with value " << n << std::endl;
}

Integer::~Integer() {
  std::cout << "Destructor called with value " << _n << std::endl;
}

int Integer::getValue() const { return _n; }

Integer &Integer::operator=(Integer const &rhs) {
  std::cout << "Assignation operator called from " << _n;
  std::cout << " to " << rhs.getValue() << std::endl;
  _n = rhs.getValue();
  return *this;
}
