#include "pch.h"
#include "CppUnitTest.h"
#include"..\Lab05_PolishRecord\PolishNotation.h"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPolishNotation
{
	TEST_CLASS(UnitTestPolishNotation)
	{
	public:
		
		TEST_METHOD(Test_Priority)
		{
			Assert::AreEqual(Priority('+'), 1);
			Assert::AreEqual(Priority('-'), 1);
			Assert::AreEqual(Priority('*'), 2);
			Assert::AreEqual(Priority('/'), 2);
			Assert::AreEqual(Priority('^'), 3);
		}
		TEST_METHOD(Test_Operation)
		{
			Assert::IsTrue(Operation('+'));
			Assert::IsTrue(Operation('-'));
			Assert::IsTrue(Operation('/'));
			Assert::IsTrue(Operation('*'));
			Assert::IsFalse('1');
		}
		TEST_METHOD(Test_Number)
		{
			Assert::IsTrue(Number('0'));
			Assert::IsTrue(Number('1'));
			Assert::IsTrue(Number('2'));
			Assert::IsTrue(Number('3'));
			Assert::IsTrue(Number('4'));
			Assert::IsTrue(Number('5'));
			Assert::IsTrue(Number('6'));
			Assert::IsTrue(Number('7'));
			Assert::IsTrue(Number('8'));
			Assert::IsTrue(Number('9'));
			Assert::IsTrue(Number('/'));
		}
		TEST_METHOD(Test_Counting)
		{
			Assert::AreEqual(Counting("12+12"), 24.0);
			Assert::AreEqual(Counting("6*4"), 24.0);
			Assert::AreEqual(Counting("48/2"), 24.0);
			Assert::AreEqual(Counting("26-2"), 24.0);
			Assert::AreEqual(Counting("3^3"), 27.0);
		}
	};
}
