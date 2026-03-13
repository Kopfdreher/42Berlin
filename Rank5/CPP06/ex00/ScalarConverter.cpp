#include "ScalarConverter.hpp"
#include <cctype>
#include <iostream>

// public ----------------------------------------------------------------------

void ScalarConverter::convert(const std::string &literal) {
  eType type = setType(literal);
  switch (type) {
  case PSEUDO:
    std::cout << "PSEUDO" << std::endl;
    break;
  case CHAR:
    std::cout << "CHAR" << std::endl;
    break;
  case INT:
    std::cout << "INT" << std::endl;
    break;
  case FLOAT:
    std::cout << "FLOAT" << std::endl;
    break;
  case DOUBLE:
    std::cout << "DOUBLE" << std::endl;
    break;
  default:
    std::cout << "INVALID" << std::endl;
  }
}

// private
// ---------------------------------------------------------------------

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
