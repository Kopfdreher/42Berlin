#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <iostream>
#include <string>

int main() {

  FragTrap tom("Tom");
  FragTrap generic;
  FragTrap tomClone(tom);


  tom.highFivesGuys();
  generic.highFivesGuys();
  tomClone.highFivesGuys();
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
