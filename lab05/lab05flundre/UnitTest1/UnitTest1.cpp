#include "pch.h"
#include "CppUnitTest.h"
#include "../polish.h"
#include "../polish.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
	public:
		
		TEST_METHOD(isDigit_Test) {
			char temp[10] = { '0', '1', '2', '3','4','5','6','7','8','9' };
			for (int i = 0; i < 10; ++i) {
			Assert::IsTrue(isDigit(temp[i]));
			}
		}

		TEST_METHOD(isFunc_Test) {
			char temp[5] = { '+', '-', '*', '/','^'};
			for (int i = 0; i < 5; ++i) {
				Assert::IsTrue(isFunc(temp[i]));
			}
		}

		TEST_METHOD(getPriority_Test) {
			Assert::IsTrue(1 == getPriority('+'));
			Assert::IsTrue(1 == getPriority('-'));
			Assert::IsTrue(2 == getPriority('*'));
			Assert::IsTrue(2 == getPriority('/'));
			Assert::IsTrue(3 == getPriority('^'));
			Assert::IsTrue(-1 == getPriority(' '));
		}

		TEST_METHOD(getReversedPolishNotation_Test) {
			std::string temp = "5 5 +";
			Assert::AreEqual(temp, getReversedPolishNotation("5+5"));
		}

		TEST_METHOD(calculateReversedPolishNotation_Test) {
			std::string temp = "5 5 +";
			Assert::AreEqual(10.0, calculateReversedPolishNotation("5 5 +"));
		}
		
	};
}
