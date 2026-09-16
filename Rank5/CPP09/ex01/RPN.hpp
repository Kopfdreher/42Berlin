#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>
#include <list>

class RPN {

public:
  RPN();
  RPN(RPN const &);
  RPN &operator=(RPN const &);
  ~RPN();

  void processInput(const std::string &s);

private:
  std::stack<int, std::list<int> > _nums;
  bool isOperator(const std::string &token) const;
  void execOperator(const std::string &s);
};

#endif
