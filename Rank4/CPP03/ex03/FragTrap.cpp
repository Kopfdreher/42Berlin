#include "FragTrap.hpp"
#include "ClapTrap.hpp"
#include <iostream>
#include <string>

// public ----------------------------------------------------------------------

FragTrap::FragTrap() : ClapTrap() {

  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "ClapTrap " << _name << " upgraded to FragTrap." << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {

  _hitPoints = 100;
  _energyPoints = 100;
  _attackDamage = 30;
  std::cout << "ClapTrap " << _name << " upgraded to FragTrap." << std::endl;
}

FragTrap &FragTrap::operator=(FragTrap const &rhs) {

  if (this != &rhs) {
    ClapTrap::operator=(rhs);
  }
  return *this;
}

FragTrap::FragTrap(FragTrap const &src) : ClapTrap(src) {

  *this = src;
  std::cout << "ClapTrap " << _name << " was upgraded to FragTrap clone of "
            << src._name << std::endl;
}

FragTrap::~FragTrap() {

  std::cout << "FragTrap " << _name << " downgraded to ClapTrap." << std::endl;
}

// methods

void FragTrap::attack(const std::string &target) {

  if (_energyPoints && _hitPoints) {
    std::cout << "FragTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
  } else {
    std::cout << "FragTrap " << _name << " is out of action." << std::endl;
  }
}

void FragTrap::highFivesGuys() {

  std::cout << "FragTrap " << _name << " requests a high-fives."
            << std::endl;
}

// protected -------------------------------------------------------------------
// std::string _name;
// unsigned int _hitPoints;
// unsigned int _energyPoints;
// unsigned int _attackDamage;
