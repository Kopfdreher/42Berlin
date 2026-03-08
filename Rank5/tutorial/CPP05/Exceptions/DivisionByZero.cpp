#include <iostream>
#include <stdexcept>

// 1. Define our custom exception inheriting from std::exception
class DivideByZeroException : public std::exception {
public:
  // Override the what() function.
  // The throw() tells the compiler this func itself won't throw exceptions
  virtual const char *what() const throw() {
    return "Math Error: Attempted to divide by zero!";
  }
};

// 2. A function that does the math and thorws if things go wrong
double divide(double numerator, double denominator) {
  if (denominator == 0) {
    throw DivideByZeroException(); // We throw our custom object here
  }
  return numerator / denominator;
}

int main() {
  std::cout << "--- Starting Calculator ---" << std::endl;

  try {
    std::cout << "Trying 10 /2..." << std::endl;
    std::cout << "Result: " << divide(10, 2) << std::endl;

    std::cout << "\nTrying 5 /0..." << std::endl;
    // This next line triggers the thorw. The code immediately stops here
    // and jumps to the catch block!
    std::cout << "Result: " << divide(5, 0) << std::endl;
    std::cout << "You will never see this line printed." << std::endl;
  }
  // 3. Catch most specific exceptions first, BY REFERENCE (&)
  catch (DivideByZeroException &e) {
    std::cerr << "Caught specific error: " << e.what() << std::endl;
  }
  // 4. Catch general exceptions last, BY REFERENCE (&)
  catch (std::exception &e) {
    std::cerr << "Caught general error: " << e.what() << std::endl;
  }
  std::cout << "\nProgram recovered and exits gracefully!" << std::endl;
  return 0;
}
