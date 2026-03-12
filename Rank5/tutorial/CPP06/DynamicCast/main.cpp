#include <exception>
#include <iostream>
#include <typeinfo>

class Parent {
public:
  virtual ~Parent() {}
};
class Child1 : public Parent {};
class Child2 : public Parent {};

int main() {
  Child1 a;       // Reference value
  Parent *b = &a; // Implicit upcast -> Ok

  // Explicit downcast -> Suspens...
  Child1 *c = dynamic_cast<Child1 *>(b);
  if (c == NULL) {
    std::cout << "Conversion is NOT Ok" << std::endl;
  } else {
    std::cout << "Conversion is Ok" << std::endl;
  }

  // Explicit downcast -> Suspens...
  try {
    Child2 &d = dynamic_cast<Child2 &>(*b);
    std::cout << "Conversion is Ok" << std::endl;
  }
  catch (std::bad_cast &bc) {
    std::cout << "Conversion is NOT Ok: " << bc.what() << std::endl;
  }
}
