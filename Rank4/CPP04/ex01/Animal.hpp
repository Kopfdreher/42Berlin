#ifndef ANIMAL_H
#define ANIMAL_H

#include "Brain.hpp"
#include <string>

class Animal {

public:
  Animal(); // empty constructor
  Animal(Animal const &); // copy constructor
  Animal &operator=(Animal const &); // copy assignment operator
  virtual ~Animal(); // destructor

  virtual void makeSound() const ;
  std::string getType() const ;

protected:
  Animal(std::string t);
  std::string type;

};

#endif
