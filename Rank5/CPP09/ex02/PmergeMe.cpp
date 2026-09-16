#include "PmergeMe.hpp"

// public ----------------------------------------------------------------------

PmergeMe::PmergeMe() {}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs) {

  if (this != &rhs) {}
  return *this;
}

PmergeMe::PmergeMe(PmergeMe const &src) {

  *this = src;
}

PmergeMe::~PmergeMe() {}

// private ---------------------------------------------------------------------
