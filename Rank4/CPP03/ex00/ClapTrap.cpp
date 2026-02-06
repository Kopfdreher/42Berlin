#include "ClapTrap.hpp"
#include <iostream>
#include <string>

// public ----------------------------------------------------------------------

ClapTrap::ClapTrap()
    : _name("Generic"), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

  std::cout << "ClapTrap " << _name << " was born." << std::endl;
}

ClapTrap::ClapTrap(std::string name)
    : _name(name), _hitPoints(10), _energyPoints(10), _attackDamage(0) {

  std::cout << "ClapTrap " << _name << " was born." << std::endl;
}

ClapTrap &ClapTrap::operator=(ClapTrap const &rhs) {

  if (this != &rhs) {
    _name = rhs._name;
    _hitPoints = rhs._hitPoints;
    _energyPoints = rhs._energyPoints;
    _attackDamage = rhs._attackDamage;
  }
  return *this;
}

ClapTrap::ClapTrap(ClapTrap const &src) {

  *this = src;
  std::cout << "ClapTrap " << _name << " was cloned." << std::endl;
}

ClapTrap::~ClapTrap() {

  std::cout << "ClapTrap " << _name << " died." << std::endl;
}

// methods

void ClapTrap::attack(const std::string &target) {

  if (_energyPoints && _hitPoints) {
    std::cout << "ClapTrap " << _name << " attacks " << target << ", causing "
              << _attackDamage << " points of damage!" << std::endl;
    _energyPoints--;
  } else {
    std::cout << "ClapTrap " << _name << " is out of action." << std::endl;
  }
}

void ClapTrap::takeDamage(unsigned int amount) {

  if (_hitPoints == 0) {
    std::cout << "ClapTrap " << _name << " is already dead." << std::endl;
  } else {
    std::cout << "ClapTrap " << _name << " takes " << amount
              << " points of damage!" << std::endl;
    if (_hitPoints > amount)
      _hitPoints -= amount;
    else
      _hitPoints = 0;
  }
}

void ClapTrap::beRepaired(unsigned int amount) {

  if (_energyPoints && _hitPoints) {
    std::cout << "ClapTrap " << _name << " repairs " << amount
              << " points of damage!" << std::endl;
    _energyPoints--;
    _hitPoints += amount;
  } else {
    std::cout << "ClapTrap " << _name << " is out of action." << std::endl;
  }
}

// private ---------------------------------------------------------------------
// std::string _name;
// unsigned int _hitPoints;
// unsigned int _energyPoints;
// unsigned int _attackDamage;
