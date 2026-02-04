#include "Fixed.hpp"
#include <iostream>
#include <cmath>

// public ----------------------------------------------------------------------

Fixed::Fixed() {

  _value = 0;
}

Fixed::Fixed(int const value) {

  _value = value << _fractBits;
}

Fixed::Fixed(float const value) {

  _value = roundf(value * (1 << _fractBits));
}

Fixed::Fixed(Fixed const &src) {

  *this = src;
}

Fixed::~Fixed() {

}

// operators -------------------------------------------------------------------

Fixed &Fixed::operator=(Fixed const &rhs) {

  if (this != &rhs)
    _value = rhs.getRawBits();
  return *this;
}

  // compare

bool Fixed::operator>(Fixed const &rhs) const {

  return _value > rhs.getRawBits();
}

bool Fixed::operator<(Fixed const &rhs) const {

  return _value < rhs.getRawBits();
}

bool Fixed::operator>=(Fixed const &rhs) const {

  return _value >= rhs.getRawBits();
}

bool Fixed::operator<=(Fixed const &rhs) const {

  return _value <= rhs.getRawBits();
}

bool Fixed::operator==(Fixed const &rhs) const {

  return _value == rhs.getRawBits();
}

bool Fixed::operator!=(Fixed const &rhs) const {

  return _value != rhs.getRawBits();
}

  // arthmetic

Fixed Fixed::operator+(Fixed const &rhs) const {

  Fixed result;

  result.setRawBits(_value + rhs.getRawBits());
  return result;
}

Fixed Fixed::operator-(Fixed const &rhs) const {

  Fixed result;

  result.setRawBits(_value - rhs.getRawBits());
  return result;
}

Fixed Fixed::operator*(Fixed const &rhs) const {

  Fixed result;

  result.setRawBits((long(_value) * long(rhs.getRawBits())) >> _fractBits);
  return result;
}

Fixed Fixed::operator/(Fixed const &rhs) const {

  Fixed result;

  result.setRawBits((long(_value) << _fractBits) / rhs.getRawBits());
  return result;
}

  // increment/decrement

Fixed &Fixed::operator++() {

  _value++;
  return *this;
}

Fixed Fixed::operator++(int) {

  Fixed tmp(*this);
  _value++;
  return tmp;
}

Fixed &Fixed::operator--() {

  _value--;
  return *this;
}

Fixed Fixed::operator--(int) {

  Fixed tmp(*this);
  _value--;
  return tmp;
}

  // static methods

Fixed &Fixed::min(Fixed &a, Fixed &b) {

  if (a < b)
    return a;
  return b;
}

const Fixed &Fixed::min(Fixed const &a, Fixed const &b) {

  if (a < b)
    return a;
  return b;
}

Fixed &Fixed::max(Fixed &a, Fixed &b) {

  if (a > b)
    return a;
  return b;
}

const Fixed &Fixed::max(Fixed const &a, Fixed const &b) {

  if (a > b)
    return a;
  return b;
}

  // methods

int Fixed::getRawBits() const {

  return _value;
}

void Fixed::setRawBits(int const raw) {

  _value = raw;
}

float Fixed::toFloat() const {

  return (float)_value / (1 << _fractBits);
}

int Fixed::toInt() const {

  return _value >> _fractBits;
}

std::ostream &operator<<(std::ostream &o, Fixed const &rhs) {
  o << rhs.toFloat();
  return o;
}

// private ---------------------------------------------------------------------
// int _value;

const int Fixed::_fractBits = 8;
