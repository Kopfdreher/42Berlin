#include "MutantStack.hpp"
#include <iostream>
#include <list>

int main() {
  {
    std::cout << "\n--- MutantStack ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << ".top(): " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << ".size(): " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
  }
  {
    std::cout << "\n--- MutantStack (reverse) ---" << std::endl;
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << ".top(): " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << ".size(): " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    MutantStack<int>::reverse_iterator rit = mstack.rbegin();
    MutantStack<int>::reverse_iterator rite = mstack.rend();
    ++rit;
    --rit;
    while (rit != rite) {
      std::cout << *rit << std::endl;
      ++rit;
    }
  }
  {
    std::cout << "\n--- List ---" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << ".back(): " << list.back() << std::endl;
    list.pop_back();
    std::cout << ".size(): " << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::iterator it = list.begin();
    std::list<int>::iterator ite = list.end();
    ++it;
    --it;
    while (it != ite) {
      std::cout << *it << std::endl;
      ++it;
    }
  }
  {
    std::cout << "\n--- List (reverse) ---" << std::endl;
    std::list<int> list;
    list.push_back(5);
    list.push_back(17);
    std::cout << ".back(): " << list.back() << std::endl;
    list.pop_back();
    std::cout << ".size(): " << list.size() << std::endl;
    list.push_back(3);
    list.push_back(5);
    list.push_back(737);
    list.push_back(0);
    std::list<int>::reverse_iterator rit = list.rbegin();
    std::list<int>::reverse_iterator rite = list.rend();
    ++rit;
    --rit;
    while (rit != rite) {
      std::cout << *rit << std::endl;
      ++rit;
    }
  }
}
