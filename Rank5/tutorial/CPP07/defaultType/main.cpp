#include "Vertex.class.tpp"
#include <iostream>

int main() {
  Vertex<int> v1(12, 23, 34);
  Vertex<> v2(12, 23, 34);

  std::cout << v1 << std::endl;
  std::cout << v2 << std::endl;
}
