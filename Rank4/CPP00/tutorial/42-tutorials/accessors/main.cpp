#include "Sample.hpp"
#include <iostream>

int main() {
	Sample instance;

	instance.setFoo(24);
	std::cout << "instance.getFoo: " << instance.getFoo() << std::endl;
	instance.setFoo(-24);
	std::cout << "instance.getFoo: " << instance.getFoo() << std::endl;
}
