#include "Zombie.hpp"
#include <iostream>
#include <string>

int main() {
  Zombie *zombies;
  int i;
  int N;

  N = 42;
  zombies = zombieHorde(N, "zombie");
  i = -1;
  while (++i < N) {
    zombies[i].announce();
  }
  delete [] zombies;
}
