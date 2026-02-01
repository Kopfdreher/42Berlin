#include <iostream>
#include <string>

class FirstClass {
public:
	FirstClass();
	~FirstClass();

  static void print(std::string txt) {
    std::cout << "FirstClass: " << txt << std::endl;
  }
};

class SecondClass {
public:
  SecondClass();
  ~SecondClass();

  static void print(void) {
		std::cout << "SecondClass: No text" << std::endl;
	}
};

int main(void) {
  SecondClass::print();
  FirstClass::print("My test");
  return (0);
}
