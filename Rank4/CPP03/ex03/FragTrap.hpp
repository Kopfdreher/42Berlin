#ifndef FRAGTRAP_H
#define FRAGTRAP_H

#include "ClapTrap.hpp"
#include <string>

class FragTrap : virtual public ClapTrap {

public:
  FragTrap(); // empty constructor
  FragTrap(std::string name);
  FragTrap(FragTrap const &); // copy constructor
  FragTrap &operator=(FragTrap const &); // copy assignment operator
  ~FragTrap(); // destructor

  void attack(const std::string &target);
  void highFivesGuys();

};

#endif
