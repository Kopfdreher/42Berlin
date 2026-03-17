#include <iostream>

template <typename T> T const &max(T const &x, T const &y) {
  return (x >= y ? x : y);
}

int foo(int x) {
  std::cout << "Long computing time" << std::endl;
  return x;
}

int main(void) {
  int a = 21;
  int b = 42;

  printf("Max of %d and %d is %d\n", a, b, max<int>(a, b));
  printf("Max of %d and %d is %d\n", a, b, max(a, b));

  float c = -1.7f;
  float d = 4.2f;

  printf("Max of %f and %f is %f\n", c, d, max<float>(c, d));
  printf("Max of %f and %f is %f\n", c, d, max(c, d));

  char e = 'a';
  char f = 'z';

  printf("Max of %c and %c is %c\n", e, f, max<char>(e, f));
  printf("Max of %c and %c is %c\n", e, f, max(e, f));

  // BUT...
  printf("Max of %d and %d is %d\n", a, b, max<int>(foo(a), foo(b)));
  printf("Max of %d and %d is %d\n", a, b, max(foo(a), foo(b)));
}
