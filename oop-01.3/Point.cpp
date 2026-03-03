#include "Point.h"
#include <iostream>
#include <cmath>
#include <sstream>

// Setters with validation (protecting against NaN and Infinity)
void Point::setX(double newX) {
    if (!std::isnan(newX) && !std::isinf(newX)) {
        x = newX;
    }
    else {
        std::cerr << "Error: Invalid value for X. Set to 0." << std::endl;
        x = 0.0;
    }
}

void Point::setY(double newY) {
    if (!std::isnan(newY) && !std::isinf(newY)) {
        y = newY;
    }
    else {
        std::cerr << "Error: Invalid value for Y. Set to 0." << std::endl;
        y = 0.0;
    }
}

// Constant getters
double Point::getX() const { return x; }
double Point::getY() const { return y; }

// Initialization
void Point::Init(double newX, double newY) {
    setX(newX);
    setY(newY);
}

// Input from keyboard
void Point::Read() {
    double inputX, inputY;
    std::cout << "Enter X coordinate: ";
    std::cin >> inputX;
    std::cout << "Enter Y coordinate: ";
    std::cin >> inputY;
    Init(inputX, inputY);
}

// Display on screen
void Point::Display() const {
    std::cout << "Point (" << x << ", " << y << ")" << std::endl;
}

// Convert to string
std::string Point::toString() const {
    std::ostringstream oss;
    oss << "(" << x << ", " << y << ")";
    return oss.str();
}

// Move along X axis
void Point::moveX(double dx) {
    setX(x + dx);
}

// Move along Y axis
void Point::moveY(double dy) {
    setY(y + dy);
}

// Calculate distance between two points
double Point::distance(const Point& other) const {
    return std::sqrt(std::pow(other.x - x, 2) + std::pow(other.y - y, 2));
}