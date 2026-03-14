#include "ScalarConverter.hpp"
#include <cctype>
#include <cerrno>
#include <cmath>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <sstream>
#include <stdexcept>

// public ----------------------------------------------------------------------

void ScalarConverter::convert(const std::string &literal) {
  eType type = setType(literal);
  DataValue value;

  value.charIsPossible = true;
  value.intIsPossible = true;
  value.floatIsPossible = true;

  switch (type) {
  case PSEUDO:
    printPseudo(literal);
    return;
  case CHAR:
    printChar(literal, value);
    return;
  case INT:
    printInt(literal, value);
    return;
  case FLOAT:
    printFloat(literal, value);
    return;
  case DOUBLE:
    printDouble(literal, value);
    return;
  default:
    throw InvalidException();
  }
}

// private ---------------------------------------------------------------------

void ScalarConverter::printDouble(const std::string &literal,
                                  DataValue &value) {
  errno = 0;
  double tmp = std::strtod(literal.c_str(), NULL);
  if (errno == ERANGE)
    throw InvalidException();
  value.d = tmp;
  value.f = static_cast<float>(value.d);
  value.c = static_cast<char>(value.d);
  value.i = static_cast<int>(value.d);
  setPossibility(value);
  printConversion(value);
}

void ScalarConverter::printFloat(const std::string &literal, DataValue &value) {
  errno = 0;
  double tmp = std::strtod(literal.c_str(), NULL);

  if (errno == ERANGE || tmp > std::numeric_limits<float>::max() ||
      tmp < -std::numeric_limits<float>::max())
    throw InvalidException();
  value.f = static_cast<float>(tmp);
  value.c = static_cast<char>(value.f);
  value.i = static_cast<int>(value.f);
  value.d = static_cast<double>(value.f);
  setPossibility(value);
  printConversion(value);
}

void ScalarConverter::printInt(const std::string &literal, DataValue &value) {
  errno = 0;
  long tmp = std::strtol(literal.c_str(), NULL, 10);

  if (errno == ERANGE || tmp > std::numeric_limits<int>::max() ||
      tmp < std::numeric_limits<int>::min())
    throw InvalidException();
  value.i = static_cast<int>(tmp);
  value.c = static_cast<char>(value.i);
  value.f = static_cast<float>(value.i);
  value.d = static_cast<double>(value.i);
  setPossibility(value);
  printConversion(value);
}

void ScalarConverter::printChar(const std::string &literal, DataValue &value) {
  value.c = literal[0];
  value.i = static_cast<int>(value.c);
  value.f = static_cast<float>(value.c);
  value.d = static_cast<double>(value.c);
  setPossibility(value);
  printConversion(value);
}

void ScalarConverter::printPseudo(const std::string &literal) {
  std::string pseudoF[] = {"-inff", "+inff", "nanf"};
  std::string pseudoD[] = {"-inf", "+inf", "nan"};

  int i = 0;
  while (i < 6) {
    if (literal == pseudoF[i] || literal == pseudoD[i])
      break;
    i++;
  }
  std::cout << "char: impossible\n";
  std::cout << "int: impossible\n";
  std::cout << "float: " << pseudoF[i] << "\n";
  std::cout << "double: " << pseudoD[i] << std::endl;
}

void ScalarConverter::printConversion(const DataValue &value) {

  // CHAR
  if (value.charIsPossible) {
    if (value.c >= ' ' && value.c <= '~')
      std::cout << "char: '" << value.c << "'\n";
    else
      std::cout << "char: Non displayable\n";
  } else {
    std::cout << "char: impossible\n";
  }

  // INT
  if (value.intIsPossible)
    std::cout << "int: " << value.i << "\n";
  else
    std::cout << "int: impossible\n";

  // FLOAT
  if (value.floatIsPossible) {
    std::cout << "float: " << value.f;
    if (value.f == std::floor(value.f))
      std::cout << ".0";
    std::cout << "f\n";
  } else
    std::cout << "float: impossible\n";

  // DOUBLE
  std::cout << "double: " << value.d;
  if (value.d == std::floor(value.d))
    std::cout << ".0";
  std::cout << std::endl;
}

void ScalarConverter::setPossibility(DataValue &value) {
  if (value.d < 0.0 || value.d > 128.0)
    value.charIsPossible = false;
  if (value.d > std::numeric_limits<int>::max() ||
      value.d < std::numeric_limits<int>::min())
    value.intIsPossible = false;
  if (value.d > std::numeric_limits<float>::max() ||
      value.d < -std::numeric_limits<float>::max())
    value.floatIsPossible = false;
  return;
}

ScalarConverter::eType ScalarConverter::setType(const std::string &literal) {
  if (isPseudo(literal))
    return PSEUDO;
  if (isChar(literal))
    return CHAR;
  if (isInt(literal))
    return INT;
  if (isFloat(literal))
    return FLOAT;
  if (isDouble(literal))
    return DOUBLE;
  return INVALID;
}

// weird string, "-inf" -> pseudo-literal
bool ScalarConverter::isPseudo(const std::string &literal) {
  std::string pseudoLiteral[] = {"-inff", "+inff", "nanf",
                                 "-inf",  "+inf",  "nan"};
  for (int i = 0; i < 6; i++) {
    if (literal == pseudoLiteral[i]) {
      return true;
    }
  }
  return false;
}

// is len 1 && isNotDigit -> char
bool ScalarConverter::isChar(const std::string &literal) {
  if (literal.length() == 1 && std::isdigit(literal[0]) == false)
    return true;
  return false;
}

// just digits, and - or + -> int
bool ScalarConverter::isInt(const std::string &literal) {
  unsigned long start = 0;

  if (literal.length() > 11 || literal.length() == 0)
    return false;
  if (literal[start] == '-' || literal[start] == '+') {
    if (literal.length() == 1)
      return false;
    start++;
  }
  while (start < literal.length()) {
    if (!std::isdigit(literal[start]))
      return false;
    start++;
  }
  return true;
}

bool ScalarConverter::isDecimal(const std::string &literal, unsigned long len) {
  unsigned long start = 0;
  int point = 0;
  int preDigit = 0;
  int postDigit = 0;

  if (literal[start] == '-' || literal[start] == '+')
    start++;
  while (start < len) {
    if (!std::isdigit(literal[start]) && literal[start] != '.')
      return false;
    if (literal[start] == '.') {
      point++;
      start++;
      continue;
    }
    if (point == 0)
      preDigit++;
    else
      postDigit++;
    start++;
  }
  if (preDigit == 0 || postDigit == 0 || point != 1)
    return false;
  return true;
}

// f in the end? -> float
bool ScalarConverter::isFloat(const std::string &literal) {
  if (literal[literal.length() - 1] != 'f')
    return false;
  return isDecimal(literal, literal.length() - 1);
}

// decimal but no f -> double
bool ScalarConverter::isDouble(const std::string &literal) {
  return isDecimal(literal, literal.length());
}

ScalarConverter::ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
  (void)rhs;
  return *this;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) { (void)src; }

ScalarConverter::~ScalarConverter() {}
