#include "Point.hpp"
#include "Fixed.hpp"

// public ----------------------------------------------------------------------

Point::Point() : _x(0), _y(0) {}

Point::Point(float const x, float const y) : _x(Fixed(x)), _y(Fixed(y)) {}

Point::Point(Point const &src) : _x(src.getX()), _y(src.getY()) {}

Point::~Point() {}

// assign

Point &Point::operator=(Point const &rhs) {

  (void)rhs;
  return *this;
}

// methods

Fixed const Point::getX() const { return (_x); }

Fixed const Point::getY() const { return (_y); }

// private ---------------------------------------------------------------------
//  Fixed const _x;
//  Fixed const _y;
