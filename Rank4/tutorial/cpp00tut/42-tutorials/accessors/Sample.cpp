#include "Sample.hpp"
#include <iostream>

Sample::Sample() {
	std::cout << "Constructor called!" << std::endl;
	this->_foo = 42;
}

Sample::~Sample() {
	std::cout << "Destructor called!" << std::endl;
}

int	Sample::getFoo() const {
	return (this->_foo);
}

void	Sample::setFoo(int value) {
	if (value >= 0)
		this->_foo = value;
}
