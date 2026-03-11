#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <string>

// public ----------------------------------------------------------------------

Intern::Intern() {}

Intern &Intern::operator=(Intern const &rhs) {
  (void)rhs;
  return *this;
}

Intern::Intern(Intern const &src) { (void)src; }

Intern::~Intern() {}

AForm *Intern::makeRobotomyRequest(std::string target) {
  return new RobotomyRequestForm(target);
}

AForm *Intern::makePresidentialPardon(std::string target) {
  return new PresidentialPardonForm(target);
}

AForm *Intern::makeShrubberyCreation(std::string target) {
  
  return new ShrubberyCreationForm(target);
}

AForm *Intern::makeForm(std::string formType, std::string target) {
  std::string types[] = {"robotomy request", "presidential pardon",
                         "shrubbery creation"};
  AForm *(Intern::*function[])(std::string) = {&Intern::makeRobotomyRequest,
                                             &Intern::makePresidentialPardon,
                                             &Intern::makeShrubberyCreation};
  for (int i = 0; i < 3; i++) {
    if (types[i] == formType) {
      std::cout << "Intern creates " << target << " of type: " << formType
                << std::endl;
      return (this->*function[i])(target);
    }
  }
  std::cerr << "Error: invalid form type" << std::endl;
  return NULL;
}
