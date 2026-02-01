#include "Zombie.hpp"
#include <iostream>
#include <string>

int main() {
  Zombie *heapZombie;

  heapZombie = newZombie("heapZombie");
	heapZombie->announce();
  delete heapZombie;
	randomChump("stackZombie");
}
