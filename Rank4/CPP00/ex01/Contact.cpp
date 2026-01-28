#include "Contact.hpp"

Contact::Contact() {}

Contact::~Contact() {}

void Contact::setInfo(Info field, std::string value) {
  if (Contact::fieldIsValid(field))
    this->_info[field] = value;
}

std::string Contact::getInfo(Info field) const {
  if (Contact::fieldIsValid(field))
    return (this->_info[field]);
	return ("");
}

int Contact::fieldIsValid(Info field) const {
  return (field >= FirstName && field <= DarkestSecret);
}
