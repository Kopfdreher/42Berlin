#ifndef SHRUBBERYCREATIONFORM_H
#define SHRUBBERYCREATIONFORM_H

#include "AForm.hpp"
#include <string>

class ShrubberyCreationForm : virtual public AForm {

public:
  ShrubberyCreationForm(std::string const &target);     // empty constructor
  ShrubberyCreationForm(ShrubberyCreationForm const &); // copy constructor
  ShrubberyCreationForm &
  operator=(ShrubberyCreationForm const &); // copy assignment operator
  ~ShrubberyCreationForm();                 // destructor

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
  ShrubberyCreationForm(); // empty constructor
};

#endif
