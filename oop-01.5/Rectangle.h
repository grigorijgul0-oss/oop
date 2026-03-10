#pragma once
#include "Pair.h"
#include <string>

class Rectangle {
private:
    Pair sides; // Container class contains an object of another class as a field

public:
    // Initialization method
    void Init(double a, double b);
    // Keyboard input method
    void Read();
    // Display method
    void Display() const;
    // Convert to string method
    std::string toString() const;

    // Access methods
    Pair getSides() const;
    bool setSides(double a, double b);

    // Specific methods
    double Perimeter() const;
    double Area() const;
};