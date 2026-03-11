#ifndef ROBOTOMYREQUESTFORM_H
#define ROBOTOMYREQUESTFORM_H

#include "AForm.hpp"
#include <string>

class RobotomyRequestForm : virtual public AForm {

public:
  RobotomyRequestForm(std::string const &target);     // empty constructor
  RobotomyRequestForm(RobotomyRequestForm const &); // copy constructor
  RobotomyRequestForm &
  operator=(RobotomyRequestForm const &); // copy assignment operator
  ~RobotomyRequestForm();                 // destructor

  // Exceptions

  class FileNotOpenException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Error: Could not open output file";
    }
  };

protected:
  void executeAction() const;

private:
  std::string _target;
  RobotomyRequestForm(); // empty constructor
};

#endif
