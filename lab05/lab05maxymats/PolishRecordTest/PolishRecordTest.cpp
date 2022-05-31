#include "pch.h"
#include "CppUnitTest.h"
#include "../PolishRecord/PolishRecord.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PolishRecordTest
{
	TEST_CLASS(PolishRecordTest)
	{
	public:
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
				std::string expression = "(4+3)*6-4/2+1";
				std::string reverse = reversePolish(expression);
				std::string result = "4 3 + 2 * 6 2 / - 1 +";
				Assert::AreEqual(reverse, result);
			}
			TEST_METHOD(TestCalculate)
			{
				std::string expression = "4 3 + 6 * 4 2 / - 1 +";
				Assert::AreEqual(21.0, calculate(expression));
			}

		};
	}
