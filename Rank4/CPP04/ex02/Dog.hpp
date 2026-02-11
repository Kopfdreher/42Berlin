#ifndef DOG_H
#define DOG_H

#include "Brain.hpp"
#include "AAnimal.hpp"
#include <string>

class Dog : virtual public AAnimal {

public:
  Dog(); // empty constructor
  Dog(Dog const &); // copy constructor
  Dog &operator=(Dog const &); // copy assignment operator
  ~Dog(); // destructor

  virtual void makeSound() const ;

private:
  Brain *brain;

};

#endif
