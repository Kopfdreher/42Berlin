#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T> class MutantStack : public std::stack<T> {

public:
  typedef typename std::stack<T>::container_type::iterator iterator;
  typedef typename std::stack<T>::container_type::const_iterator const_iterator;
  typedef
      typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
  typedef typename std::stack<T>::container_type::const_reverse_iterator
      const_reverse_iterator;

  // OCF
  MutantStack();                                  // empty constructor
  MutantStack(MutantStack<T> const &);            // copy constructor
  MutantStack &operator=(MutantStack<T> const &); // copy assignment operator
  ~MutantStack();                                 // destructor

  // Methods
  iterator begin();
  iterator end();
  const_iterator begin() const;
  const_iterator end() const;
  reverse_iterator rbegin();
  reverse_iterator rend();
  const_reverse_iterator rbegin() const;
  const_reverse_iterator rend() const;

private:
};

#include "MutantStack.tpp"

#endif
