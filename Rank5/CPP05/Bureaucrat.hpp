#include <string>

#ifndef Bureaucrat_H
#define Bureaucrat_H

class Bureaucrat {

public:
  Bureaucrat(const std::string name, const int grade);
  Bureaucrat(X const &); // copy constructor
  Bureaucrat &operator=(X const &); // copy assignment operator
  ~Bureaucrat(); // destructor


private:
  const std::string _name;
  int _grade;

  Bureaucrat(); // empty constructor
};

#endif
