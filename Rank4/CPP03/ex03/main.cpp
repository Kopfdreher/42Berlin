#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "DiamondTrap.hpp"
#include <iostream>
#include <string>

int main() {

  DiamondTrap tom("Tom");
  DiamondTrap generic;
  DiamondTrap tomClone(tom);


  tom.whoAmI();
  generic.whoAmI();
  tomClone.whoAmI();
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
