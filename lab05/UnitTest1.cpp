#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Project33\polish.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
        TEST_METHOD(IsOperatorTest)
        {
            Assert::IsTrue(isOperator('+'));
            Assert::IsTrue(isOperator('-'));
            Assert::IsTrue(isOperator('/'));
            Assert::IsFalse(isOperator('^'));
            Assert::IsFalse(isOperator('%'));
        }
        TEST_METHOD(IsNumberTest)
        {
            Assert::IsTrue(isNumber('0'));
            Assert::IsTrue(isNumber('4'));
            Assert::IsTrue(isNumber('1'));
            Assert::IsFalse(isNumber('+'));
            Assert::IsFalse(isNumber('-'));
        }
        TEST_METHOD(PriorityTest)
        {
            Assert::AreEqual(priority('('), 0);
            Assert::AreEqual(priority('+'), 1);
            Assert::AreEqual(priority('-'), 1);
            Assert::AreEqual(priority('*'), 2);
            Assert::AreEqual(priority('3'), -1);
            Assert::AreEqual(priority('^'), -1);
        }
        TEST_METHOD(PolishRecordTest) {
            std::string expression = "3*((14+6)/4)*2-4";
            std::string exp = polishRecord(expression);
            std::string result = "3 14 6 + 4 / * 2 * 4 -";
            Assert::AreEqual(result, exp);
        }
        TEST_METHOD(CalculateTest) {
            std::string expression = "3 14 6 + 4 / * 2 * 4 -";
            double result = calculate(expression);
            Assert::AreEqual(26.0, result);
        }
	};
}
