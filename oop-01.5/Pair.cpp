#include "Pair.h"
#include <iostream>
#include <sstream>

void Pair::Init(double f, double s) {
    // Use setters to prevent bypassing validation
    if (!setFirst(f)) first = 1.0;   // default value in case of error
    if (!setSecond(s)) second = 1.0; // default value in case of error
}

void Pair::Read() {
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

void Pair::Display() const {
    std::cout << "Pair of numbers: (" << first << ", " << second << ")" << std::endl;
}

std::string Pair::toString() const {
    std::ostringstream oss;
    oss << "(" << first << ", " << second << ")";
    return oss.str();
}

double Pair::getFirst() const { return first; }
double Pair::getSecond() const { return second; }

bool Pair::setFirst(double f) {
    if (f > 0) {
        first = f;
        return true;
    }
    return false;
}

bool Pair::setSecond(double s) {
    if (s > 0) {
        second = s;
        return true;
    }
    return false;
}

double Pair::Product() const {
    return first * second;
}