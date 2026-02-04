#include "Fixed.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

Fixed::Fixed() {

  std::cout << "Default constructor called" << std::endl;
  _value = 0;
}

Fixed::Fixed(Fixed const &src) {

  std::cout << "Copy constructor called" << std::endl;
  *this = src;
}

Fixed::~Fixed() {

  std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(Fixed const &rhs) {

  std::cout << "Copy assignment operator called" << std::endl;
  if (this != &rhs)
    _value = rhs.getRawBits();
  return *this;
}

int Fixed::getRawBits() const {

  std::cout << "getRawBits member function called" << std::endl;
  return _value;
}

void Fixed::setRawBits(int const raw) {

  std::cout << "setRawBits member function called" << std::endl;
  _value = raw;
}


// private ---------------------------------------------------------------------
// int _value;

const int Fixed::_fractBits = 8;
