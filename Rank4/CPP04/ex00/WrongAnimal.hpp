#ifndef WRONG_ANIMAL_H
#define WRONG_ANIMAL_H

#include <string>

class WrongAnimal {

public:
  WrongAnimal(); // empty constructor
  WrongAnimal(WrongAnimal const &); // copy constructor
  WrongAnimal &operator=(WrongAnimal const &); // copy assignment operator
  ~WrongAnimal(); // destructor (missing virtual)

  void makeSound() const ; // (missing virtual)
  std::string getType() const ;

protected:
  WrongAnimal(std::string t);
  std::string type;

};

#endif
