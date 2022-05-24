#include "pch.h"
#include "CppUnitTest.h"
#include "..//Project5/polish.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolishUnitTest
{
	TEST_CLASS(PolishUnitTest)
	{
	public:
		
		TEST_METHOD(TestIsNumber)
		{
			const int size = 10;
			char number[size] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
			for (int i = 0; i < size; i++) {
				Assert::IsTrue(isNumber(number[i]));
			}
			Assert::IsFalse(isNumber('a'));
			Assert::IsFalse(isNumber('^'));
		}
		TEST_METHOD(TestIsOperator)
		{
			Assert::IsTrue(isOperator('+'));
			Assert::IsTrue(isOperator('-'));
			Assert::IsTrue(isOperator('*'));
			Assert::IsTrue(isOperator('/'));
			Assert::IsTrue(isOperator('^'));

			Assert::IsFalse(isOperator('a'));
			Assert::IsFalse(isOperator('3'));
		}
		TEST_METHOD(TestPriority)
		{
			Assert::AreEqual(priority('^'), 3);
			Assert::AreEqual(priority('*'), 2);
			Assert::AreEqual(priority('/'), 2);
			Assert::AreEqual(priority('+'), 1);
			Assert::AreEqual(priority('1'), -1);
			Assert::AreEqual(priority('a'), -1);
		}
		TEST_METHOD(TestReversePolish)
		{
			std::string expression = "(5+6)*2-4/2+1";
			std::string reverse = reversePolish(expression);
			std::string result = "5 6 + 2 * 4 2 / - 1 +";
			Assert::AreEqual(reverse, result);
		}
		TEST_METHOD(TestCalculate)
		{
			std::string expression = "5 6 + 2 * 4 2 / - 1 +";
			Assert::AreEqual(21.0, calculate(expression));
		}

	};
}
