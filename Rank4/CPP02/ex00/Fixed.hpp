#ifndef FIXED_H
#define FIXED_H

class Fixed {

public:
  Fixed();
  Fixed(Fixed const &src);
  ~Fixed();

  Fixed &operator=(Fixed const &rhs);

  int getRawBits() const;
  void setRawBits(int const raw);

private:
  int _value;
  static const int _fractBits;

};

#endif
