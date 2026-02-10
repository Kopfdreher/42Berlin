#ifndef WRONG_CAT_H
#define WRONG_CAT_H

#include "Animal.hpp"
#include <string>

class WrongCat : virtual public Animal {

public:
  WrongCat(); // empty constructor
  WrongCat(WrongCat const &); // copy constructor
  WrongCat &operator=(WrongCat const &); // copy assignment operator
  ~WrongCat(); // destructor

  virtual void makeSound() const ;

};

#endif
