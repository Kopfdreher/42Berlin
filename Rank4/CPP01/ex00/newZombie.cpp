#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie *newZombie(std::string name) {
  Zombie *rtn = new Zombie(name);
  return (rtn);
}
