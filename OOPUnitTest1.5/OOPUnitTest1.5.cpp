#include "pch.h"
#include "CppUnitTest.h"
#include <string>
#include "../oop-01.5/Pair.cpp" 
#include "../oop-01.5/Rectangle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ProjectTests
{
    TEST_CLASS(PairTests)
    {
    public:

        TEST_METHOD(InitializationAndValidation)
        {
            Pair p;
            p.Init(3.5, 2.0);
            // Третій параметр - це похибка для порівняння чисел з плаваючою комою (double)
            Assert::AreEqual(3.5, p.getFirst(), 0.0001);
            Assert::AreEqual(2.0, p.getSecond(), 0.0001);

            // Перевірка некоректних значень (має встановитись 1.0 за замовчуванням)
            Pair p2;
            p2.Init(-5.0, 0.0);
            Assert::AreEqual(1.0, p2.getFirst(), 0.0001);
            Assert::AreEqual(1.0, p2.getSecond(), 0.0001);
        }

        TEST_METHOD(ProductCalculation)
        {
            Pair p;
            p.Init(4.0, 2.5);
            Assert::AreEqual(10.0, p.Product(), 0.0001);
        }

        TEST_METHOD(SettersValidation)
        {
            Pair p;
            // Має повернути false при спробі встановити від'ємне число або нуль
            Assert::IsFalse(p.setFirst(-10.0));
            Assert::IsFalse(p.setSecond(0.0));

            // Має повернути true при коректних даних
            Assert::IsTrue(p.setFirst(5.0));
            Assert::AreEqual(5.0, p.getFirst(), 0.0001);
        }

        TEST_METHOD(ToStringFormat)
        {
            Pair p;
            p.Init(7.0, 8.5);
            std::string expected = "(7, 8.5)";
            Assert::AreEqual(expected, p.toString());
        }
    };

    TEST_CLASS(RectangleTests)
    {
    public:

        TEST_METHOD(AreaAndPerimeterCalculation)
        {
            Rectangle r;
            r.Init(3.0, 4.0);
            Assert::AreEqual(12.0, r.Area(), 0.0001);
            Assert::AreEqual(14.0, r.Perimeter(), 0.0001);
        }

        TEST_METHOD(ValidationFallback)
        {
            Rectangle r;
            // Якщо передати хоча б одне некоректне значення, сторони скидаються до (1.0, 1.0)
            r.Init(-3.0, 4.0);
            Assert::AreEqual(1.0, r.Area(), 0.0001);       // 1.0 * 1.0
            Assert::AreEqual(4.0, r.Perimeter(), 0.0001);  // 2 * (1.0 + 1.0)
        }

        TEST_METHOD(ToStringFormat)
        {
            Rectangle r;
            r.Init(2.0, 5.0);
            std::string expected = "Rectangle[sides=(2, 5)]";
            Assert::AreEqual(expected, r.toString());
        }
    };
}