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

Integer Integer::operator+(Integer const &rhs) const {

  std::cout << "Addition operator called from " << _n;
  std::cout << " and " << rhs.getValue() << std::endl;
  return Integer(_n + rhs.getValue());
}

std::ostream &operator<<(std::ostream &o, Integer const &rhs) {

  o << rhs.getValue();
  return o;
}
