#ifndef SPAN_H
#define SPAN_H

#include <set>
#include <stdexcept>

class Span {

public:
  Span(unsigned int N);
  Span(Span const &);            // copy constructor
  Span &operator=(Span const &); // copy assignment operator
  ~Span();                       // destructor

  // Methods

  void addNumber(int num);
  unsigned int shortestSpan();
  unsigned int longestSpan();

  template <typename InputIterator>
  void addNumber(InputIterator first, InputIterator last) {
    if (static_cast<unsigned int>(std::distance(first, last)) >
        _N - _container.size())
      throw LimitReachedException();
    _container.insert(first, last);
  }

  // Exceptions

  class LimitReachedException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Error: Number cannot be added, limit reached";
    }
  };

  class NoSpanFoundException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Error: No Span can be found";
    }
  };

private:
  std::multiset<int> _container;
  unsigned int _N;

  Span(); // empty constructor
};

#endif
