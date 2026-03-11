#include "AForm.hpp"

// public ----------------------------------------------------------------------

AForm::AForm()
    : _name("Generic"), _isSigned(false), _gradeSign(150), _gradeExecute(150) {}

AForm::AForm(std::string const &name, int gradeSign, int gradeExecute)
    : _name(name), _isSigned(false), _gradeSign(gradeSign),
      _gradeExecute(gradeExecute) {
  if (gradeSign > 150 || gradeExecute > 150)
    throw GradeTooLowException();
  if (gradeSign < 1 || gradeExecute < 1)
    throw GradeTooHighException();
}

AForm &AForm::operator=(AForm const &rhs) {
  if (this != &rhs) {
    _isSigned = rhs.getIsSigned();
  }
  return *this;
}

AForm::AForm(AForm const &src)
    : _name(src.getName()), _isSigned(src.getIsSigned()),
      _gradeSign(src.getGradeSign()), _gradeExecute(src.getGradeExecute()) {}

// Methods

std::string const &AForm::getName() const { return _name; }

bool AForm::getIsSigned() const { return _isSigned; }

int AForm::getGradeSign() const { return _gradeSign; }

int AForm::getGradeExecute() const { return _gradeExecute; }

void AForm::beSigned(Bureaucrat const &signer) {
  if (signer.getGrade() > _gradeSign)
    throw GradeTooLowException();
  _isSigned = true;
}

void AForm::execute(Bureaucrat const &executor) const {
  if (_isSigned == false)
    throw MissingSignException();
  if (executor.getGrade() > _gradeExecute)
    throw GradeTooLowException();
  this->executeAction();
}

AForm::~AForm() {}

// Insertion Operator

std::ostream &operator<<(std::ostream &o, AForm const &rhs) {
  o << rhs.getName() << ", " << rhs.getIsSigned() << ", " << rhs.getGradeSign()
    << ", " << rhs.getGradeExecute();
  return o;
}

// private ---------------------------------------------------------------------

// std::string const _name;
// bool _isSigned;
// int const _gradeSign;
// int const _gradeExecute;
