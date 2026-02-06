#include <string>

#ifndef CLAPTRAP_H
#define CLAPTRAP_H

class ClapTrap {

public:
  ClapTrap(); // empty constructor
  ClapTrap(std::string name);
  ClapTrap(ClapTrap const &); // copy constructor
  ClapTrap &operator=(ClapTrap const &); // copy assignment operator
  ~ClapTrap(); // destructor

  void attack(const std::string &target);
  void takeDamage(unsigned int amount);
  void beRepaired(unsigned int amount);

protected:
  std::string _name;
  unsigned int _hitPoints;
  unsigned int _energyPoints;
  unsigned int _attackDamage;

};

#endif
