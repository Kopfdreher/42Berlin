#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <stack>

template <typename T>
class MutantStack : public std::stack<T> {

public:
  MutantStack();                               // empty constructor
  MutantStack(MutantStack const &);            // copy constructor
  MutantStack &operator=(MutantStack const &); // copy assignment operator
  ~MutantStack();                              // destructor

  // Methods
  



private:
};

#endif
