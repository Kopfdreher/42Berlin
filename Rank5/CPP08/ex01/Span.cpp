#include "Span.hpp"
#include <algorithm>
#include <iterator>
#include <limits>
#include <numeric>

// public ----------------------------------------------------------------------

Span::Span(unsigned int N) : _N(N) {}

Span &Span::operator=(Span const &rhs) {
  if (this != &rhs) {
    _container = rhs._container;
    _N = rhs._N;
  }
  return *this;
}

Span::Span(Span const &src) { *this = src; }

Span::~Span() {}

// Methods

void Span::addNumber(int num) {
  if (_N > _container.size())
    _container.insert(num);
  else
    throw LimitReachedException();
}

unsigned int Span::shortestSpan() {
  if (_container.size() <= 1)
    throw NoSpanFoundException();

  unsigned int shortest;
  unsigned int current;
  std::multiset<int>::iterator it;
  std::multiset<int>::iterator next;
  std::multiset<int>::iterator secondLast = _container.end()--;

  shortest = std::numeric_limits<unsigned int>::max();
  for (it = _container.begin(); it != secondLast; it++) {
    next = it;
    next++;
    current = *next - *it;
    shortest = std::min(shortest, current);
  }
  return shortest;
}

unsigned int Span::longestSpan() {
  if (_container.size() <= 1)
    throw NoSpanFoundException();

  return (*(std::max_element(_container.begin(), _container.end())) -
          *(std::min_element(_container.begin(), _container.end())));
}

// private ---------------------------------------------------------------------
// std::multiset<int> _container;
// unsigned int _N;

Span::Span() {}
