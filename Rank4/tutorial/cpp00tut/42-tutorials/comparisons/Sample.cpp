#include "Sample.hpp"
#include <iostream>

Sample::Sample(int value) {
	std::cout << "Constructor called!" << std::endl;
	this->_foo = 42;
}

Sample::~Sample() {
	std::cout << "Destructor called!" << std::endl;
}

int	Sample::getFoo() const {
	return (this->_foo);
}

int	Sample::compare(Sample * other) const {
	if (this->_foo < other->getFoo())
		return (-1);
	else if (this->_foo > other->getFoo())
		return (1);
	return (0);
}
