#include "pch.h"
#include "CppUnitTest.h"
#include "Money.h" // Include the header file of our class

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MoneyTests
{
    TEST_CLASS(MoneyTests)
    {
    public:

        // Test 1: Check valid initialization
        TEST_METHOD(TestInitValid)
        {
            Money m;
            Assert::IsTrue(m.Init(100, 5));
            Assert::AreEqual(100, m.getFirst());
            Assert::AreEqual(5, m.getSecond());
        }

        // Test 2: Check initialization with invalid denomination
        TEST_METHOD(TestInitInvalidNominal)
        {
            Money m;
            Assert::IsFalse(m.Init(7, 10)); // 7 is not a valid banknote
        }

        // Test 3: Check initialization with invalid count
        TEST_METHOD(TestInitInvalidCount)
        {
            Money m;
            Assert::IsFalse(m.Init(50, -3)); // Negative count is invalid
        }

        // Test 4: Check setters (modifiers)
        TEST_METHOD(TestSetters)
        {
            Money m;
            // Testing valid inputs
            Assert::IsTrue(m.setFirst(200));
            Assert::IsTrue(m.setSecond(15));

            // Testing invalid inputs
            Assert::IsFalse(m.setFirst(3));
            Assert::IsFalse(m.setSecond(0));
        }

        // Test 5: Check sum calculation
        TEST_METHOD(TestSumma)
        {
            Money m;
            m.Init(500, 4); // 4 banknotes of 500 UAH
            Assert::AreEqual(2000LL, m.summa()); // LL stands for long long
        }

        // Test 6: Check external creation function
        TEST_METHOD(TestMakeMoney)
        {
            Money m = makeMoney(20, 7);
            Assert::AreEqual(20, m.getFirst());
            Assert::AreEqual(7, m.getSecond());
            Assert::AreEqual(140LL, m.summa());
        }
    };
}