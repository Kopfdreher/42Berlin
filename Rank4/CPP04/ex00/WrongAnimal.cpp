#include "WrongAnimal.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

WrongAnimal::Animal() : type("Animal") {

  std::cout << "Default animal constructor called!" << std::endl;
}

WrongAnimal::Animal(std::string t) : type(t) {

  std::cout << "WrongAnimal of type " << t << " constructor called!" << std::endl;
}

WrongAnimal &Animal::operator=(Animal const &rhs) {

  std::cout << "Copy animal assignment operator called!" << std::endl;
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}

WrongAnimal::Animal(Animal const &src) {

  std::cout << "Copy animal constructor called!" << std::endl;
  *this = src;
}

WrongAnimal::~Animal() { std::cout << "Default animal destructor called!" << std::endl; }

void WrongAnimal::makeSound() const { std::cout << "*Animal sound!*" << std::endl; }

std::string WrongAnimal::getType() const { return type; }

// protected -------------------------------------------------------------------
// std::string type;
