#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>

class ScalarConverter {

public:
  static void convert(const std::string &literal);

private:
  ScalarConverter();                        // empty constructor
  ScalarConverter(ScalarConverter const &); // copy constructor
  ScalarConverter &
  operator=(ScalarConverter const &); // copy assignment operator
  ~ScalarConverter();                 // destructor
};

#endif
