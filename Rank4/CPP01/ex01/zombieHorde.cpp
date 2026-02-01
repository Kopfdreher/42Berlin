#include "Zombie.hpp"
#include <iostream>
#include <string>

Zombie *zombieHorde(int N, std::string name) {
	int i;
	Zombie *zombies = new Zombie[N];

	i = -1;
	while (++i < N)
	{
		zombies[i].Zombie::setName(name);
	}
  return (zombies);
}
