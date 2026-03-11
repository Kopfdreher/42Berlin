#include "Form.hpp"

// public ----------------------------------------------------------------------

Form::Form()
    : _name("Generic"), _isSigned(false), _gradeSign(150), _gradeExecute(150) {}

Form::Form(std::string const &name, int gradeSign, int gradeExecute)
    : _name(name), _isSigned(false), _gradeSign(gradeSign),
      _gradeExecute(gradeExecute) {
  if (gradeSign > 150 || gradeExecute > 150)
    throw GradeTooLowException();
  if (gradeSign < 1 || gradeExecute < 1)
    throw GradeTooHighException();
}

Form &Form::operator=(Form const &rhs) {
  if (this != &rhs) {
    _isSigned = rhs.getIsSigned();
  }
  return *this;
}

Form::Form(Form const &src)
    : _name(src.getName()), _isSigned(src.getIsSigned()),
      _gradeSign(src.getGradeSign()), _gradeExecute(src.getGradeExecute()) {}

// Methods

std::string const &Form::getName() const { return _name; }

bool Form::getIsSigned() const { return _isSigned; }

int Form::getGradeSign() const { return _gradeSign; }

int Form::getGradeExecute() const { return _gradeExecute; }

void Form::beSigned(Bureaucrat const &signer) {
  if (signer.getGrade() > _gradeSign)
    throw GradeTooLowException();
  _isSigned = true;
}

Form::~Form() {}

// Insertion Operator

std::ostream &operator<<(std::ostream &o, Form const &rhs) {
  o << rhs.getName() << ", " << rhs.getIsSigned() << ", " << rhs.getGradeSign()
    << ", " << rhs.getGradeExecute();
  return o;
}

// private ---------------------------------------------------------------------

// std::string const _name;
// bool _isSigned;
// int const _gradeSign;
// int const _gradeExecute;
