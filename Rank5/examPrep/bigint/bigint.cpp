#include "bigint.hpp"
#include <sstream>
#include <algorithm>

void bigint::trim_zeros() {
	size_t start = _str.find_first_not_of('0');
	if (start == std::string::npos) _str = "0";
	else _str = _str.substr(start);
}

bigint::bigint() : _str("0") {}

bigint::bigint(unsigned long long num) {
	std::stringstream ss;
	ss << num;
	_str = ss.str();
}

bigint::bigint(const std::string& str) : _str(str) {
	trim_zeros();
}

bigint::bigint(const bigint& other) : _str(other._str) {}

bigint& bigint::operator=(const bigint& other) {
	if (this != &other) {
		_str = other._str;
	}
	return *this;
}

bigint::~bigint() {}

const std::string& bigint::get_str() const {
	return _str;
}

bigint bigint::operator+(const bigint& other) const {
	std::string result = "";
	int i = _str.length() - 1;
	int j = other._str.length() - 1;
	int carry = 0;

	while (i >= 0 || j >= 0 || carry) {
		int sum = carry;
		if (i >= 0) sum += _str[i--] - '0';
		if (j >= 0) sum += other._str[j--] - '0';

		carry = sum / 10;
		result.push_back((sum % 10) + '0');
	}

	std::reverse(result.begin(), result.end());
	return bigint(result);
}

bigint& bigint::operator+=(const bigint& other) {
	*this = *this + other;
	return *this;
}

// Left shift

bigint bigint::operator<<(size_t shift) const {
	if (_str == "0") return *this;
	std::string res = _str + std::string(shift, '0');
	return bigint(res);
}

bigint& bigint::operator<<=(size_t shift) {
	*this = *this << shift;
	return *this;
}

// Right shift

bigint bigint::operator>>(size_t shift) const {
	if (_str == "0" || shift == 0) return *this;
	if (shift >= _str.length()) return bigint("0");
	std::string res = _str.substr(0, _str.length() - shift);
	return bigint(res);
}

bigint& bigint::operator>>=(size_t shift) {
	*this = *this >> shift;
	return *this;
}

// bigint shifts

size_t bigint::to_size_t() const {
	std::stringstream ss(_str);
	size_t val = 0;
	ss >> val;
	return val;
}

bigint bigint::operator<<(const bigint& shift) const {
	return *this << shift.to_size_t();
}

bigint& bigint::operator<<=(const bigint& shift) {
	*this = *this << shift.to_size_t();
	return *this;
}

bigint bigint::operator>>(const bigint& shift) const {
	return *this >> shift.to_size_t();
}

bigint& bigint::operator>>=(const bigint& shift) {
	*this = *this >> shift.to_size_t();
	return *this;
}

// increments

bigint& bigint::operator++() {
	*this += bigint(1);
	return *this;
}

bigint bigint::operator++(int) {
	bigint temp = *this;
	*this += bigint(1);
	return temp;
}

// boolsche

bool bigint::operator==(const bigint& other) const {
	return _str == other._str;
}

bool bigint::operator!=(const bigint& other) const {
	return _str != other._str;
}

bool bigint::operator<(const bigint& other) const {
	if (_str.length() != other._str.length())
		return _str.length() < other._str.length();
	return _str < other._str;
}

bool bigint::operator>(const bigint& other) const {
	return other < *this;
}

bool bigint::operator<=(const bigint& other) const {
	return !(*this > other);
}

bool bigint::operator>=(const bigint& other) const {
	return !(*this < other);
}

std::ostream& operator<<(std::ostream& os, const bigint& obj) {
	os << obj.get_str();
	return os;
}
