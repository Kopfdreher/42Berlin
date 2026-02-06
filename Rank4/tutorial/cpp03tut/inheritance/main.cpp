#include "Animal.hpp"
#include "Cat.hpp"
#include <iostream>

#define PRINT_MSG(x) std::cout << "\n\033[1;33m--- " << x << " ---\033[0m" << std::endl

int main() {
    
    // TEST 1: Basis-Klasse (Animal)
    {
        PRINT_MSG("TEST 1: Creating a generic Animal");
        Animal a;
        a.eat("Grass");
        a.run(10);
        // a.scornSomeone("You"); // Das würde nicht kompilieren!
    } // Hier wird 'a' zerstört (Destruktor)

    // TEST 2: Abgeleitete Klasse (Cat) - Vererbung testen
    {
        PRINT_MSG("TEST 2: Creating a Cat");
        Cat kitty;
        
        std::cout << "(Calling inherited methods...)" << std::endl;
        kitty.eat("Tuna");      // Geerbt von Animal
        kitty.run(5);           // Geerbt von Animal
        
        std::cout << "(Calling cat-specific methods...)" << std::endl;
        kitty.scornSomeone("Dog"); // Nur für Cat
    } // Hier: Erst ~Cat(), dann ~Animal()

    // TEST 3: Copy Constructor & Assignment Operator (Canonical Form)
    {
        PRINT_MSG("TEST 3: Testing Copies (Deep Copy logic)");
        
        std::cout << "1. Create original cat:" << std::endl;
        Cat original;
        
        std::cout << "\n2. Test Copy Constructor (Cat copy(original)):" << std::endl;
        Cat copy(original); // Ruft Animal Copy Const UND Cat Copy Const auf
        
        std::cout << "\n3. Test Assignment Operator (original = copy):" << std::endl;
        Cat assigned;
        assigned = original; // Ruft Animal Op= UND Cat Op= auf
        
        std::cout << "\nDestructing all 3 cats..." << std::endl;
    }

    return 0;
}
