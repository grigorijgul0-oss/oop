#ifndef POINT_H
#define POINT_H
#include <string>

class Point {
private:
    double x;
    double y;

public:
    // Методи доступу (геттери та сеттери)
    void setX(double newX);
    void setY(double newY);
    double getX() const;
    double getY() const;

    // Обов'язкові методи за завданням
    void Init(double newX, double newY);
    void Read();
    void Display() const;
    std::string toString() const;

    // Специфічні методи для точки
    void moveX(double dx);
    void moveY(double dy);
    double distance(const Point& other) const;
};

#endif // POINT_H