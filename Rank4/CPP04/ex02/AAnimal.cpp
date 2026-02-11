#include "AAnimal.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

AAnimal::AAnimal() : type("AAnimal") {

  std::cout << "Default AAnimal constructor called!" << std::endl;
}

AAnimal::AAnimal(std::string t) : type(t) {

  std::cout << "AAnimal of type " << t << " constructor called!" << std::endl;
}

AAnimal &AAnimal::operator=(AAnimal const &rhs) {

  std::cout << "Copy AAnimal assignment operator called!" << std::endl;
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}

AAnimal::AAnimal(AAnimal const &src) {

  std::cout << "Copy AAnimal constructor called!" << std::endl;
  *this = src;
}

AAnimal::~AAnimal() { std::cout << "Default AAnimal destructor called!" << std::endl; }

std::string AAnimal::getType() const { return type; }

// protected -------------------------------------------------------------------
// std::string type;
