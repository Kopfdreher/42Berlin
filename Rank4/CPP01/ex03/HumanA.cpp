#include "HumanA.hpp"
#include "Weapon.hpp"
#include <string>
#include <iostream>

// public ----------------------------------------------------------------------

HumanA::HumanA(std::string name, Weapon &weapon) : _weapon(weapon), _name(name) {}

HumanA::~HumanA() {}

void HumanA::attack() {

  std::cout << _name << " attacks with their " << _weapon.getType() << std::endl;
}
