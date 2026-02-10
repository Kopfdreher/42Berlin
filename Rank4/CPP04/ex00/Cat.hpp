#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include <string>

class Cat : virtual public Animal {

public:
  Cat(); // empty constructor
  Cat(Cat const &); // copy constructor
  Cat &operator=(Cat const &); // copy assignment operator
  ~Cat(); // destructor

  virtual void makeSound() const ;

};

#endif
