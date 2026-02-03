#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"
#include <string>

class HumanB {

public:
  HumanB(std::string name);
  ~HumanB();

  void attack();
  void setWeapon(Weapon &weapon);

private:
  Weapon *_weapon;
  std::string _name;
};

#endif
