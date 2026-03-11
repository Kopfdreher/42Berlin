#include "ShrubberyCreationForm.hpp"
#include <fstream>

// public ----------------------------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm(std::string const &target)
    : AForm("ShrubberyCreationForm", 145, 137), _target(target) {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
  if (this != &rhs) {
    AForm::operator=(rhs);
    _target = rhs._target;
  }
  return *this;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src)
    : AForm(src), _target(src._target) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

void ShrubberyCreationForm::executeAction() const {
  std::string fileName = _target + "_shrubbery";
  std::ofstream outfile(fileName.c_str());
  if (!outfile.is_open())
    throw FileNotOpenException();
  outfile << "       _-_\\ " << std::endl;
  outfile << "    /~~   ~~\\ " << std::endl;
  outfile << " /~~         ~~\\ " << std::endl;
  outfile << "{               } " << std::endl;
  outfile << " \\  _-     -_  / " << std::endl;
  outfile << "   ~  \\\\ //  ~ " << std::endl;
  outfile << "_- -   | | _- _ " << std::endl;
  outfile << "  _ -  | |   -_ " << std::endl;
  outfile << "      // \\\\ " << std::endl;
  outfile.close();
}

// private ---------------------------------------------------------------------

ShrubberyCreationForm::ShrubberyCreationForm() {}

// std::string const _name;
// bool _isSigned;
// int const _gradeSign;
// int const _gradeExecute;
