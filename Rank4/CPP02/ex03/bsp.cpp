#include "Point.hpp"
#include "Fixed.hpp"

static Fixed crossP(Point const &a, Point const &b, Point const &p) {

  Fixed cP = (b.getX() - a.getX()) * (p.getY() - a.getY()) -
             (b.getY() - a.getY()) * (p.getX() - a.getX());
  return cP;
}

bool bsp(Point const a, Point const b, Point const c, Point const point) {

  Fixed cPA = crossP(a, b, point);
  Fixed cPB = crossP(b, c, point);
  Fixed cPC = crossP(c, a, point);

  return ((cPA > 0 && cPB > 0 && cPC > 0) || (cPA < 0 && cPB < 0 && cPC < 0));
}
