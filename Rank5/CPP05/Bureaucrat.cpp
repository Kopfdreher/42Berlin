#include "Bureaucrat.hpp"

// public ----------------------------------------------------------------------

Bureaucrat::Bureaucrat(const std::string name, const int grade) : _name(name) {
  if (grade > 150 || grade < 1)

}

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &rhs) {
  if (this != &rhs) {
    _grade = rhs._grade;
  }
}

Bureaucrat::Bureaucrat(Bureaucrat const &src)
    : _name(src._name), _grade(src.grade) {
  *this = src;
}

Bureaucrat::~Bureaucrat() {}

// private ---------------------------------------------------------------------
//    std::string _name;
//    int _grade;

Bureaucrat::Bureaucrat() : _name("Generic"), _grade(150) {}
