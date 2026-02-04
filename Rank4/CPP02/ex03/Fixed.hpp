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

  // assign
  Fixed &operator=(Fixed const &rhs);

  // compare
  bool operator>(Fixed const &rhs) const;
  bool operator<(Fixed const &rhs) const;
  bool operator>=(Fixed const &rhs) const;
  bool operator<=(Fixed const &rhs) const;
  bool operator==(Fixed const &rhs) const;
  bool operator!=(Fixed const &rhs) const;

  // arthmetic
  Fixed operator+(Fixed const &rhs) const;
  Fixed operator-(Fixed const &rhs) const;
  Fixed operator*(Fixed const &rhs) const;
  Fixed operator/(Fixed const &rhs) const;

  // increment/decrement
  Fixed &operator++();
  Fixed operator++(int);
  Fixed &operator--();
  Fixed operator--(int);

  // static methods
  static Fixed &min(Fixed &a, Fixed &b);
  static const Fixed &min(Fixed const &a, Fixed const &b);
  static Fixed &max(Fixed &a, Fixed &b);
  static const Fixed &max(Fixed const &a, Fixed const &b);

  // methods
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
