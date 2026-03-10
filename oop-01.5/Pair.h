#pragma once
#include <string>

class Pair {
private:
    double first;
    double second;

public:
    // Initialization method
    void Init(double f, double s);
    // Keyboard input method
    void Read();
    // Display method
    void Display() const;
    // Convert to string method
    std::string toString() const;

    // Access methods (getters)
    double getFirst() const;
    double getSecond() const;

    // Access methods (setters) with validation
    bool setFirst(double f);
    bool setSecond(double s);

    // Specific method: calculate product
    double Product() const;
};