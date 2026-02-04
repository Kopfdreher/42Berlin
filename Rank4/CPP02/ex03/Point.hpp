#include "Fixed.hpp"

#ifndef POINT_H
#define POINT_H

class Point {

public:
  Point();
  Point(float const x, float const y);
  Point(Point const &src);
  ~Point();

  // assign
  Point &operator=(Point const &rhs);

  // methods
  Fixed const getY() const;
  Fixed const getX() const;

private:
  Fixed const _x;
  Fixed const _y;
};

#endif
