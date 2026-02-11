#ifndef WRONG_CAT_H
#define WRONG_CAT_H

#include "WrongAnimal.hpp"
#include <string>

class WrongCat : virtual public WrongAnimal {

public:
  WrongCat(); // empty constructor
  WrongCat(WrongCat const &); // copy constructor
  WrongCat &operator=(WrongCat const &); // copy assignment operator
  ~WrongCat(); // destructor

  void makeSound() const ;

};

#endif
