#ifndef SCALARCONVERTER_H
#define SCALARCONVERTER_H

#include <string>

class ScalarConverter {

public:
  static void convert(const std::string &literal);

  // EXCEPTIONS

  class InvalidException : public std::exception {
  public:
    virtual const char *what() const throw() { return "Error: Invalid-Input"; }
  };

private:
  ScalarConverter();                        // empty constructor
  ScalarConverter(ScalarConverter const &); // copy constructor
  ScalarConverter &
  operator=(ScalarConverter const &); // copy assignment operator
  ~ScalarConverter();                 // destructor

  // STRUCTS
  struct DataValue {
    double d;
    float f;
    int i;
    char c;
    bool floatIsPossible;
    bool intIsPossible;
    bool charIsPossible;
  };

  // ENUMS
  enum eType { CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID };

  // METHODS
  static void printDouble(const std::string &literal, DataValue &value);
  static void printFloat(const std::string &literal, DataValue &value);
  static void printInt(const std::string &literal, DataValue &value);
  static void printChar(const std::string &literal, DataValue &value);
  static void printPseudo(const std::string &literal);
  static void printConversion(const DataValue &value);

  static void setPossibility(DataValue &value);

  static eType setType(const std::string &literal);
  static bool isPseudo(const std::string &literal);
  static bool isChar(const std::string &literal);
  static bool isInt(const std::string &literal);
  static bool isDecimal(const std::string &literal, unsigned long len);
  static bool isFloat(const std::string &literal);
  static bool isDouble(const std::string &literal);
};

#endif
