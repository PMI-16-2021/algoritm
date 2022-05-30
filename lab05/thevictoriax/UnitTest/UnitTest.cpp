#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab05/polish.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(Operators)
		{
			Assert::IsTrue(operators('+'));
			Assert::IsTrue(operators('-'));
			Assert::IsTrue(operators('/'));
			Assert::IsTrue(operators('*'));
			Assert::IsTrue(operators('^'));
			Assert::IsFalse(operators('_'));
		}
		TEST_METHOD(Numbers)
		{
			Assert::IsTrue(numbers('1'));
			Assert::IsTrue(numbers('2'));
			Assert::IsTrue(numbers('3'));
			Assert::IsTrue(numbers('4'));
			Assert::IsTrue(numbers('5'));
			Assert::IsFalse(numbers('_'));
		}
		TEST_METHOD(Priority)
		{
			Assert::AreEqual(priority('+'), 1);
			Assert::AreEqual(priority('-'), 1);
			Assert::AreEqual(priority('/'), 2);
			Assert::AreEqual(priority('*'), 2);
			Assert::AreEqual(priority('^'), 3);
			Assert::AreNotEqual(priority('_'), 2);
		}
		TEST_METHOD(Reversion)
		{
			std::string sample = "2*(4+8)";
			std::string num = reversion(sample);
			std::string result = "2 4 8 + *";
			Assert::AreEqual(result, num);
		}
		TEST_METHOD(Calculation)
		{
			std::string sample = "2 4 8 + *";
			int result = calculation(sample);
			Assert::AreEqual(24, result);
		}
	};
}
