#pragma once
#include <string>

class Rectangle {
public:
    // Оголошення вкладеного класу (Nested Class)
    class Pair {
    private:
        double first;
        double second;

    public:
        void Init(double f, double s);
        void Read();
        void Display() const;
        std::string toString() const;

        double getFirst() const;
        double getSecond() const;

        bool setFirst(double f);
        bool setSecond(double s);

        double Product() const;
    };

private:
    Pair sides; // Поле зовнішнього класу, яке є об'єктом вкладеного класу

public:
    void Init(double a, double b);
    void Read();
    void Display() const;
    std::string toString() const;

    Pair getSides() const;
    bool setSides(double a, double b);

    double Perimeter() const;
    double Area() const;
};