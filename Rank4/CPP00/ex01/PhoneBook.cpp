#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>

PhoneBook::PhoneBook() { _total = 0; }

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
	while (
  std::cout << "First Name: ";
  _addInput(Contact::FirstName);
  std::cout << "Last Name: ";
  _addInput(Contact::LastName);
  std::cout << "Nickname: ";
  _addInput(Contact::Nickname);
  std::cout << "Phone Number: ";
  _addInput(Contact::PhoneNumber);
  std::cout << "Darkest Secret: ";
  _addInput(Contact::DarkestSecret);
  this->_total++;
  std::cout << "Contact added!" << std::endl;
}

void PhoneBook::displayPhoneBook() {
  std::cout << "|----------|----------|----------|----------|" << std::endl;
  std::cout << "|     Index| FirstName|  LastName|  Nickname|" << std::endl;
  std::cout << "|----------|----------|----------|----------|" << std::endl;
  for (int i = 0; i < 8 && i < this->_total; i++)
    PhoneBook::_printContact(i);
  std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::_addInput(Contact::Info field) {
  std::string input;

  while (true) {
    if (!std::getline(std::cin, input))
      break;
    if (!input.empty()) {
      this->_contacts[this->_total % 8].setInfo(field, input);
      break;
    }
    std::cout << "Field cannot be empty. Try again: ";
  }
}

void PhoneBook::_printContact(int i) {
  int field;

  field = 0;
  std::cout << "|         " << i + 1;
  while ((Contact::Info)field <= Contact::Nickname) {
    std::cout << "|" << std::setw(10)
              << _truncate(this->_contacts[i].getInfo((Contact::Info)field));
    field++;
  }
  std::cout << "|" << std::endl;
}

std::string PhoneBook::_truncate(std::string str) {
  if (str.length() > 10)
    return (str.substr(0, 9) + ".");
  return (str);
}
