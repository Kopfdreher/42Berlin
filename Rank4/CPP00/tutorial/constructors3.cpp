#include <iostream>

ClapTrap::ClapTrap(void) : _name("Default"), _hp(10), _ep(10), _ad(0) {
	std::cout << "Default ClapTrap constructor called for ";
	std::cout << _GREEN << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hp(10), _ep(10) _ad(0) {
	std::cout << "Named ClapTrap constructor called for ";
	std::cout << _GREEN << this->_name;
	std::cout << _RESET << std::endl;
	return ;
}

ClapTrap::ClapTrap(std::string name, uint hp, uint ep, uint ad) :
_name(name), _hp(hp), _ep(ep), _ad(ad) {
	std::cout << "Full ClapTrap Constructor called for ";
	std::cout << _GREEN << this->_name << _RESET;
	std::cout << " with " << _YELLOW << this->_hp << _RESET << "hp, ";
	std::cout << _YELLOW << this->_ep << _RESET << " ep, " << _YELLOW << this->_ad
		<< _RESET << " ad. ";
	std::cout << std::endl;
	return ;
}
