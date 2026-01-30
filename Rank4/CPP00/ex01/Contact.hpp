#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <string>

class Contact {
public:
  enum Info { FirstName = 0, LastName, Nickname, PhoneNumber, DarkestSecret };

  Contact();
  ~Contact();

  void setInfo(Info field, std::string value);
  std::string getInfo(Info field) const;
  int fieldIsValid(Info field) const;

private:
  std::string _info[5];
};

#endif
