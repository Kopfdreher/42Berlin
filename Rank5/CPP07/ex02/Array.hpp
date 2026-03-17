#ifndef ARRAY_H
#define ARRAY_H

#include <stdexcept>

template <typename T> class Array {

public:
  Array();              // empty constructor
  Array(Array const &); // copy constructor
  Array(unsigned int len);
  Array(int len);
  ~Array(); // destructor

  Array &operator=(Array const &); // copy assignment operator
  T &operator[](unsigned int i);
  T &operator[](int i);

  unsigned int size() const;

private:
  T *_arr;
  unsigned int _size;
};

#include "Array.tpp"

#endif
