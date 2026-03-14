#include "A.hpp"
#include "B.hpp"
#include "Base.hpp"
#include "C.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

Base *generate(void) {
  int random = std::rand() % 3;

  if (random == 0) {
    std::cout << "A generated." << std::endl;
    return new A();
  }
  if (random == 1) {
    std::cout << "B generated." << std::endl;
    return new B();
  }
  if (random == 2) {
    std::cout << "C generated." << std::endl;
    return new C();
  }
  return NULL;
}

void identify(Base *p) {
  if (dynamic_cast<A *>(p))
    std::cout << "A identified with pointer." << std::endl;
  else if (dynamic_cast<B *>(p))
    std::cout << "B identified with pointer." << std::endl;
  else if (dynamic_cast<C *>(p))
    std::cout << "C identified with pointer." << std::endl;
  else
    std::cerr << "Error: Invalid-Type." << std::endl;
}

void identify(Base &p) {
  try {
    (void)dynamic_cast<A &>(p);
    std::cout << "A identified with reference." << std::endl;
    return;
  } catch (const std::exception &e) {
  }
  try {
    (void)dynamic_cast<B &>(p);
    std::cout << "B identified with reference." << std::endl;
    return;
  } catch (const std::exception &e) {
  }
  try {
    (void)dynamic_cast<C &>(p);
    std::cout << "C identified with reference." << std::endl;
    return;
  } catch (const std::exception &e) {
  }
  std::cerr << "Error: Invalid-Type." << std::endl;
  return;
}

int main() {
  std::srand(std::time(NULL));
  Base *test;
  for (int i = 0; i < 10; i++) {
    std::cout << "\n------ Object " << i << " ------" << std::endl;
    test = generate();
    identify(test);
    identify(*test);
    delete test;
  }
}
