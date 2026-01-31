#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

int main() {
  PhoneBook phonebook;
  std::string input;

	std::cout << "You opened your PhoneBook!" << std::endl;
	std::cout << "Available commands: ADD, SEARCH, EXIT" << std::endl;
  while (1) {
    std::cout << "> ";
    std::getline(std::cin, input);
    if (input == "ADD")
      phonebook.addContact();
    else if (input == "SEARCH")
      phonebook.searchPhoneBook();
		else if (input == "EXIT")
      break;
  }
}
