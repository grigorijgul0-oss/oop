#include "Circle.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Creating an object via external function
    cout << "--- Testing makeCircle function ---" << endl;
    Circle circle1 = makeCircle(5.5, -3.0, 10.0);
    circle1.Display();
    cout << "Area: " << circle1.area() << endl;
    cout << "Circumference: " << circle1.circumference() << endl;

    // 2. Demonstrating input/output methods
    cout << "\n--- Testing keyboard input ---" << endl;
    Circle circle2;
    circle2.Read();
    circle2.Display();
    cout << "Area: " << circle2.area() << endl;
    cout << "Circumference: " << circle2.circumference() << endl;

    return 0;
}