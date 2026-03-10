#include "Bureaucrat.hpp"
#include <iostream>

// public ----------------------------------------------------------------------

Bureaucrat::Bureaucrat(const std::string &name, const int grade) : _name(name) {
  if (grade > 150)
    throw GradeTooLowException();
  if (grade < 1)
    throw GradeTooHighException();
  _grade = grade;
}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  if (this != &rhs)
    _grade = rhs._grade;
  return *this;
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : _name(src.getName()), _grade(src.getGrade()) {
  *this = src;
}

Bureaucrat::~Bureaucrat() {}

// Getters

std::string const & Bureaucrat::getName() const { return (_name); }

int Bureaucrat::getGrade() const { return (_grade); }

// Insertion Operator

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs) {
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
  return o;
}

// private ---------------------------------------------------------------------
//    std::string _name;
//    int _grade;

Bureaucrat::Bureaucrat() : _name("Generic"), _grade(150) {}
