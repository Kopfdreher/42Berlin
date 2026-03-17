#ifndef ITER_H
#define ITER_H

#include <cstddef>
#include <iostream>

template <typename T, typename F>
void iter(T *arr, std::size_t const len, F func) {
  for (size_t i = 0; i < len; i++) {
    func(arr[i]);
  }
}

template <typename T>
void add(T &x) {
  x++;
}

template <typename T>
void print(T const &x) {
  std::cout << x << " ";
}

template <typename T>
void printArr(T *arr, std::size_t const len) {
  iter<T>(arr, len, print<T>);
  std::cout << std::endl;
}

#endif
