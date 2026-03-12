#include "ScalarConverter.hpp"

// public ----------------------------------------------------------------------

void ScalarConverter::convert(const std::string &literal) {

  // is len 1 && isNotDigit -> char
  // f in the end? -> float
  // decimal but no f -> double
  // just digits, and - or + -> int
  // weird string, "-inf" -> pseudo-literal
}


// private ---------------------------------------------------------------------

ScalarConverter::ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &rhs) {
  (void)rhs;
}

ScalarConverter::ScalarConverter(ScalarConverter const &src) { (void)src; }

ScalarConverter::~ScalarConverter() {}
