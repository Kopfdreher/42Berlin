#include <iostream>
#include <string>

int main() {

  std::string str = "HI THIS IS BRAIN";

  std::string *stringPTR = &str;
  std::string &stringREF = str;

  std::cout << "MEMORY ADDRESS\nstring:\t\t" << &str << "\nstringPTR:\t"
            << stringPTR << "\nstringREF:\t" << &stringREF
            << "\nVALUES\nstring:\t\t" << str << "\nstringPTR:\t" << *stringPTR
            << "\nstringREF:\t" << stringREF << std::endl;
}
