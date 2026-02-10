#include "Cat.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

Cat::Cat() : Animal("Cat") {

  std::cout << "Default Cat constructor called!" << std::endl;
}

Cat &Cat::operator=(Cat const &rhs) {

  std::cout << "Copy Cat assignment operator called!" << std::endl;
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}

Cat::Cat(Cat const &src) {

  std::cout << "Copy Cat constructor called!" << std::endl;
  *this = src;
}

Cat::~Cat() { std::cout << "Default Cat destructor called!" << std::endl; }

void Cat::makeSound() const { std::cout << "*Miauuu!*" << std::endl; }

// protected -------------------------------------------------------------------
// std::string type;
