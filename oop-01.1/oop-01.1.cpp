#include "Money.h"
#include <iostream>

using namespace std;

int main() {
    // 1. Створення об'єкта через зовнішню функцію
    cout << "--- Тестування функції makeMoney ---" << endl;
    Money wallet1 = makeMoney(200, 15); // 15 купюр по 200
    wallet1.Display();
    cout << "Загальна сума: " << wallet1.summa() << " грн" << endl;

    // 2. Демонстрація методів вводу/виводу
    cout << "\n--- Тестування введення з клавіатури ---" << endl;
    Money wallet2;
    wallet2.Read();
    wallet2.Display();
    cout << "Загальна сума: " << wallet2.summa() << " грн" << endl;

    // 3. Демонстрація роботи захисту (щоб перевірити, розкоментуйте рядок нижче)
    // cout << "\n--- Тестування некоректних даних ---" << endl;
    // Money errorWallet = makeMoney(3, 10); // Викличе помилку, бо номіналу 3 не існує

    return 0;
}