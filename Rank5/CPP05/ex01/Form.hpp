#ifndef Form_H
#define Form_H

#include "Bureaucrat.hpp"
#include <stdexcept>
#include <string>
#include <iostream>

class Bureaucrat;

class Form {

public:
  Form(); // empty constructor
  Form(std::string const &name, int gradeSign, int gradeExecute);
  Form(Form const &);            // copy constructor
  Form &operator=(Form const &); // copy assignment operator
  ~Form();                       // destructor

  // Methods
  std::string const &getName() const;
  bool getIsSigned() const;
  int getGradeSign() const;
  int getGradeExecute() const;

  void beSigned(Bureaucrat const &signer);

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Error: Grade too low"; }
  };

private:
  std::string const _name;
  bool _isSigned;
  int const _gradeSign;
  int const _gradeExecute;
};

std::ostream &operator<<(std::ostream &o, Form const &rhs);

#endif
