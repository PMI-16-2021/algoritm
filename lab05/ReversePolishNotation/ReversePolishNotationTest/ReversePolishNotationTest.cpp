#include "pch.h"
#include "CppUnitTest.h"
#include "..\\stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace ReversePolishNotationTest
{
	TEST_CLASS(ReversePolishNotationTest)
	{
	public:

		TEST_METHOD(TestInfixToPostfix)
		{
			std::string infix = "(5+5)/2*3+(7-2)";
			std::string postfix = "5 5 + 2 / 3 * 7 2 - +";
			Assert::AreEqual(infixToPostfix(infix), postfix);
		}

		TEST_METHOD(TestAction)
		{
			std::string infix = "(5+5)/2*3+(7-2)";
			Assert::AreEqual(action(infixToPostfix(infix)), 20.);
		}

		TEST_METHOD(TestIsNum)
		{
			std::string postfix = "879+-";
			char num = postfix[2];
			Assert::AreEqual(isNum(num), true);
		}

		TEST_METHOD(TestIsOperator)
		{
			std::string postfix = "879+-";
			char myOperator = postfix[3];
			Assert::AreEqual(isOperator(myOperator), true);
		}
	};
}
