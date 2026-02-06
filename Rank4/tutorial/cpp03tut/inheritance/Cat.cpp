#include "Cat.hpp"

// Constructor
// : Animal() wird automatisch aufgerufen, aber man kann es explizit hinschreiben
Cat::Cat() : Animal() {
    std::cout << "Cat constructed" << std::endl;
}

// Copy Constructor
// WICHTIG: Wir müssen dem Animal-Teil sagen, dass er sich auch kopieren soll!
Cat::Cat(Cat const &src) : Animal(src) {
    std::cout << "Cat Copy Constructor called" << std::endl;
    // Hier würden wir zusätzliche Variablen von Cat kopieren, wenn es welche gäbe.
    // *this = src; // Nicht nötig, da Animal(src) schon den Basisteil erledigt hat.
}

// Assignment Operator
Cat &Cat::operator=(Cat const &rhs) {
    std::cout << "Cat Assignment Operator called" << std::endl;
    if (this != &rhs) {
        // WICHTIG: Erst den Animal-Teil kopieren!
        Animal::operator=(rhs);
        
        // Danach hier Cat-spezifische Variablen kopieren (falls vorhanden)
    }
    return *this;
}

// Destructor
// ~Animal() wird AUTOMATISCH danach aufgerufen.
Cat::~Cat() {
    std::cout << "Cat destroyed" << std::endl;
}

// Member Function
void Cat::scornSomeone(std::string const &target) {
    std::cout << "Cat looks at " << target << " with absolute disdain." << std::endl;
}
