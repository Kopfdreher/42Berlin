#ifndef AForm_H
#define AForm_H

#include "Bureaucrat.hpp"
#include <iostream>
#include <stdexcept>
#include <string>

class Bureaucrat;

class AForm {

public:
  AForm(std::string const &name, int gradeSign, int gradeExecute);
  AForm();                         // empty constructor
  AForm(AForm const &);            // copy constructor
  AForm &operator=(AForm const &); // copy assignment operator
  ~AForm();                        // destructor

  // Methods

  std::string const &getName() const;
  bool getIsSigned() const;
  int getGradeSign() const;
  int getGradeExecute() const;
  void beSigned(Bureaucrat const &signer);

  void execute(Bureaucrat const & executor) const;

  // Exceptions

  class MissingSignException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Error: Missing Sign"; }
  };

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Error: Grade too high"; }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Error: Grade too low"; }
  };

protected:
  virtual void executeAction() const = 0;

private:
  std::string const _name;
  bool _isSigned;
  int const _gradeSign;
  int const _gradeExecute;
};

std::ostream &operator<<(std::ostream &o, AForm const &rhs);

#endif
