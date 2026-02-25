#ifndef CIRCLE_H
#define CIRCLE_H

class Circle {
private:
    double x; // X coordinate of the center
    double y; // Y coordinate of the center
    double R; // Radius of the circle

public:
    // Default constructor
    Circle();

    // Access methods (constant getters)
    double getX() const;
    double getY() const;
    double getR() const;

    // Modifiers (setters) with validation
    bool setX(double newX);
    bool setY(double newY);
    bool setR(double newR);

    // Initialization method
    bool Init(double newX, double newY, double newR);

    // Keyboard input method
    void Read();

    // Screen output method
    void Display() const;

    // Methods for calculating area and circumference
    double area() const;
    double circumference() const;
};

// External function to create an object
Circle makeCircle(double x, double y, double R);

#endif // CIRCLE_H