#include "Dog.hpp"
#include "Brain.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

Dog::Dog() : AAnimal("Dog") {

  brain = new Brain();
  std::cout << "Default Dog constructor called!" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {

  std::cout << "Copy Dog assignment operator called!" << std::endl;
  if (this != &rhs) {
    type = rhs.type;
    *brain = *rhs.brain;
  }
  return *this;
}

Dog::Dog(Dog const &src) {

  brain = new Brain();
  std::cout << "Copy Dog constructor called!" << std::endl;
  *this = src;
}

Dog::~Dog() {

  delete brain;
  std::cout << "Default Dog destructor called!" << std::endl;
}

void Dog::makeSound() const { std::cout << "*Wufff!*" << std::endl; }

// protected -------------------------------------------------------------------
// std::string type;
