#ifndef DOG_H
#define DOG_H

#include "Animal.hpp"
#include <string>

class Dog : virtual public Animal {

public:
  Dog(); // empty constructor
  Dog(Dog const &); // copy constructor
  Dog &operator=(Dog const &); // copy assignment operator
  ~Dog(); // destructor

  virtual void makeSound() const ;

};

#endif
