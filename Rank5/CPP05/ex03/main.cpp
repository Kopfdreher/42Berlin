#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <cstdlib>
#include <ctime>
#include <iostream>

int main() {
  std::srand(std::time(NULL));
  {
  }
  std::cout << "\nTEST 1: The CEO (Grade 1)" << std::endl;
  {
    AForm *robotomy = NULL;
    AForm *pardon = NULL;
    AForm *shrubbery = NULL;
    AForm *test = NULL;
    try {
      Intern someRandomIntern;
      Bureaucrat Bert("Bert", 1);
      robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
      pardon = someRandomIntern.makeForm("presidential pardon", "Person");
      shrubbery = someRandomIntern.makeForm("shrubbery creation", "Bert");
      test = someRandomIntern.makeForm("test", "test");
      Bert.signAForm(*shrubbery);
      Bert.executeForm(*shrubbery);
      Bert.signAForm(*robotomy);
      Bert.executeForm(*robotomy);
      Bert.signAForm(*pardon);
      Bert.executeForm(*pardon);
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    delete robotomy;
    delete pardon;
    delete shrubbery;
    delete test;
  }
  std::cout << "\nTEST 2: The Employee (Grade 150)" << std::endl;
  {
    AForm *robotomy = NULL;
    AForm *pardon = NULL;
    AForm *shrubbery = NULL;
    AForm *test = NULL;
    try {
      Intern someRandomIntern;
      Bureaucrat Bert("Bert", 150);
      robotomy = someRandomIntern.makeForm("robotomy request", "Bender");
      pardon = someRandomIntern.makeForm("presidential pardon", "Person");
      shrubbery = someRandomIntern.makeForm("shrubbery creation", "Bert");
      test = someRandomIntern.makeForm("test", "test");
      Bert.signAForm(*shrubbery);
      Bert.executeForm(*shrubbery);
      Bert.signAForm(*robotomy);
      Bert.executeForm(*robotomy);
      Bert.signAForm(*pardon);
      Bert.executeForm(*pardon);
    } catch (std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
    delete robotomy;
    delete pardon;
    delete shrubbery;
    delete test;
  }
}
