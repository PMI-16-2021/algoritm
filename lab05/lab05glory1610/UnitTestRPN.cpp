#include "pch.h"
#include "CppUnitTest.h"
#include "..//ReservedPN/Function.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestRPN
{
	TEST_CLASS(UnitTestRPN)
	{
	public:
		
		TEST_METHOD(TestIsOperator)
		{
			char a = '+';
			char b = '-';
			char v = '/';
			char d = '*';
			Assert::IsTrue(isOperator(a));
			Assert::IsTrue(isOperator(b));
			Assert::IsTrue(isOperator(v));
			Assert::IsTrue(isOperator(d));
		}
		TEST_METHOD(TestIsDigit)
		{
			char n = '5';
			Assert::IsTrue(isDigit(n));
		}
		TEST_METHOD(TestPriority)
		{
			char a = '+';
			Assert::AreEqual(priority(a), 1);
			char b = '-';
			Assert::AreEqual(priority(b), 1);
			char v = '/';
			Assert::AreEqual(priority(v), 2);
			char d = '*';
			Assert::AreEqual(priority(d), 2);
		}
		TEST_METHOD(TestReversed)
		{
			std::string exp = "(5-4)*10";
			std::string res = ReversePN(exp);
			std::string result = "5 4 - 10 *";
			Assert::AreEqual(result, res);
		}
		TEST_METHOD(TestAddition)
		{
			std::string exp = "5 4 +";
			double result = calculate(exp);
			Assert::AreEqual(9.0, result);
		}
		TEST_METHOD(TestSubtraction)
		{
			std::string exp = "5 4 -";
			double result = calculate(exp);
			Assert::AreEqual(1.0, result);
		}
		TEST_METHOD(TestMultiplication)
		{
			std::string exp = "5 4 *";
			double result = calculate(exp);
			Assert::AreEqual(20.0, result);
		}
		TEST_METHOD(TestDivision)
		{
			std::string exp = "10 2 /";
			double result = calculate(exp);
			Assert::AreEqual(5.0, result);
		}
	};
}
