#include "WrongCat.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

WrongCat::WrongCat() : WrongAnimal("WrongCat") {

  std::cout << "Default WrongCat constructor called!" << std::endl;
}

WrongCat &WrongCat::operator=(WrongCat const &rhs) {

  std::cout << "Copy WrongCat assignment operator called!" << std::endl;
  if (this != &rhs) {
    type = rhs.type;
  }
  return *this;
}

WrongCat::WrongCat(WrongCat const &src) {

  std::cout << "Copy WrongCat constructor called!" << std::endl;
  *this = src;
}

WrongCat::~WrongCat() { std::cout << "Default WrongCat destructor called!" << std::endl; }

void WrongCat::makeSound() const { std::cout << "*Miauuu!*" << std::endl; }

// protected -------------------------------------------------------------------
// std::string type;
