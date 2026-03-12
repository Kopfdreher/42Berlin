#include <iostream>

class A {};
class B {};

class C {

public:
  C(A const &_) { return; }
  explicit C(B const &_) { return; } // allows to prevent the implicit usage of the constructor as a converter
};

void f(C onst &_) { return; }

int main() {
  f(A()); // Implicit conversion OK
  f(B()); // Implicit conversion NOT OK, constructor is explicit
}

/*
The Core Concept: Conversion Constructors

In C++, any constructor that can be called with a single argument acts as a "conversion constructor" by default. It tells the compiler: "Hey, if you ever have this single argument type but you actually need my class type, you can use me to automatically convert it."
*/
