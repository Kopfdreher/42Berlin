#include <stdio.h>

int main() {
  float a = 420.042f;   // reference value

  void *b = &a;         // implicit reinterpretation cast
  void *c = (void *)&a; // explicit reinterpretation cast

  void *d = &a;         // implicit promotion -> Ok
  int *e = d;           // implicit demotion -> Hazareous!!
  int *f = (int *)d;    // explicit demotion -> Ok, I obey

  printf("%p, %f\n", &a, a);

  printf("%p\n", b);
  printf("%p\n", c);

  printf("%p\n", d);
  printf("%p, %d\n", e, *e);
  printf("%p, %d\n", f, *f);
}
