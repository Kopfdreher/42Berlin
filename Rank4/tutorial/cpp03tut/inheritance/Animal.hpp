#ifndef ANIMAL_H
#define ANIMAL_H

#include <string>
#include <iostream>

class Animal {

public:
    Animal();
    Animal(Animal const &src);
    Animal &operator=(Animal const &rhs);
    ~Animal();

    void run(int distance);
    void call();
    void eat(std::string const &what);
    void walk(int distance);

private:
    int _numberOfLegs;
};

#endif
