#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

int main() {
  PhoneBook phonebook;
  std::string input;

  while (1) {
    std::cout << "> ";
    std::getline(std::cin, input);
    if (input == "EXIT")
      break;
    else if (input == "ADD")
      phonebook.addContact();
    else if (input == "SEARCH")
      phonebook.searchPhoneBook();
  }
}
