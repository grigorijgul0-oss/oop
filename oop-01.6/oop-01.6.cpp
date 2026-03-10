#include <iostream>
#include "Rectangle.h"

int main() {
    std::cout << "=== Rectangle::Pair Class Demonstration ===" << std::endl;
    // 1. Static object creation (using nested class)
    Rectangle::Pair p1;
    p1.Init(3.5, 4.2);
    p1.Display();
    std::cout << "Product of p1: " << p1.Product() << std::endl;

    // Checking encapsulation and validation
    if (!p1.setFirst(-5)) {
        std::cout << "Validation works: cannot set a negative value!" << std::endl;
    }
    std::cout << "toString for p1: " << p1.toString() << "\n\n";

    std::cout << "=== Rectangle Class Demonstration ===" << std::endl;
    // 2. Static object creation and Read() call
    Rectangle rect1;
    rect1.Read();
    rect1.Display();
    std::cout << "toString for rect1: " << rect1.toString() << "\n\n";

    // 3. Dynamic object creation (via pointer)
    std::cout << "--- Dynamic Object ---" << std::endl;
    Rectangle* rectPtr = new Rectangle();
    rectPtr->Init(5.0, 10.0);
    rectPtr->Display();
    delete rectPtr; // Mandatory memory deallocation
    std::cout << "\n";

    // 4. Static array of objects creation
    std::cout << "--- Static Array of Objects ---" << std::endl;
    const int SIZE = 2;
    Rectangle rectArray[SIZE];
    rectArray[0].Init(2.0, 4.0);
    rectArray[1].Init(7.5, 3.2);

    for (int i = 0; i < SIZE; i++) {
        std::cout << "Rectangle " << i + 1 << ":" << std::endl;
        std::cout << "Sides (via getter): " << rectArray[i].getSides().toString() << std::endl;
        std::cout << "Area: " << rectArray[i].Area() << std::endl;
    }
    std::cout << "\n";

    // 5. Dynamic array of objects creation
    std::cout << "--- Dynamic Array of Objects ---" << std::endl;
    Rectangle* dynArray = new Rectangle[2];
    dynArray[0].Init(1.1, 2.2);
    dynArray[1].Init(3.3, 4.4);

    for (int i = 0; i < 2; i++) {
        dynArray[i].Display();
    }
    delete[] dynArray; // Deallocating array memory

    return 0;
}