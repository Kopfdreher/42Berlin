#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>

// public ----------------------------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm(std::string const &target)
    : AForm("RobotomyRequestForm", 72, 45), _target(target) {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
    _target = rhs._target;
  }
  return *this;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src)
    : AForm(src), _target(src._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

void RobotomyRequestForm::executeAction() const {
  std::cout << "Bzzztt! Ddddrrrrllll!!!" << std::endl;
  if (std::rand() < RAND_MAX / 2)
    std::cout << _target << " has been robotomized successfully" << std::endl;
  else
    std::cout << "The robotomy failed" << std::endl;
}

// private ---------------------------------------------------------------------

RobotomyRequestForm::RobotomyRequestForm() {}

// std::string const _name;
// bool _isSigned;
// int const _gradeSign;
// int const _gradeExecute;
