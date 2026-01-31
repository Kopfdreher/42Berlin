#include "Sample.hpp"
#include <iostream>

Sample::Sample() {
	std::cout << "Constructor called!" << std::endl;
	Sample::_mbInst += 1;
}

Sample::~Sample() {
	std::cout << "Destructor called!" << std::endl;
	Sample::_mbInst -= 1;
}

static int Sample::getMbInst() {
	return (Sample::_mbInst);
}

int	Sample::_mbInst = 0;
