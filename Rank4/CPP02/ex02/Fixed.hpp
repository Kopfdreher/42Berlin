#include <iostream>

#ifndef FIXED_H
#define FIXED_H

class Fixed {

public:
  Fixed();
  Fixed(int const value);
  Fixed(float const value);
  Fixed(Fixed const &src);
  ~Fixed();

  Fixed &operator=(Fixed const &rhs);

  int getRawBits() const;
  void setRawBits(int const raw);
  float toFloat() const;
  int toInt() const;

private:
  int _value;
  static const int _fractBits;

};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
