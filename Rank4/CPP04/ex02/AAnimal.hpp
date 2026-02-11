#ifndef AANIMAL_H
#define AANIMAL_H

#include "Brain.hpp"
#include <string>

class AAnimal {

public:
  AAnimal(); // empty constructor
  AAnimal(AAnimal const &); // copy constructor
  AAnimal &operator=(AAnimal const &); // copy assignment operator
  virtual ~AAnimal(); // destructor

  virtual void makeSound() const = 0;
  std::string getType() const ;

protected:
  AAnimal(std::string t);
  std::string type;

};

#endif
