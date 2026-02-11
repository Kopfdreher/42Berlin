#include "Animal.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

Animal::Animal() : type("Animal") {

  std::cout << "Default Animal constructor called!" << std::endl;
}

Animal::Animal(std::string t) : type(t) {

  std::cout << "Animal of type " << t << " constructor called!" << std::endl;
}

Animal &Animal::operator=(Animal const &rhs) {

  std::cout << "Copy Animal assignment operator called!" << std::endl;
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}

Animal::Animal(Animal const &src) {

  std::cout << "Copy Animal constructor called!" << std::endl;
  *this = src;
}

Animal::~Animal() { std::cout << "Default Animal destructor called!" << std::endl; }

void Animal::makeSound() const { std::cout << "*Animal sound!*" << std::endl; }

std::string Animal::getType() const { return type; }

// protected -------------------------------------------------------------------
// std::string type;
