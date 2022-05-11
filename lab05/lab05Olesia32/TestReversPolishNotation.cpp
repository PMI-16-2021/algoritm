#include "pch.h"
#include "CppUnitTest.h"
#include "..//Reverse Polish Notation/functions.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TestReversPolishNotation {

	TEST_CLASS(TestReversPolishNotation) {

	public:
		TEST_METHOD(IsDigitTest) {
			char digit[10] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };
			for (int  i = 0; i < 10; i++) {
				Assert::IsTrue(IsDigit(digit[i]));
			}
		}
		TEST_METHOD(IsOperatorTest) {
			char _operator[5] = { '+', '-', '*', '/', '^' };
			for (int i = 0; i < 5; i++) {
				Assert::IsTrue(IsOperator(_operator[i]));
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
			std::string expression = "(12*(9-3)-3*(5+6))/3+12";
			std::string result = ReversePolishNotation(expression);
			std::string right_answer = "12 9 3 - * 3 5 6 + * - 3 / 12 +";
			Assert::AreEqual(right_answer, result);
		}
		TEST_METHOD(AddTest) {
			std::string expression = "2 18 +";
			double result = Calculate(expression);
			Assert::AreEqual(20.0, result);
		}
		TEST_METHOD(SubtractionTest) {
			std::string expression = "2 18 -";
			double result = Calculate(expression);
			Assert::AreEqual(-16.0, result);
		}
		TEST_METHOD(MultiplicationTest) {
			std::string expression = "2 10 *";
			double result = Calculate(expression);
			Assert::AreEqual(20.0, result);
		}
		TEST_METHOD(DivisionTest) {
			std::string expression = "18 2 /";
			double result = Calculate(expression);
			Assert::AreEqual(9.0, result);
		}
		TEST_METHOD(DegreeTest) {
			std::string expression = "3 2 ^";
			double result = Calculate(expression);
			Assert::AreEqual(9.0, result);
		}
	};
}
