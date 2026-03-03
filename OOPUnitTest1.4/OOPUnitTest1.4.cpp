#include "pch.h"
#include "CppUnitTest.h"
// ТУТ ВАЖЛИВО: вкажи правильний шлях до твого файлу Address.h
// Якщо він лежить у сусідній папці проєкту (наприклад, oop-01.3), шлях буде таким:
#include "../oop-1.4/Adress.cpp" 

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace std;

namespace AddressTests
{
    TEST_CLASS(AddressTests)
    {
    public:

        TEST_METHOD(TestDefaultConstructor)
        {
            // Перевіряємо, чи конструктор задає безпечні значення за замовчуванням
            Address addr;
            Assert::AreEqual(string("Unknown"), addr.getCity());
            Assert::AreEqual(string("Unknown"), addr.getStreet());
            Assert::AreEqual(string("Unknown"), addr.getBuilding());
            Assert::AreEqual(string("00000"), addr.getZipCode());
        }

        TEST_METHOD(TestSettersValidData)
        {
            // Перевіряємо нормальне заповнення полів
            Address addr;
            addr.setCity("Kyiv");
            addr.setStreet("Khreshchatyk");
            addr.setBuilding("1A");
            addr.setZipCode("01001");

            Assert::AreEqual(string("Kyiv"), addr.getCity());
            Assert::AreEqual(string("Khreshchatyk"), addr.getStreet());
            Assert::AreEqual(string("1A"), addr.getBuilding());
            Assert::AreEqual(string("01001"), addr.getZipCode());
        }

        TEST_METHOD(TestSettersInvalidData)
        {
            // Перевіряємо ЗАХИСТ від некоректних даних (порожні рядки)
            Address addr;

            addr.setCity(""); // Пробуємо передати порожній рядок
            Assert::AreEqual(string("Unknown"), addr.getCity()); // Клас має заблокувати це і поставити Unknown

            addr.setZipCode("12"); // Пробуємо передати короткий індекс
            Assert::AreEqual(string("00000"), addr.getZipCode()); // Має скинутися до дефолтного
        }

        TEST_METHOD(TestInitMethod)
        {
            // Перевіряємо метод Init
            Address addr;
            addr.Init("Lviv", "Franka", "10", "79005");

            Assert::AreEqual(string("Lviv"), addr.getCity());
            Assert::AreEqual(string("Franka"), addr.getStreet());
            Assert::AreEqual(string("10"), addr.getBuilding());
            Assert::AreEqual(string("79005"), addr.getZipCode());
        }

        TEST_METHOD(TestToStringMethod)
        {
            // Перевіряємо правильність формування рядка
            Address addr;
            addr.Init("Odessa", "Main", "5", "65000");
            string expected = "[Zip: 65000 | City: Odessa | Street: Main | Bldg: 5]";

            Assert::AreEqual(expected, addr.toString());
        }
    };
}