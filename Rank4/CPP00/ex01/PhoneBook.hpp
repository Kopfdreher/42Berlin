#ifndef PHONE_BOOK_H
#define PHONE_BOOK_H

#include "Contact.hpp"
#include <string>

class PhoneBook {
private:
  Contact::Contact _contacts[8];
  int _index;

public:
  PhoneBook();
  ~PhoneBook();

  void addContact();
  void displayPhoneBook();
}

#endif
