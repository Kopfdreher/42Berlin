#ifndef DIAMONDTRAP_H
#define DIAMONDTRAP_H

#include "FragTrap.hpp"
#include "ScavTrap.hpp"
#include <string>

class DiamondTrap : public ScavTrap, public FragTrap {

public:
  DiamondTrap(); // empty constructor
  DiamondTrap(std::string name);
  DiamondTrap(DiamondTrap const &); // copy constructor
  DiamondTrap &operator=(DiamondTrap const &); // copy assignment operator
  ~DiamondTrap(); // destructor

  void whoAmI();

  using ScavTrap::attack;

private:
  std::string _name;

};

#endif
