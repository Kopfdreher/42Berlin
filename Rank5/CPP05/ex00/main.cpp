#include "Bureaucrat.hpp"
#include <iostream>

int main() {
  try {
    Bureaucrat employee0("test", 1);
    std::cout << employee0 << std::endl;
    Bureaucrat employee1("too low", 151);
    Bureaucrat employee2("too high", -1);
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  }
}
