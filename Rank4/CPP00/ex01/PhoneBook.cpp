#include "PhoneBook.hpp"
#include <iomanip>
#include <iostream>
#include <sstream>

PhoneBook::PhoneBook() {
  _total = 0;
  _fieldNames[0] = "FirstName";
  _fieldNames[1] = "LastName";
  _fieldNames[2] = "Nickname";
  _fieldNames[3] = "PhoneNumber";
  _fieldNames[4] = "DarkestSecret";
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
  int i;

  i = -1;
  while (++i < 5) {
    std::cout << _fieldNames[i] << ": ";
    _addInput((Contact::Info)i);
  }
  this->_total++;
  std::cout << "Contact added!" << std::endl;
}

void PhoneBook::searchPhoneBook() {
  std::string input;
  int index;

  if (_total == 0) {
    std::cout << "No contacts to display!" << std::endl;
    return;
  }
  _displayPhoneBook();
  std::cout << "Put an index: ";
  while (true) {
    std::getline(std::cin, input);
    std::stringstream sStream(input);
    if (sStream >> index && sStream.eof() && index > 0 && index <= 8 &&
        index <= _total) {
      _printContact(index - 1);
      break;
    }
    std::cout << "Index invalid. Try again: ";
  }
}

void PhoneBook::_displayPhoneBook() {
  std::cout << "|----------|----------|----------|----------|" << std::endl;
  std::cout << "|     Index| FirstName|  LastName|  Nickname|" << std::endl;
  std::cout << "|----------|----------|----------|----------|" << std::endl;
  for (int i = 0; i < 8 && i < this->_total; i++)
    _printContact(i);
  std::cout << "|----------|----------|----------|----------|" << std::endl;
}

void PhoneBook::_addInput(Contact::Info field) {
  std::string input;

  while (true) {
    std::getline(std::cin, input);
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
