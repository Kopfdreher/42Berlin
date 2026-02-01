#include "Weapon.hpp"
#include <string>

class HumanA {

public:
  HumanA(std::string name, Weapon &weapon);
  ~HumanA();

  void attack();

private:
  Weapon &_weapon;
  std::string _name;
};
