#ifndef VECT2_HPP 
#define VECT2_HPP 

#include <iostream>

class vect2 {
public:
	int x;
	int y;

	vect2();
	vect2(int a, int b);
	vect2(const vect2& other);
	vect2 operator=(const vect2& other);
	~vect2();

	int operator[](int index) const;
	int& operator[](int index);

	// de-increments
	vect2 operator++();
	vect2 operator++(int);
	vect2 operator--();
	vect2 operator--(int);

	// plus minus
	vect2 operator+(const vect2& other) const;
	vect2& operator+=(const vect2& other);
	vect2 operator-(const vect2& other) const;
	vect2 operator-() const;
	vect2& operator-=(const vect2& other);

	// multiply
	vect2 operator*(const int& other) const;
	vect2& operator*=(const int& other);
	vect2 operator*(const vect2& other) const;
	vect2& operator*=(const vect2& other);

	// boolsche
	bool operator==(const vect2& other) const;
	bool operator!=(const vect2& other) const;
	bool operator<(const vect2& other) const;
	bool operator<=(const vect2& other) const;
	bool operator>(const vect2& other) const;
	bool operator>=(const vect2& other) const;
};

vect2 operator*(const int& lhs, const vect2& rhs);
std::ostream& operator<<(std::ostream& input, const vect2& obj);

#endif
