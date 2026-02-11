#ifndef BRAIN_H
#define BRAIN_H

#include <string>

class Brain {

public:
  Brain(); // empty constructor
  Brain(Brain const &); // copy constructor
  Brain &operator=(Brain const &); // copy assignment operator
  ~Brain(); // destructor

  std::string ideas[100];

};

#endif
