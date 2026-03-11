#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(std::time(NULL));
  std::cout << "\nTEST 1: The CEO (Grade 1)" << std::endl;
  {
    try {
      Bureaucrat Bert("Bert", 1);
      ShrubberyCreationForm shrubbery("Shrubbery");
      Bert.signAForm(shrubbery);
      Bert.executeForm(shrubbery);
      RobotomyRequestForm robotomy("Robotomy");
      Bert.signAForm(robotomy);
      Bert.executeForm(robotomy);
      PresidentialPardonForm pardon("Person");
      Bert.signAForm(pardon);
      Bert.executeForm(pardon);
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
  std::cout << "\nTEST 2: The Employee (Grade 150)" << std::endl;
  {
    try {
      Bureaucrat Bert("Bert", 150);
      ShrubberyCreationForm shrubbery("Shrubbery");
      Bert.signAForm(shrubbery);
      Bert.executeForm(shrubbery);
      RobotomyRequestForm robotomy("Robotomy");
      Bert.signAForm(robotomy);
      Bert.executeForm(robotomy);
      PresidentialPardonForm pardon("Person");
      Bert.signAForm(pardon);
      Bert.executeForm(pardon);

    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }
}
