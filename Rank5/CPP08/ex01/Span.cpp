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

  unsigned int shortest = std::numeric_limits<unsigned int>::max();

  std::multiset<int>::iterator current = _container.begin();
  std::multiset<int>::iterator next = current;
  ++next;

  while (next != _container.end()) {
    unsigned int diff = static_cast<unsigned int>(*next - *current);
    shortest = std::min(shortest, diff);
    ++current;
    ++next;
  }
  return shortest;
}

unsigned int Span::longestSpan() {
  if (_container.size() <= 1)
    throw NoSpanFoundException();
  return static_cast<unsigned int>(*_container.rbegin() - *_container.begin());
}

// private ---------------------------------------------------------------------
// std::multiset<int> _container;
// unsigned int _N;

Span::Span() {}
