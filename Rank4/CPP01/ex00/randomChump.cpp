#include "Zombie.hpp"
#include <iostream>
#include <string>

void randomChump(std::string name) {

	Zombie chump(name);

	chump.announce();
}
