#include "Zombie.hpp"
#include <iostream>
#include <string>

// public ----------------------------------------------------------------------

Zombie::Zombie(std::string name) : _name(name) {}

Zombie::~Zombie() { std::cout << _name << " died." << std::endl; }

void Zombie::announce(void) {
  std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

// private ---------------------------------------------------------------------

Zombie::Zombie() {}
