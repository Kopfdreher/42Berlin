#include "DiamondTrap.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

DiamondTrap::DiamondTrap() : ClapTrap("Generic_clap_name") {

  _name = "Generic";
  _hitPoints = FragTrap::_hitPoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;
  std::cout << "ClapTrap " << _name << " upgraded to DiamondTrap." << std::endl;
}

DiamondTrap::DiamondTrap(std::string name) : ClapTrap(name + "_clap_name") {

  _name = name;
  _hitPoints = FragTrap::_hitPoints;
  _energyPoints = ScavTrap::_energyPoints;
  _attackDamage = FragTrap::_attackDamage;
  std::cout << "ClapTrap " << _name << " upgraded to DiamondTrap." << std::endl;
}

DiamondTrap &DiamondTrap::operator=(DiamondTrap const &rhs) {

  if (this != &rhs) {
    ClapTrap::operator=(rhs);
    _name = rhs._name;
  }
  return *this;
}

DiamondTrap::DiamondTrap(DiamondTrap const &src) : ClapTrap(src) {

  *this = src;
  std::cout << "ClapTrap " << _name << " was upgraded to DiamondTrap clone of "
            << src._name << std::endl;
}

DiamondTrap::~DiamondTrap() {

  std::cout << "DiamondTrap " << _name << " downgraded to ClapTrap."
            << std::endl;
}

// methods

void DiamondTrap::whoAmI() {

  std::cout << "My DiamondTrapName is " << _name << "\nMy ClapTrapName is "
            << ClapTrap::_name << std::endl;
}

// protected -------------------------------------------------------------------
// std::string _name;
// unsigned int _hitPoints;
// unsigned int _energyPoints;
// unsigned int _attackDamage;
