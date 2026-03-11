#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include "AForm.hpp"
#include <string>

class PresidentialPardonForm : virtual public AForm {

public:
  PresidentialPardonForm(std::string const &target);     // empty constructor
  PresidentialPardonForm(PresidentialPardonForm const &); // copy constructor
  PresidentialPardonForm &
  operator=(PresidentialPardonForm const &); // copy assignment operator
  ~PresidentialPardonForm();                 // destructor

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
  PresidentialPardonForm(); // empty constructor
};

#endif
