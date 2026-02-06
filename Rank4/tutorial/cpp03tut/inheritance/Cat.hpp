#ifndef CAT_H
#define CAT_H

#include "Animal.hpp"
#include <string>
#include <iostream>

// Wir erben "public" von Animal, damit alle public Methoden von Animal
// auch an der Katze von außen aufrufbar sind.
class Cat : public Animal {

public:
    Cat();
    Cat(Cat const &src);
    Cat &operator=(Cat const &rhs);
    ~Cat();

    void scornSomeone(std::string const &target);
};

#endif
