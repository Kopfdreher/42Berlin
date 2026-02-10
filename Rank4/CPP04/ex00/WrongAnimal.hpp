#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <string>

class WrongAnimal {

public:
  WrongAnimal(); // empty constructor
  WrongAnimal(Animal const &); // copy constructor
  WrongAnimal &operator=(Animal const &); // copy assignment operator
  virtual ~WrongAnimal(); // destructor

  virtual void makeSound() const ;
  std::string getType() const ;

protected:
  WrongAnimal(std::string t);
  std::string type;

};

#endif
