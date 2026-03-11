#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {

  // too low / high form grade
  try {
    Form form("vip-form", 151, 1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Form form("vip-form", 1, -1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }

  // correct form construction
  Form form1;
  Form form2("vip-form", 1, 1);
  std::cout << form1 << std::endl;
  std::cout << form2 << std::endl;

  // signing forms
  try {
    Bureaucrat employee0("test", 150);
    employee0.signForm(form1);
    employee0.signForm(form2);
    std::cout << employee0 << std::endl;
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Bureaucrat employee2("too high", -1);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
  try {
    Bureaucrat employee1("too low", 151);
  } catch (std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
}
