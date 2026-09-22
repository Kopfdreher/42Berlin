#include "vect2.hpp"

vect2::vect2() : x(0), y(0) {}

vect2::vect2(int a, int b) : x(a), y(b) {}

vect2::vect2(const vect2& other) : x(other.x), y(other.y) {}

vect2 vect2::operator=(const vect2& other) {
	if (this != &other) {
		x = other.x;
		y = other.y;
	}
	return *this;
}

vect2::~vect2() {}

int vect2::operator[](int index) const {
	if (index == 0) return x;
	return y;
}
int& vect2::operator[](int index) {
	if (index == 0) return x;
	return y;
}

// de-increment

vect2 vect2::operator++() {
	++x;
	++y;
	return *this;
}

vect2 vect2::operator++(int) {
	vect2 tmp(x, y);
	++x;
	++y;
	return tmp;
}

vect2 vect2::operator--() {
	--x;
	--y;
	return *this;
}

vect2 vect2::operator--(int) {
	vect2 tmp(x, y);
	--x;
	--y;
	return tmp;
}

// plus

vect2 vect2::operator+(const vect2& other) const {
	return vect2(x + other.x, y + other.y);
}

vect2& vect2::operator+=(const vect2& other) {
	x += other.x;
	y += other.y;
	return *this;
}

// minus 

vect2 vect2::operator-() const {
	return vect2(-x, -y);
}

vect2 vect2::operator-(const vect2& other) const {
	return vect2(x - other.x, y - other.y);
}

vect2& vect2::operator-=(const vect2& other) {
	x -= other.x;
	y -= other.y;
	return *this;
}

// multiply

vect2 vect2::operator*(const int& other) const {
	return vect2(x * other, y * other);
}

vect2& vect2::operator*=(const int& other) {
	x *= other;
	y *= other;
	return *this;
}

vect2 vect2::operator*(const vect2& other) const {
	return vect2(x * other.x, y * other.y);
}

vect2& vect2::operator*=(const vect2& other) {
	x *= other.x;
	y *= other.y;
	return *this;
}

// boolsche

bool vect2::operator==(const vect2& other) const {
	if (x == other.x && y == other.y) return true;
	return false;
}

bool vect2::operator!=(const vect2& other) const {
	if (x != other.x && y != other.y) return true;
	return false;
}

bool vect2::operator<(const vect2& other) const {
	if (x < other.x && y < other.y) return true;
	return false;
}

bool vect2::operator<=(const vect2& other) const {
	if (x <= other.x && y <= other.y) return true;
	return false;
}

bool vect2::operator>(const vect2& other) const {
	if (x > other.x && y > other.y) return true;
	return false;
}

bool vect2::operator>=(const vect2& other) const {
	if (x >= other.x && y >= other.y) return true;
	return false;
}

vect2 operator*(const int& lhs, const vect2& rhs) {
	return vect2(lhs * rhs.x, lhs * rhs.y);
}

std::ostream& operator<<(std::ostream& input, const vect2& obj) {
	input << "{" << obj.x << ", " << obj.y << "}";
	return input;
}
