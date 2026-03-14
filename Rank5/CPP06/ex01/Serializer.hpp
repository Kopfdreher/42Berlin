#ifndef SERIALIZER_H
#define SERIALIZER_H

#include "defines.hpp"
#include <stdint.h>

struct Data;

class Serializer {

public:
  static uintptr_t serialize(Data *ptr);
  static Data *deserialize(uintptr_t raw);

private:
  Serializer();                              // empty constructor
  Serializer(Serializer const &);            // copy constructor
  Serializer &operator=(Serializer const &); // copy assignment operator
  ~Serializer();                             // destructor
};

#endif
