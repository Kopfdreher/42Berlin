#include "Dog.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

Dog::Dog() : Animal("Dog") {

  std::cout << "Default Dog constructor called!" << std::endl;
}

Dog &Dog::operator=(Dog const &rhs) {

  std::cout << "Copy Dog assignment operator called!" << std::endl;
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}

Dog::Dog(Dog const &src) {

  std::cout << "Copy Dog constructor called!" << std::endl;
  *this = src;
}

Dog::~Dog() { std::cout << "Default Dog destructor called!" << std::endl; }

void Dog::makeSound() const { std::cout << "*Wuffff wufff!*" << std::endl; }

// protected -------------------------------------------------------------------
// std::string type;
