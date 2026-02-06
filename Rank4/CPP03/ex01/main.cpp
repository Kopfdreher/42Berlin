#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <iostream>
#include <string>

int main() {

  ScavTrap tom("Tom");
  ScavTrap generic;
  ScavTrap tomClone(tom);

  tom.guardGate();
  generic.guardGate();
  tomClone.guardGate();
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
