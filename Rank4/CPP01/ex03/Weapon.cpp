#include "Weapon.hpp"
#include <string>

// public ----------------------------------------------------------------------

Weapon() {}

~Weapon() {}

std::string getType() const {
  return (_type);
}

void setType(std::string type) {
  _type = type;
}

// private ---------------------------------------------------------------------
