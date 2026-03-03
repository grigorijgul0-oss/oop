#include <iostream>
#include "Point.h"

int main() {
    // --- ЗАГАЛЬНІ ВИМОГИ (з першої частини завдання) ---
    std::cout << "=== GENERAL REQUIREMENTS ===" << std::endl;

    Point p1;
    // Демонстрація методу ініціалізації Init()
    p1.Init(0.0, 0.0);

    // Демонстрація методу виведення Display()
    std::cout << "1. Init() and Display() methods: ";
    p1.Display();

    // Демонстрація методу перетворення у рядок toString()
    std::cout << "2. toString() method: " << p1.toString() << std::endl;

    // Демонстрація методу введення з клавіатури Read()
    std::cout << "\n3. Read() method (Keyboard input):" << std::endl;
    Point p2;
    p2.Read();
    std::cout << "You created: ";
    p2.Display();


    // --- ВИМОГИ ТВОГО ВАРІАНТУ (робота з точками) ---
    std::cout << "\n=== VARIANT REQUIREMENTS ===" << std::endl;

    // Визначення відстані між двома точками
    std::cout << "1. Distance between your point and (0, 0): " << p2.distance(p1) << std::endl;

    // Переміщення точки по осі X та Y
    std::cout << "2. Moving your point (X +10, Y -5)..." << std::endl;
    p2.moveX(10.0);
    p2.moveY(-5.0);

    // Виводимо результат після переміщення
    std::cout << "Result after moving: ";
    p2.Display();


    // --- ДЕМОНСТРАЦІЯ МАСИВІВ (остання вимога завдання) ---
    std::cout << "\n=== ARRAY DEMONSTRATION ===" << std::endl;
    Point arr[2];
    arr[0].Init(1, 1);
    arr[1].Init(2, 2);
    std::cout << "Array points: " << arr[0].toString() << " and " << arr[1].toString() << std::endl;

    return 0;
}