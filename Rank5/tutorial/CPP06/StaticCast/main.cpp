#include <iostream>

class Parent {};
class Child1 : public Parent {};
class Child2 : public Parent {};
class Unrelated {};

int main() {
  Child1 a;                             // reference value

  Parent *b = &a;                       // implicit upcast -> ok
  Child1 *c = b;                        // implicit downcast -> hell, no
  Child2 *d = static_cast<Child2 *>(b); // explicit downcast -> ok, i obey

  Unrelated *e = static_cast<Unrelated *>(&a); // explicit converion -> no!
}

/* with ints and doubles
int main() {
  int a = 42;                  // reference value

  double b = a;                // implicit promotion -> ok
  int c = b;                   // implicit demotion -> hell, no
  int d = static_cast<int>(b); // explicit demotion -> ok, I obey
}
*/
