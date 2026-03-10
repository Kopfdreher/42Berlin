#include "Bureaucrat.hpp"
#include "Form.hpp"
#include <iostream>

int main() {
  Form form1;
  Form form2("vip-form", 1, 1);
  std::cout << form1 << std::endl;
  try {
    Bureaucrat employee0("test", 150);
    employee0.signForm(form1);
    employee0.signForm(form2);

    std::cout << employee0 << std::endl;
    Bureaucrat employee1("too low", 151);
    Bureaucrat employee2("too high", -1);
  } catch (Bureaucrat::GradeTooLowException &e) {
    std::cerr << e.what() << std::endl;
  } catch (Bureaucrat::GradeTooHighException &e) {
    std::cerr << e.what() << std::endl;
  }
}
