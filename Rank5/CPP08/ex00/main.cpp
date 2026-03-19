#include "easyfind.hpp"
#include <iostream>
#include <list>
#include <vector>

int main() {
  std::cout << "\nIterate through Int-List" << std::endl;
  try {
    std::list<int> lst;

    lst.push_back(10);
    lst.push_back(23);
    lst.push_back(3);
    lst.push_back(17);
    lst.push_back(20);

    std::list<int>::iterator it1 = easyfind(lst, 3);
    std::cout << "*it: " << *it1 << std::endl;
    std::list<int>::iterator it2 = easyfind(lst, 42);
    std::cout << "*it: " << *it2 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  std::cout << "\nIterate through Vector-List" << std::endl;
  try {
    std::vector<int> vec;

    vec.push_back(10);
    vec.push_back(23);
    vec.push_back(3);
    vec.push_back(17);
    vec.push_back(20);

    std::vector<int>::iterator it1 = easyfind(vec, 3);
    std::cout << "*it: " << *it1 << std::endl;
    std::vector<int>::iterator it2 = easyfind(vec, 42);
    std::cout << "*it: " << *it2 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
