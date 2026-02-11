#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main() {

  std::cout << "\n-- Test 1: Correct Implementation --\n" << std::endl;
  {
    const Animal *meta = new Animal();
    const Animal *j = new Dog();
    const Animal *i = new Cat();

    std::cout << "\n[Types]" << std::endl;
    std::cout << "j is a " << j->getType() << std::endl;
    std::cout << "i is a " << i->getType() << std::endl;
    std::cout << "meta is an " << meta->getType() << std::endl;

    std::cout << "\n[Sounds]" << std::endl;
    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << "\n[Destructors]" << std::endl;
    delete i;
    delete j;
    delete meta;
  }
  std::cout << "\n-- Test 2: Wrong Implementation --\n" << std::endl;
  {
    const WrongAnimal *meta = new WrongAnimal();
    const WrongAnimal *i = new WrongCat();

    std::cout << "\n[Types]" << std::endl;
    std::cout << "i is a " << i->getType() << std::endl;
    std::cout << "meta is an " << meta->getType() << std::endl;

    std::cout << "\n[Sounds]" << std::endl;
    i->makeSound();
    meta->makeSound();

    std::cout << "\n[Destructors]" << std::endl;
    delete i;
    delete meta;
  }
}
