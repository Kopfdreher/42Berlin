#include "Bureaucrat.hpp"

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
    : _name(src.getName()), _grade(src.getGrade()) {}

Bureaucrat::~Bureaucrat() {}

// Methods

std::string const &Bureaucrat::getName() const { return _name; }

int Bureaucrat::getGrade() const { return _grade; }

void Bureaucrat::incrementGrade() {
  if (_grade - 1 < 1)
    throw GradeTooHighException();
  _grade--;
}

void Bureaucrat::decrementGrade() {
  if (_grade + 1 > 150)
    throw GradeTooLowException();
  _grade++;
}

void Bureaucrat::signAForm(AForm &form) {
  try {
    form.beSigned(*this);
    std::cout << _name << " signed " << form.getName() << std::endl;
  } catch (AForm::GradeTooLowException &e) {
    std::cerr << _name << " couldn't sign " << form.getName() << " because of "
              << e.what() << std::endl;
  }
}

void Bureaucrat::executeForm(AForm const &form) const {
  try {
    form.execute(*this);
    std::cout << _name << " executed " << form.getName() << std::endl;
  } catch (std::exception &e) {
    std::cerr << _name << " couldn't execute " << form.getName()
              << " because of " << e.what() << std::endl;
  }
}

// Insertion Operator

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs) {
  o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade() << ".";
  return o;
}

// private ---------------------------------------------------------------------
//    std::string _name;
//    int _grade;

Bureaucrat::Bureaucrat() : _name("Generic"), _grade(150) {}
