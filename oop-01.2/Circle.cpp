#include "Circle.h"
#include <iostream>
#include <cstdlib> // For exit() function

using namespace std;

// Constant for Pi
const double PI = 3.141592653589793;

// Initialize with a safe default circle (unit circle at origin)
Circle::Circle() : x(0.0), y(0.0), R(1.0) {}

// Getters
double Circle::getX() const { return x; }
double Circle::getY() const { return y; }
double Circle::getR() const { return R; }

// Setters (Coordinates can be any real number)
bool Circle::setX(double newX) {
    x = newX;
    return true;
}

bool Circle::setY(double newY) {
    y = newY;
    return true;
}

// Validation: Radius must be strictly greater than 0
bool Circle::setR(double newR) {
    if (newR > 0) {
        R = newR;
        return true;
    }
    else {
        cout << "Error: Radius must be a positive number!" << endl;
        return false;
    }
}

// Init logic with validation
bool Circle::Init(double newX, double newY, double newR) {
    if (newR > 0) {
        x = newX;
        y = newY;
        R = newR;
        return true;
    }
    return false;
}

// Read from keyboard loop until valid
void Circle::Read() {
    double newX, newY, newR;
    do {
        cout << "Enter X coordinate of the center: ";
        cin >> newX;
        cout << "Enter Y coordinate of the center: ";
        cin >> newY;
        cout << "Enter the radius of the circle (R > 0): ";
        cin >> newR;

        if (newR <= 0) {
            cout << "Invalid radius! Please try again.\n";
        }
    } while (!Init(newX, newY, newR));
}

// Display method
void Circle::Display() const {
    cout << "Circle center: (" << x << ", " << y << "), Radius: " << R << endl;
}

// Calculate area
double Circle::area() const {
    return PI * R * R;
}

// Calculate circumference
double Circle::circumference() const {
    return 2 * PI * R;
}

// External creation function
Circle makeCircle(double x, double y, double R) {
    Circle c;
    if (!c.Init(x, y, R)) {
        cout << "Critical error (makeCircle): invalid arguments passed (" << x << ", " << y << ", " << R << "). Terminating." << endl;
        exit(1);
    }
    return c;
}