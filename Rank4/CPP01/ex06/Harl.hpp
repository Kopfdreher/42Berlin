#include <string>

#ifndef HARL_H
#define HARL_H

class Harl {

public:
  Harl();
  ~Harl();

  void debug();
  void info();
  void warning();
  void error();
  void complain(std::string level);
};

#endif
