#ifndef SCAVTRAP_H
#define SCAVTRAP_H

#include "ClapTrap.hpp"
#include <string>

class ScavTrap : public ClapTrap {

public:
  ScavTrap(); // empty constructor
  ScavTrap(std::string name);
  ScavTrap(ScavTrap const &); // copy constructor
  ScavTrap &operator=(ScavTrap const &); // copy assignment operator
  ~ScavTrap(); // destructor

  void attack(const std::string &target);
  void guardGate();

};

#endif
