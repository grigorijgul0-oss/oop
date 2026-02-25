#include "Money.h"
#include <iostream>
#include <cstdlib> // Для функції exit()

using namespace std;

// Ініціалізація безпечними значеннями за замовчуванням
Money::Money() : first(1), second(1) {}

// Перевірка допустимого номіналу
bool Money::isValidNominal(int value) const {
    int validNominals[] = { 1, 2, 5, 10, 20, 50, 100, 200, 500 };
    for (int i = 0; i < 9; ++i) {
        if (value == validNominals[i]) {
            return true;
        }
    }
    return false;
}

// Константні методи доступу (зчитування)
int Money::getFirst() const {
    return first;
}

int Money::getSecond() const {
    return second;
}

// Методи запису з контролем
bool Money::setFirst(int value) {
    if (isValidNominal(value)) {
        first = value;
        return true;
    }
    else {
        cout << "Помилка: Неіснуючий номінал купюри!" << endl;
        return false;
    }
}

bool Money::setSecond(int value) {
    if (value > 0) {
        second = value;
        return true;
    }
    else {
        cout << "Помилка: Кількість купюр має бути додатним числом!" << endl;
        return false;
    }
}

// Метод ініціалізації полів
bool Money::Init(int f, int s) {
    // Якщо обидва параметри коректні, ініціалізуємо
    if (isValidNominal(f) && s > 0) {
        first = f;
        second = s;
        return true;
    }
    return false;
}

// Введення з клавіатури з циклом до правильного вводу
void Money::Read() {
    int f, s;
    do {
        cout << "Введіть номінал купюри (1, 2, 5, 10, 20, 50, 100, 200, 500): ";
        cin >> f;
        cout << "Введіть кількість купюр: ";
        cin >> s;
        if (!isValidNominal(f) || s <= 0) {
            cout << "Некоректні дані! Спробуйте ще раз.\n";
        }
    } while (!Init(f, s));
}

// Виведення на екран
void Money::Display() const {
    cout << "Номінал: " << first << " грн, Кількість: " << second << " шт." << endl;
}

// Обчислення суми
long long Money::summa() const {
    return (long long)first * second;
}

// Зовнішня функція, яка створює об'єкт
Money makeMoney(int f, int s) {
    Money m;
    if (!m.Init(f, s)) {
        cout << "Критична помилка (makeMoney): передано невірні аргументи (" << f << ", " << s << "). Роботу завершено." << endl;
        exit(1); // Примусове завершення роботи програми при помилці
    }
    return m;
}