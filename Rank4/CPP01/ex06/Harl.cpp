#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

Harl::~Harl() {}

void Harl::debug() {
  std::cout
      << "I love having extra bacon for my \n"
         "7XL-double-cheese-triple-pickle-specialketchup burger. I really do!"
      << std::endl;
}

void Harl::info() {
  std::cout
      << "I cannot believe adding extra bacon costs more money. \nYou didn’t put "
         "enough bacon in my burger! \nIf you did, I wouldn’t be asking for more!"
      << std::endl;
}

void Harl::warning() {
  std::cout
      << "I think I deserve to have some extra bacon for free. \nI’ve been "
         "coming for years, whereas you started working here just last month."
      << std::endl;
}

void Harl::error() {
  std::cout << "This is unacceptable! I want to speak to the manager now."
            << std::endl;
}

void Harl::complain(std::string level) {

  std::string levels[] = {"DEBUG", "INFO", "WARNING", "ERROR"};

  int i = 0;
  while (i < 4 && levels[i] != level) {
    i++;
  }
  switch (i) {
  case 0:
    std::cout << "[ DEBUG ]\n";
    debug();
    std::cout << "\n";
  case 1:
    std::cout << "[ INFO ]\n";
    info();
    std::cout << "\n";
  case 2:
    std::cout << "[ WARNING ]\n";
    warning();
    std::cout << "\n";
  case 3:
    std::cout << "[ ERROR ]\n";
    error();
    std::cout << "\n";
    break;
  default:
    std::cout << "[ Probably complaining about insignificant problems ]"
              << std::endl;
  }
}
