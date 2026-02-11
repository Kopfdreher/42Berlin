#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include <iostream>

int main() {

  std::cout << "\n-- Test: Allocate Single Objects --\n" << std::endl;
  {
    //const AAnimal *meta = new AAnimal();
    const AAnimal *j = new Cat();
    const AAnimal *i = new Dog();

    std::cout << "\n[Types]" << std::endl;
    std::cout << "j is a " << j->getType() << std::endl;
    std::cout << "i is a " << i->getType() << std::endl;
    //std::cout << "meta is an " << meta->getType() << std::endl;

    std::cout << "\n[Sounds]" << std::endl;
    i->makeSound();
    j->makeSound();
    //meta->makeSound();

    std::cout << "\n[Destructors]" << std::endl;
    delete i;
    delete j;
    //delete meta;
  }
  std::cout << "\n-- Test: Allocate Array of Objects --\n" << std::endl;
  {
    int i;
    int amount = 42;
    AAnimal *animals[amount];

    i = -1;
    while (++i < amount / 2) {
      std::cout << "\nCat:" << i << std::endl;
      animals[i] = new Cat();
      std::cout << "\nDog:" << i << std::endl;
      animals[amount / 2 + i] = new Dog();
    }

    i = -1;
    while (++i < amount) {
      std::cout << "\n" << i << ": " << animals[i]->getType() << std::endl;
      animals[i]->makeSound();
      delete animals[i];
    }
  }
}
