#include "pch.h"
#include "CppUnitTest.h"
#include <stdexcept>

#include "../oop-01.7/Money.cpp" 
#include "../oop-01.7/Bankomat.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace BankomatTests
{
    // --- Тестування класу Money ---
    TEST_CLASS(MoneyTests)
    {
    public:

        TEST_METHOD(TestInitAndToString)
        {
            Money m;
            // Ініціалізуємо: 1 по 500 грн і 2 по 50 коп
            m.Init(1, 0, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0);

            // Очікуємо 501,00 UAH
            Assert::AreEqual(std::string("501,00 UAH"), m.toString());
        }

        TEST_METHOD(TestNegativeValueThrowsException)
        {
            Money m;
            // Перевіряємо, що спроба встановити від'ємну кількість купюр кидає виняток
            auto func = [&] { m.set100(-5); };
            Assert::ExpectException<std::invalid_argument>(func);
        }

        TEST_METHOD(TestAddition)
        {
            Money m1, m2;
            m1.set100(2); // 200 UAH
            m2.set50(1);  // 50 UAH

            Money sum = m1.Add(m2);
            Assert::AreEqual(std::string("250,00 UAH"), sum.toString());
        }

        TEST_METHOD(TestSubtractionLogicError)
        {
            Money m1, m2;
            m1.set10(1); // 10 UAH
            m2.set100(1); // 100 UAH

            // Віднімання більшої суми від меншої має кинути помилку логіки
            auto func = [&] { m1.Subtract(m2); };
            Assert::ExpectException<std::logic_error>(func);
        }
    };

    // --- Тестування класу Bankomat ---
    TEST_CLASS(BankomatCoreTests)
    {
    public:

        TEST_METHOD(TestSuccessfulWithdrawal)
        {
            Bankomat atm;
            Money initial;
            initial.set100(10); // 1000 UAH
            atm.Init("ATM-1", initial, 50.0, 5000.0);

            // Знімаємо 200 грн
            atm.Withdraw(200.0);

            // Залишок має бути 800 грн
            Assert::AreEqual(std::string("800,00 UAH"), atm.toString());
        }

        TEST_METHOD(TestWithdrawalOutOfBoundsLeavesBalanceUnchanged)
        {
            Bankomat atm;
            Money initial;
            initial.set100(10); // 1000 UAH
            atm.Init("ATM-2", initial, 100.0, 500.0); // Ліміт 100 - 500

            // Спроба зняти більше ліміту (наприклад 600)
            atm.Withdraw(600.0);

            // Баланс не повинен змінитися
            Assert::AreEqual(std::string("1000,00 UAH"), atm.toString());
        }

        TEST_METHOD(TestLoadBills)
        {
            Bankomat atm;
            Money initial;
            initial.set50(2); // 100 UAH
            atm.Init("ATM-3", initial, 10.0, 1000.0);

            Money load;
            load.set500(1); // Додаємо 500 UAH

            atm.LoadBills(load);

            Assert::AreEqual(std::string("600,00 UAH"), atm.toString());
        }
    };
}