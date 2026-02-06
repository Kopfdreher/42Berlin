#include "Animal.hpp"

// Constructor
Animal::Animal() : _numberOfLegs(4) { // Defaulting to 4 legs usually
    std::cout << "Animal constructed" << std::endl;
}

// Copy Constructor
Animal::Animal(Animal const &src) {
    std::cout << "Animal Copy Constructor called" << std::endl;
    *this = src;
}

// Assignment Operator
Animal &Animal::operator=(Animal const &rhs) {
    std::cout << "Animal Assignment Operator called" << std::endl;
    if (this != &rhs) {
        // WICHTIG: Hier kopieren wir die Member-Variablen direkt.
        // Nicht Animal::operator=(rhs) aufrufen -> Das wäre eine Endlos-Schleife!
        this->_numberOfLegs = rhs._numberOfLegs;
    }
    return *this;
}

// Destructor
Animal::~Animal() {
    std::cout << "Animal destroyed" << std::endl;
}

// Member Functions
void Animal::run(int distance) {
    std::cout << "Animal runs " << distance << " meters." << std::endl;
}

void Animal::call() {
    std::cout << "Animal makes a generic sound." << std::endl;
}

void Animal::eat(std::string const &what) {
    std::cout << "Animal eats " << what << "." << std::endl;
}

void Animal::walk(int distance) {
    std::cout << "Animal walks " << distance << " meters." << std::endl;
}
