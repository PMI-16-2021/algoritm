#include "pch.h"
#include "CppUnitTest.h"
#include "../Polish/postfix.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPolish
{
	TEST_CLASS(UnitTestPolish)
	{
	public:
		
		TEST_METHOD(IsDigitalTest) {
			char digit[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
			for (int i = 0; i < 10; i++) {
				Assert::IsTrue(IsDigital(digit[i]));
			}
		}
		TEST_METHOD(IsOperatorTest) {
			char oper[5] = { '+', '-', '*', '/', '^' };
			for (int i = 0; i < 5; i++) {
				Assert::IsTrue(IsOperator(oper[i]));
			}
		}
		TEST_METHOD(PriorityTest) {
			Assert::AreEqual(Priority('+'), 1);
			Assert::AreEqual(Priority('-'), 1);
			Assert::AreEqual(Priority('*'), 2);
			Assert::AreEqual(Priority('/'), 2);
			Assert::AreEqual(Priority('^'), 3);
		}
		TEST_METHOD(ConvecterTest) {
			std::string expr = "(10-4)+4*4";
			std::string result = ToPostfix(expr);
			std::string correct = "10 4 - 4 4 *+";
			Assert::AreEqual(correct, result);
		}
		TEST_METHOD(AddTest) {
			std::string expr = "12 4 +";
			double result = Calculate(expr);
			Assert::AreEqual(16.0, result);
		}
		TEST_METHOD(SubtractionTest) {
			std::string expr = "12 4 -";
			double result = Calculate(expr);
			Assert::AreEqual(8.0, result);
		}
		TEST_METHOD(MultiplicationTest) {
			std::string expr = "12 4 *";
			double result = Calculate(expr);
			Assert::AreEqual(48.0, result);
		}
		TEST_METHOD(DivisionTest) {
			std::string expr = "12 4 /";
			double result = Calculate(expr);
			Assert::AreEqual(3.0, result);
		}
		TEST_METHOD(DegreeTest) {
			std::string expression = "2 3 ^";
			double result = Calculate(expression);
			Assert::AreEqual(8.0, result);
		}
	};
}
