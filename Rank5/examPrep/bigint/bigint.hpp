#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <iostream>
#include <string>
#include <algorithm>

class bigint {
private:
	std::string _str;
	void trim_zeros();
	size_t to_size_t() const;

public:
	// Constructors
	bigint();
	bigint(unsigned long long num);
	bigint(const std::string& str);
	bigint(const bigint& other);
	bigint& operator=(const bigint& other);
	~bigint();

	// Accessor
	const std::string& get_str() const;
	
	// Addition Operators
	bigint operator+(const bigint& other) const;
	bigint& operator+=(const bigint& other);

	// Shift / Multiplication Operators
	bigint operator<<(size_t shift) const;
	bigint& operator<<=(size_t shift);
	bigint operator>>(size_t shift) const;
	bigint& operator>>=(size_t shift);

	bigint operator<<(const bigint& shift) const;
	bigint& operator<<=(const bigint& shift);
	bigint operator>>(const bigint& shift) const;
	bigint& operator>>=(const bigint& shift);

	// Increments
	bigint& operator++();
	bigint operator++(int);

	// Comparison Operators
	bool operator==(const bigint& other) const;
	bool operator!=(const bigint& other) const;
	bool operator<(const bigint& other) const;
	bool operator>(const bigint& other) const;
	bool operator<=(const bigint& other) const;
	bool operator>=(const bigint& other) const;
};

std::ostream& operator<<(std::ostream& os, const bigint& obj);

#endif
