#include "WrongAnimal.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

WrongAnimal::WrongAnimal() : type("WrongAnimal") {

  std::cout << "Default WrongAnimal constructor called!" << std::endl;
}

WrongAnimal::WrongAnimal(std::string t) : type(t) {

  std::cout << "WrongAnimal of type " << t << " constructor called!"
            << std::endl;
}

WrongAnimal &WrongAnimal::operator=(WrongAnimal const &rhs) {

  std::cout << "Copy WrongAnimal assignment operator called!" << std::endl;
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}

WrongAnimal::WrongAnimal(WrongAnimal const &src) {

  std::cout << "Copy WrongAnimal constructor called!" << std::endl;
  *this = src;
}

WrongAnimal::~WrongAnimal() {

  std::cout << "Default WrongAnimal destructor called!" << std::endl;
}

void WrongAnimal::makeSound() const {

  std::cout << "*WrongAnimal sound!*" << std::endl;
}

std::string WrongAnimal::getType() const { return type; }

// protected -------------------------------------------------------------------
// std::string type;
