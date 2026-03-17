#ifndef ARRAY_T
#define ARRAY_T

#include "Array.hpp"

template <typename T> Array<T>::Array() : _arr(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int len) : _arr(new T[len]()), _size(len) {}

template <typename T> Array<T>::Array(int len) : _size(len) {
  if (len < 0)
    throw std::out_of_range("Error: Array-Length out of bounds");
  _arr = new T[len]();
}

template <typename T>
Array<T>::Array(Array const &src) : _arr(NULL), _size(src._size) {
  *this = src;
}

template <typename T> Array<T>::~Array() { delete[] _arr; }

template <typename T> Array<T> &Array<T>::operator=(Array const &rhs) {
  if (this != &rhs) {
    _size = rhs._size;
    delete[] _arr;
    _arr = new T[_size];
    for (unsigned int i = 0; i < _size; i++) {
      _arr[i] = rhs._arr[i];
    }
  }
  return *this;
}

template <typename T> T &Array<T>::operator[](unsigned int i) {
  if (i >= _size)
    throw std::out_of_range("Error: Index out of bounds");
  return _arr[i];
}

template <typename T> T &Array<T>::operator[](int i) {
  if (static_cast<unsigned int>(i) >= _size || i < 0)
    throw std::out_of_range("Error: Index out of bounds");
  return _arr[i];
}

template <typename T> unsigned int Array<T>::size() const { return _size; }

#endif
