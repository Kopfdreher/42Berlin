#include "PresidentialPardonForm.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

PresidentialPardonForm::PresidentialPardonForm(std::string const &target)
    : AForm("PresidentialPardonForm", 25, 5), _target(target) {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
    _target = rhs._target;
  }
  return *this;
}

PresidentialPardonForm::PresidentialPardonForm(
    PresidentialPardonForm const &src)
    : AForm(src), _target(src._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

void PresidentialPardonForm::executeAction() const {
  std::cout << _target << " has been pardoned by Zaphod Beeblebrox"
            << std::endl;
}

// private ---------------------------------------------------------------------

PresidentialPardonForm::PresidentialPardonForm() {}

// std::string const _name;
// bool _isSigned;
// int const _gradeSign;
// int const _gradeExecute;
