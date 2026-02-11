#include "Brain.hpp"
#include <iostream>
#include <string>

// public ----------------------------------------------------------------------

Brain::Brain() {

  std::cout << "Default Brain Constructor called!" << std::endl;
}

Brain &Brain::operator=(Brain const &rhs) {

  std::cout << "Brain-Copy assignment operator called!" << std::endl;
  int i;

  if (this != &rhs) {

    i = -1;
    while (++i < 100)
      ideas[i] = rhs.ideas[i];
  }
  return *this;
}

Brain::Brain(Brain const &src) {

  std::cout << "Brain Copy constructor called!" << std::endl;
  *this = src;
}

Brain::~Brain() {

  std::cout << "Brain Destructor called!" << std::endl;
}

// private ---------------------------------------------------------------------
