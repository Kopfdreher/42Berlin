#include "Weapon.hpp"
#include <string>

// public ----------------------------------------------------------------------

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

std::string Weapon::getType() const & { // change the function it needs a reference return
  return ((const)_type);
}

void Weapon::setType(std::string type) { _type = type; }
