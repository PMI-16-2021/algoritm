#include "pch.h"
#include "CppUnitTest.h"
#include "..//stack/stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackUnitTest
{
	TEST_CLASS(StackUnitTest)
	{
	public:

		TEST_METHOD(TestConstructors) {
			Stack stk;
			Assert::IsTrue(stk.isEmpty());
			stk.push(1);
			Assert::IsFalse(stk.isEmpty());
			Assert::AreEqual(1, stk.top());
		}

		TEST_METHOD(TestTop) { 
			Stack stk;
			stk.push(5);
			Assert::AreEqual(5, stk.top());
			stk.push(10);
			Assert::AreEqual(10, stk.top());
		}

		TEST_METHOD(TestPush) {
			Stack stk;
			stk.push(1);
			Assert::AreEqual(1, stk.top());
			stk.push(2);
			Assert::AreEqual(2, stk.top());
		}

		TEST_METHOD(TestPop) {
			Stack stk;
			stk.push(1);
			stk.push(2);
			stk.pop();
			Assert::AreEqual(1, stk.top());
			stk.pop();
			Assert::IsTrue(stk.isEmpty());
		}

		TEST_METHOD(TestEmplace) {
			Stack stk;
			stk.push(1);
			Assert::AreEqual(1, stk.top());
			stk.push(2);
			Assert::AreEqual(2, stk.top());
		}

		TEST_METHOD(TestSize) {
			Stack stk;
			Assert::AreEqual(0, stk.size());

			Stack stk2;
			stk2.push(10);
			Assert::AreEqual(1, stk2.size());
		}

		TEST_METHOD(TestEmpty) {
			Stack stk;
			Assert::IsTrue(stk.isEmpty());
			stk.push(1);
			Assert::IsFalse(stk.isEmpty());
		}

		TEST_METHOD(TestSwap) {
			Stack stk;
			stk.push(1);
			stk.push(2);
			stk.push(3);

			stk.swap(1, 2);
			Assert::AreEqual(2, stk.top());
		}
	};
}
