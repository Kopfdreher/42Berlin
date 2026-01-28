#include "PhoneBook.hpp"

PhoneBook::PhoneBook() {}

PhoneBook::~PhoneBook() {}

void PhoneBook::addContact() {
	Contact::this->_contacts[this->_index % 8].setInfo()
}

void PhoneBook::displayPhoneBook() {}
