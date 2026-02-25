#ifndef MONEY_H
#define MONEY_H

class Money {
private:
    int first;  // Номінал купюри
    int second; // Кількість купюр

    // Приватний метод для перевірки коректності номіналу
    bool isValidNominal(int value) const;

public:
    // Конструктор за замовчуванням
    Money();

    // Методи зчитування (константні)
    int getFirst() const;
    int getSecond() const;

    // Методи запису (з жорстким контролем значень)
    bool setFirst(int value);
    bool setSecond(int value);

    // Метод ініціалізації
    bool Init(int f, int s);

    // Метод введення з клавіатури
    void Read();

    // Метод виведення на екран
    void Display() const;

    // Метод обчислення суми
    long long summa() const;
};

// Зовнішня функція для створення об'єкта
Money makeMoney(int f, int s);

#endif // MONEY_H