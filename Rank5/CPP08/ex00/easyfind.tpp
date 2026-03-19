#ifndef EASYFIND_TPP
#define EASYFIND_TPP

#include "easyfind.hpp"
#include <algorithm>

template <typename T> typename T::iterator easyfind(T &container, int i) {
  typename T::iterator it;

  it = std::find(container.begin(), container.end(), i);
  if (it == container.end())
    throw NotFoundException();
  return (it);
}

#endif

/*
 * my own find algo
for (it = container.begin(); it != ite; ++it) {
  if (i == *it)
    return it;
}
*/
