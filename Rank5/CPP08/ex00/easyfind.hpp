#ifndef EASYFIND_H
#define EASYFIND_H

#include <stdexcept>

class NotFoundException : public std::exception {
public:
  virtual const char *what() const throw() { return "Error: Value not found"; }
};

#include "easyfind.tpp"

#endif
