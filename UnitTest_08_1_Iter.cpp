#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab_08_1/Lab_08_1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab081Iter
{
    TEST_CLASS(UnitTestLab081Iter)
    {
    public:
        TEST_METHOD(TestMethodIncludeAndChange)
        {
            char testStr1[] = "abccccde";
            Assert::IsTrue(Include(testStr1));

            char testStr2[] = "abcde";
            Assert::IsFalse(Include(testStr2));

            char testStr3[50] = "a1111b2222c";
            Change(testStr3);
            Assert::AreEqual("a**b**c", testStr3);
        }
    };
}