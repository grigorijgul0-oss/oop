#include "Rectangle.h"
#include <iostream>
#include <sstream>

void Rectangle::Pair::Init(double f, double s) {
    if (!setFirst(f)) first = 1.0;
    if (!setSecond(s)) second = 1.0;
}

void Rectangle::Pair::Read() {
    double f, s;
    std::cout << "Enter the first number (side > 0): ";
    std::cin >> f;
    while (!setFirst(f)) {
        std::cout << "Error! Number must be greater than 0. Try again: ";
        std::cin >> f;
    }

    std::cout << "Enter the second number (side > 0): ";
    std::cin >> s;
    while (!setSecond(s)) {
        std::cout << "Error! Number must be greater than 0. Try again: ";
        std::cin >> s;
    }
}

void Rectangle::Pair::Display() const {
    std::cout << "Pair of numbers: (" << first << ", " << second << ")" << std::endl;
}

std::string Rectangle::Pair::toString() const {
    std::ostringstream oss;
    oss << "(" << first << ", " << second << ")";
    return oss.str();
}

double Rectangle::Pair::getFirst() const { return first; }
double Rectangle::Pair::getSecond() const { return second; }

bool Rectangle::Pair::setFirst(double f) {
    if (f > 0) {
        first = f;
        return true;
    }
    return false;
}

bool Rectangle::Pair::setSecond(double s) {
    if (s > 0) {
        second = s;
        return true;
    }
    return false;
}

double Rectangle::Pair::Product() const {
    return first * second;
}


void Rectangle::Init(double a, double b) {
    if (!setSides(a, b)) {
        sides.Init(1.0, 1.0);
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

Rectangle::Pair Rectangle::getSides() const {
    return sides;
}

bool Rectangle::setSides(double a, double b) {
    Rectangle::Pair temp;
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
    return sides.Product();
}