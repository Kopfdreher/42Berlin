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

  // STRUCTS
  struct DataValue {
    double d;
    float f;
    int i;
    char c;
    bool intIsPossible;
    bool charIsPossible;
  };

  // ENUMS
  enum eType { CHAR, INT, FLOAT, DOUBLE, PSEUDO, INVALID };

  // METHODS
  static void printInt(const std::string &literal);
  static void printChar(const std::string &literal);
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
