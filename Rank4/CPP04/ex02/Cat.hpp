#ifndef CAT_H
#define CAT_H

#include "Brain.hpp"
#include "AAnimal.hpp"
#include <string>

class Cat : virtual public AAnimal {

public:
  Cat(); // empty constructor
  Cat(Cat const &); // copy constructor
  Cat &operator=(Cat const &); // copy assignment operator
  ~Cat(); // destructor

  virtual void makeSound() const ;

private:
  Brain *brain;

};

#endif
