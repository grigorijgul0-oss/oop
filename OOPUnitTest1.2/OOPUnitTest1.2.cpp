#include "pch.h"
#include "CppUnitTest.h"
#include "../oop-01.2/Circle.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace CircleTests
{
    TEST_CLASS(CircleTests)
    {
    private:
        // Constant for Pi and tolerance for double comparisons
        const double PI = 3.141592653589793;
        const double TOLERANCE = 0.0001;

    public:

        // Test 1: Check valid initialization
        TEST_METHOD(TestInitValid)
        {
            Circle c;
            Assert::IsTrue(c.Init(2.5, -3.0, 5.0));
            Assert::AreEqual(2.5, c.getX(), TOLERANCE);
            Assert::AreEqual(-3.0, c.getY(), TOLERANCE);
            Assert::AreEqual(5.0, c.getR(), TOLERANCE);
        }

        // Test 2: Check initialization with invalid radius (zero or negative)
        TEST_METHOD(TestInitInvalidRadius)
        {
            Circle c;
            Assert::IsFalse(c.Init(0.0, 0.0, 0.0)); // Radius cannot be 0
            Assert::IsFalse(c.Init(1.0, 1.0, -5.0)); // Radius cannot be negative
        }

        // Test 3: Check setters (modifiers)
        TEST_METHOD(TestSetters)
        {
            Circle c;

            // Coordinates can be any number
            Assert::IsTrue(c.setX(10.5));
            Assert::IsTrue(c.setY(-20.5));

            // Testing valid and invalid radius
            Assert::IsTrue(c.setR(7.5));
            Assert::IsFalse(c.setR(-3.0));
        }

        // Test 4: Check area calculation
        TEST_METHOD(TestArea)
        {
            Circle c;
            c.Init(0.0, 0.0, 10.0);

            double expectedArea = PI * 10.0 * 10.0;
            Assert::AreEqual(expectedArea, c.area(), TOLERANCE);
        }

        // Test 5: Check circumference calculation
        TEST_METHOD(TestCircumference)
        {
            Circle c;
            c.Init(0.0, 0.0, 5.0);

            double expectedCircumference = 2 * PI * 5.0;
            Assert::AreEqual(expectedCircumference, c.circumference(), TOLERANCE);
        }

        // Test 6: Check external creation function
        TEST_METHOD(TestMakeCircle)
        {
            Circle c = makeCircle(1.0, 2.0, 3.0);

            Assert::AreEqual(1.0, c.getX(), TOLERANCE);
            Assert::AreEqual(2.0, c.getY(), TOLERANCE);
            Assert::AreEqual(3.0, c.getR(), TOLERANCE);
        }
    };
}