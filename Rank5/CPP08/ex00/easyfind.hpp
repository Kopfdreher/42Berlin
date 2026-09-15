#ifndef EASYFIND_H
#define EASYFIND_H

#include <algorithm>
#include <stdexcept>

template <typename T> typename T::iterator easyfind(T &container, int i) {
  typename T::iterator it = std::find(container.begin(), container.end(), i);
  if (it == container.end())
    throw std::runtime_error("Value not found");
  return (it);
}

template <typename T> typename T::const_iterator easyfind(const T &container, int i) {
  typename T::const_iterator it = std::find(container.begin(), container.end(), i);
  if (it == container.end())
    throw std::runtime_error("Value not found");
  return (it);
}

#endif
