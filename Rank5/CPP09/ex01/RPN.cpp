#include "RPN.hpp"
#include <iostream>
#include <sstream>
#include <stack>
#include <climits>

// public ----------------------------------------------------------------------

RPN::RPN() {}

RPN &RPN::operator=(RPN const &rhs) {
  if (this != &rhs)
    _nums = rhs._nums;
  return *this;
}

RPN::RPN(RPN const &src) { *this = src; }

RPN::~RPN() {}

void RPN::processInput(const std::string &s) {
  std::stringstream input(s);
  std::string token;

  while (input >> token) {
    if (token.length() != 1) {
      throw std::runtime_error("Error");
    } else if (token.length() == 1 && std::isdigit(token[0])) {
      _nums.push(token[0] - '0');
    } else if (isOperator(token)) {
      execOperator(token);
    } else {
      throw std::runtime_error("Error");
    }
  }
  if (_nums.size() != 1)
    throw std::runtime_error("Error");
  std::cout << _nums.top() << std::endl;
}

// private ---------------------------------------------------------------------

bool RPN::isOperator(const std::string &token) const {
  return (token[0] == '/' || token[0] == '*' || token[0] == '-' ||
          token[0] == '+');
}

void RPN::execOperator(const std::string &op) {
  if (_nums.size() < 2)
    throw std::runtime_error("Error");

  int a = _nums.top();
  _nums.pop();
  int b = _nums.top();
  _nums.pop();

  if (op == "*") {
		if (a == 0 || b == 0)
			return _nums.push(0);
    if (a > INT_MAX / b)
      throw std::runtime_error("Error");
    _nums.push(b * a);
  }
  else if (op == "-") {
    if (a < INT_MIN + b)
      throw std::runtime_error("Error");
    _nums.push(b - a);
  }
  else if (op == "+") {
    if (a > INT_MAX - b)
      throw std::runtime_error("Error");
    _nums.push(b + a);
  }
  else if (op == "/") {
    if (a == 0)
      throw std::runtime_error("Error");
    _nums.push(b / a);
  }
}
