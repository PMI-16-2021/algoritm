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
			string infix = "5+6/2";
			string postfix = "562/+";
			Assert::AreEqual(infixToPostfix(infix), postfix);
		}

		TEST_METHOD(TestAction)
		{
			string infix = "5+6/2";
			string postfix = "562/+";
			Assert::AreEqual(action(infixToPostfix(infix)), 8);
		}

		TEST_METHOD(TestIsNum)
		{
			string postfix = "879+-";
			char num = postfix[2];
			Assert::AreEqual(isNum(num), true);
		}

		TEST_METHOD(TestEmptySpace)
		{
			string postfix = "879+- ";
			char num = postfix[5];
			Assert::AreEqual(emptySpace(num), true);
		}
	};
}
