#include "Rectangle.h"
#include <iostream>
#include <sstream>

void Rectangle::Init(double a, double b) {
    if (!setSides(a, b)) {
        sides.Init(1.0, 1.0); // If data is incorrect, set to 1.0
    }
}

void Rectangle::Read() {
    std::cout << "--- Entering rectangle sides ---" << std::endl;
    sides.Read();
}

void Rectangle::Display() const {
    std::cout << "Rectangle with sides: " << sides.toString() << std::endl;
    std::cout << "Perimeter: " << Perimeter() << ", Area: " << Area() << std::endl;
}

std::string Rectangle::toString() const {
    std::ostringstream oss;
    oss << "Rectangle[sides=" << sides.toString() << "]";
    return oss.str();
}

Pair Rectangle::getSides() const {
    return sides;
}

bool Rectangle::setSides(double a, double b) {
    // Create a temporary pair for validation to avoid corrupting the current state
    Pair temp;
    if (temp.setFirst(a) && temp.setSecond(b)) {
        sides = temp;
        return true;
    }
    return false;
}

double Rectangle::Perimeter() const {
    return 2 * (sides.getFirst() + sides.getSecond());
}

double Rectangle::Area() const {
    // The area of a rectangle is the product of its sides (using the Pair method)
    return sides.Product();
}