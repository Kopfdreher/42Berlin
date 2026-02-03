#include "Weapon.hpp"
#include <string>

// public ----------------------------------------------------------------------

Weapon::Weapon(std::string type) : _type(type) {}

Weapon::~Weapon() {}

const std::string &Weapon::getType() { return (_type); }

void Weapon::setType(std::string type) { _type = type; }
