#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
	_total = 0;
}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
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
  //std::cout << "WORK IN PROGRESS!!" << std::endl;
	int i;

	i = -1;
	while (++i < 8 && i < this->_total)
		PhoneBook::_printContact(i);
}

void PhoneBook::_addInput(Contact::Info field) {
	std::string	input;

	if (std::getline(std::cin, input)) {
		this->_contacts[this->_total % 8].setInfo(field, input);
	} else {
		this->_contacts[this->_total % 8].setInfo(field, "");
	}
}

void 
