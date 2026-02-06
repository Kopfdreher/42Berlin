#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

// public ----------------------------------------------------------------------

ScavTrap::ScavTrap() : ClapTrap() {

  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ClapTrap " << _name << " upgraded to ScavTrap." << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {

  _hitPoints = 100;
  _energyPoints = 50;
  _attackDamage = 20;
  std::cout << "ClapTrap " << _name << " upgraded to ScavTrap." << std::endl;
}

ScavTrap &ScavTrap::operator=(ScavTrap const &rhs) {

  if (this != &rhs) {
    ClapTrap::operator=(rhs);
  }
  return *this;
}

ScavTrap::ScavTrap(ScavTrap const &src) : ClapTrap(src) {

  *this = src;
  std::cout << "ClapTrap " << _name << " was upgraded to ScavTrap clone of "
            << src._name << std::endl;
}

ScavTrap::~ScavTrap() {

  std::cout << "ScavTrap " << _name << " downgraded to ClapTrap." << std::endl;
}

// methods

void ScavTrap::attack(const std::string &target) {

  if (_energyPoints && _hitPoints) {
    std::cout << "ScavTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
  } else {
    std::cout << "ScavTrap " << _name << " is out of action." << std::endl;
  }
}

void ScavTrap::guardGate() {

  std::cout << "ScavTrap " << _name << " is now in gate keeper mode."
            << std::endl;
}

// protected -------------------------------------------------------------------
// std::string _name;
// unsigned int _hitPoints;
// unsigned int _energyPoints;
// unsigned int _attackDamage;
