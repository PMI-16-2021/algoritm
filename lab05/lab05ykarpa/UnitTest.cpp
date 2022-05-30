#include "pch.h"
#include "CppUnitTest.h"
#include "..//лр5/polishNotation.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(PolishNotationTest) {
	public:
		TEST_METHOD(isOperationTest) {
			char ch1 = '+';
			Assert::IsTrue(is_operation(ch1));
			char ch2 = '-';
			Assert::IsTrue(is_operation(ch2));
			char ch3 = '*';
			Assert::IsTrue(is_operation(ch3));
			char ch4 = '/';
			Assert::IsTrue(is_operation(ch4));
			char ch5 = '%';
			Assert::IsTrue(is_operation(ch5));
			char ch6 = '^';
			Assert::IsTrue(is_operation(ch6));
			char ch7 = 'f';
			Assert::IsFalse(is_operation(ch7));
		}
		TEST_METHOD(calculateTest) {
			char ch1 = '+';
			Assert::AreEqual(calculate(2, 3, ch1), 5.0);
			char ch2 = '-';
			Assert::AreNotEqual(calculate(2, 3, ch2), 5.0);
			char ch3 = '/';
			Assert::AreNotEqual(calculate(3, 3, ch3), 3.0);
			char ch4 = '*';
			Assert::AreEqual(calculate(2, 3, ch4), 6.0);
			char ch5 = '^';
			Assert::AreNotEqual(calculate(2, 3, ch5), 9.0);
			char ch6 = '%';
			Assert::AreEqual(calculate(6, 3, ch6), 0.0);
		}
		TEST_METHOD(convertToReversedPolishNotationTest) {
			std::string str1 = "(2^3)-(5+8)";
			Assert::AreEqual(convert_to_reversed_polish_notation(str1), (std::string)"23^58+-");
		}
		TEST_METHOD(reversePolishNotationTest) {
			std::string str1 = "23^58+-";
			Assert::AreEqual(reversed_polish_notation(str1), -5.0);
			std::string str2 = "23-56-+";
			Assert::AreNotEqual(reversed_polish_notation(str1), 0.0);
		}
		TEST_METHOD(precTest) {
			char ch1 = '-';
			Assert::AreEqual(prec(ch1), 1);
			char ch2 = '/';
			Assert::AreEqual(prec(ch2), 2);
			char ch3 = '^';
			Assert::AreEqual(prec(ch3), 3);
			char ch4 = '+';
			Assert::AreNotEqual(prec(ch4), 2);
			char ch5 = '%';
			Assert::AreNotEqual(prec(ch5), 1);
			char ch6 = '*';
			Assert::AreNotEqual(prec(ch6), 1);
		}
	};
}