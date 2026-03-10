#include <iostream>
#include "Money.h"
#include "Bankomat.h"

int main() {
    try {
        std::cout << "=== Demonstrating Class 'Money' ===\n";

        // Спосіб 1: Створення об'єкта в стеку та використання Init
        Money wallet1;
        wallet1.Init(1, 0, 2, 0, 1, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0); // 500*1 + 100*2 + 20*1 + 0.50*2 = 721,00 UAH
        std::cout << "Wallet 1: "; wallet1.Display();

        // Спосіб 2: Динамічне створення об'єкта
        Money* wallet2 = new Money();
        wallet2->set100(5); // 500,00 UAH через безпечний setter
        std::cout << "Wallet 2: "; wallet2->Display();

        // Демонстрація математичних операцій
        Money sum = wallet1.Add(*wallet2);
        std::cout << "Sum (W1 + W2): " << sum.toString() << "\n";

        Money diff = wallet1.Subtract(Money()); // Віднімаємо порожній для прикладу, або можна *wallet2

        double ratio = wallet1.DivideSums(*wallet2);
        std::cout << "Ratio (W1 / W2): " << ratio << "\n";

        Money multiplied = wallet1.MultiplyFraction(1.5);
        std::cout << "W1 * 1.5: " << multiplied.toString() << "\n";

        delete wallet2;

        std::cout << "\n=== Demonstrating Class 'Bankomat' ===\n";

        // Спосіб 3: Масив об'єктів
        const int ATM_COUNT = 2;
        Bankomat atms[ATM_COUNT];

        // Ініціалізація першого банкомату
        Money initialFunds;
        initialFunds.set500(10); // 5000 UAH
        initialFunds.set100(20); // 2000 UAH
        atms[0].Init("ATM-Lviv-01", initialFunds, 100.0, 4000.0);
        atms[0].Display();

       
        atms[0].Withdraw(1500.0);

        // Демонстрація зняття готівки (помилка ліміту)
        atms[0].Withdraw(50.0); // Менше мінімального

        // Демонстрація завантаження готівки
        Money loadFunds;
        loadFunds.set200(5); // 1000 UAH
        atms[0].LoadBills(loadFunds);

        std::cout << "\n--- Manual initialization of ATM 2 ---\n";
        atms[1].Read(); 

        
        std::cout << "\n--- Result of ATM 2 initialization ---\n";
        atms[1].Display();

       
        std::cout << "\n--- Testing withdrawal from ATM 2 ---\n";
        atms[1].Withdraw(150.0); // Спробуємо зняти 150 грн

       

    }
    catch (const std::exception& e) {
        std::cerr << "Fatal Exception: " << e.what() << "\n";
    }

    return 0;
}