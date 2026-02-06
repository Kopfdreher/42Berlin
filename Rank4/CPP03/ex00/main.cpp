#include "ClapTrap.hpp"
#include <iostream>
#include <string>

int main() {

  ClapTrap tom("Tom");
  ClapTrap generic;
  ClapTrap tomClone(tom);


  tom.attack("himself");
  tom.takeDamage(100);
  tom.beRepaired(20);
  generic.attack("Generic");
  generic.beRepaired(1000);
  generic.takeDamage(1000);
  tomClone.attack("Tom");
  tomClone.beRepaired(20);
  tomClone.beRepaired(20);
  tomClone.beRepaired(20);
  tomClone.beRepaired(20);
  tomClone.beRepaired(20);
  tomClone.beRepaired(20);
  tomClone.beRepaired(20);
  tomClone.beRepaired(20);
  tomClone.beRepaired(20);
  tomClone.beRepaired(20);
  tomClone.takeDamage(210);
}
