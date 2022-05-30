#include "pch.h"
#include "CppUnitTest.h"
#include"../polish.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolishTest
{
	TEST_CLASS(PolishTest)
	{
	public:
		TEST_METHOD(GetPriorityTest) {
			Assert::AreEqual(0, GetPriority('^'));
			Assert::AreEqual(1, GetPriority('('));
			Assert::AreEqual(1, GetPriority(')'));
			Assert::AreEqual(2, GetPriority('*'));
			Assert::AreEqual(2, GetPriority('/'));
			Assert::AreEqual(3, GetPriority('+'));
			Assert::AreEqual(3, GetPriority('-'));
			Assert::AreEqual(-1, GetPriority('%'));
		}
		TEST_METHOD(IsDigitTest) {
			char digit[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
			for (int i = 0; i < 10; i++) {
				Assert::IsTrue(IsDigit(digit[i]));
			}
			Assert::IsTrue(IsDigit('0'));
			Assert::IsTrue(IsDigit('9'));
			Assert::IsTrue(IsDigit('1'));
			Assert::IsTrue(IsDigit('4'));
			Assert::IsTrue(IsDigit('6'));
			IsDigit('20');
			Assert::Fail;
		}
		TEST_METHOD(IsOperatorTest) {
			Assert::IsTrue(IsOperator('^'));
			Assert::IsTrue(IsOperator('*'));
			Assert::IsTrue(IsOperator('/'));
			Assert::IsTrue(IsOperator('+'));
			Assert::IsTrue(IsOperator('-'));
			Assert::IsFalse(IsOperator('%'));
		}
		TEST_METHOD(PolishRecordTest) {
			std::string temp = "2 3 *5 -9 *3 /";
			Assert::AreEqual(PolishRecord("(2*3-5)*9/3"), temp);
		}
		TEST_METHOD(CalculateTest) {
			int result = 3;
			std::string temp = "(2*3-5)*9/3";
			Assert::AreEqual(Calculate(PolishRecord(temp)), result);
		}
	};
}
