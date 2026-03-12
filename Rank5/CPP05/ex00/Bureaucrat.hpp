#include <string>
#include <stdexcept>

#ifndef Bureaucrat_H
#define Bureaucrat_H

class Bureaucrat {

public:
  Bureaucrat(const std::string &name, const int grade);
  Bureaucrat(Bureaucrat const &);            // copy constructor
  Bureaucrat &operator=(Bureaucrat const &); // copy assignment operator
  ~Bureaucrat();                    // destructor

  // Methods
  std::string const &getName() const;
  int getGrade() const;
  void incrementGrade();
  void decrementGrade();

  class GradeTooHighException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Error: Grade too high";
    }
  };

  class GradeTooLowException : public std::exception {
  public:
    virtual const char *what() const throw() {
      return "Error: Grade too low";
    }
  };

private:
  const std::string _name;
  int _grade;

  Bureaucrat(); // empty constructor
};

std::ostream &operator<<(std::ostream &o, Bureaucrat const &rhs);

#endif
