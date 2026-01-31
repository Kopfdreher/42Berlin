#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include "Contact.hpp"
#include <string>

class PhoneBook {
public:
  PhoneBook();
  ~PhoneBook();

  void addContact();
  void searchPhoneBook();

private:
  Contact _contacts[8];
  int _total;
  std::string _fieldNames[5];

  void _addInput(Contact::Info field);
  void _displayPhoneBook();
  std::string _truncate(std::string str);
  void _printContact(int i);
  void _printExpandedContact(int i);
};

#endif
