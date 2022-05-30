#include "pch.h"
#include "CppUnitTest.h"
#include "..//polish/polish.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestpolish
{
	TEST_CLASS(UnitTestpolish)
	{
	public:
		
		TEST_METHOD(isDigit)
		{
			Assert::IsTrue(is_digit('6'));
			Assert::IsTrue(is_digit('2'));
			Assert::IsTrue(is_digit('9'));
			Assert::IsFalse(is_digit('+'));
		}
		TEST_METHOD(postfix)
		{
			char* p = "2+6+8*9";
			std::string res = to_postfix(p);
			std::string mustBeRes = "26+89*+";
			Assert::AreEqual(mustBeRes, res);
		}
		TEST_METHOD(calc)
		{
			std::string p = "26+89*+";
			size_t u = calc(p);
			Assert::AreEqual(80, u);
		}
		TEST_METHOD(isOperator)
		{
			Assert::IsTrue(is_operator('+'));
			Assert::IsTrue(is_operator('-'));
			Assert::IsTrue(is_operator('/'));
			Assert::IsTrue(is_operator('*'));
			Assert::IsFalse(is_operator('8'));
		}
		TEST_METHOD(compareOperators)
		{
			size_t r1 = -1;
			size_t r2 = 1;
			size_t r3 = 0;
			Assert::AreEqual(r1, compare_operators('*','+'));
			Assert::AreEqual(r2, compare_operators('-', '/'));
			Assert::AreEqual(r3, compare_operators('-', '+'));
		}
		TEST_METHOD(isOperand)
		{
			Assert::IsTrue(is_operand('8'));
			Assert::IsFalse(is_operand('('));
		}
	};
}
