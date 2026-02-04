#include "Point.hpp"
#include <iostream>

bool bsp(Point const a, Point const b, Point const c, Point const point);

void test(std::string name, Point const a, Point const b, Point const c,
          Point const p, bool expected) {
  bool result = bsp(a, b, c, p);

  std::cout << "Test: " << name << std::endl;
  std::cout << "  Point: (" << p.getX().toFloat() << ", " << p.getY().toFloat()
            << ")" << std::endl;
  std::cout << "  Result: " << (result ? "INSIDE" : "OUTSIDE") << std::endl;

  if (result == expected)
    std::cout << "  Status: \033[1;32m[OK]\033[0m" << std::endl;
  else
    std::cout << "  Status: \033[1;31m[FAIL]\033[0m (Expected "
              << (expected ? "INSIDE" : "OUTSIDE") << ")" << std::endl;
  std::cout << "-----------------------------------" << std::endl;
}

int main(void) {
  // A(0,0)
  // |     \
  // |      \
  // C(0,5)__B(5,0)

  Point a(0.0f, 0.0f);
  Point b(5.0f, 0.0f);
  Point c(0.0f, 5.0f);

  std::cout << "Triangle Vertices: A(0,0), B(5,0), C(0,5)" << std::endl;
  std::cout << "-----------------------------------" << std::endl;

  test("Clearly Inside", a, b, c, Point(1.0f, 1.0f), true);

  test("Clearly Outside", a, b, c, Point(10.0f, 10.0f), false);

  test("Vertex (Corner A)", a, b, c, Point(0.0f, 0.0f), false);

  test("On Edge (A -> C)", a, b, c, Point(0.0f, 2.5f), false);

  test("On Diagonal Edge (B -> C)", a, b, c, Point(2.5f, 2.5f), false);

  test("Barely Outside", a, b, c, Point(2.51f, 2.51f), false);

  test("Barely Inside", a, b, c, Point(2.49f, 2.49f), true);

  return 0;
}
