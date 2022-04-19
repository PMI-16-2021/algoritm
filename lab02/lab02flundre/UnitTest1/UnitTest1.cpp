#include "pch.h"
#include "CppUnitTest.h"
#include "/hacking/cpp/algorithms stack/Stack Realisation/Stack Realisation/Stack.h"
#include "/hacking/cpp/algorithms stack/Stack Realisation/Stack Realisation/Stack.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
	public:
		TEST_METHOD(TestEmpty) {
			Stack test_stack;
			Assert::IsTrue(test_stack.empty());
			test_stack.push(0);
			Assert::IsFalse(test_stack.empty());
		}

		TEST_METHOD(TestSize) {
			Stack test_stack;
			Assert::IsTrue(test_stack.size() == 0);
			test_stack.push(0);
			Assert::IsFalse(test_stack.size() == 0);
		}

		TEST_METHOD(TestTop) {
			Stack test_stack;
			test_stack.push(0);
			test_stack.push(1);
			Assert::IsTrue(test_stack.top() == 1);
			test_stack.pop();
			Assert::IsTrue(test_stack.top() == 0);
		}

		TEST_METHOD(TestPush) {
			Stack test_stack;
			test_stack.push(0);
			Assert::AreEqual(test_stack.top(), 0);
			test_stack.push(1);
			Assert::AreEqual(test_stack.top(), 1);
		}

		TEST_METHOD(TestEmplace) {
			Stack test_stack;
			test_stack.emplace(0);
			Assert::AreEqual(test_stack.top(), 0);
			test_stack.emplace(1);
			Assert::AreEqual(test_stack.top(), 1);
		}

		TEST_METHOD(TestPop) {
			Stack test_stack;
			test_stack.push(0);
			test_stack.push(1);
			Assert::IsTrue(test_stack.pop() == 1);
			Assert::IsTrue(test_stack.pop() == 0);
		}

		TEST_METHOD(TestSwap) {
			Stack test_stack1;
			Stack test_stack2;
			Stack test_stack3;
			test_stack1.push(0);
			test_stack1.push(1);
			test_stack1.push(2);
			test_stack1.push(3);
			test_stack2.push(3);
			test_stack2.push(2);
			test_stack2.push(1);
			test_stack2.push(0);
			test_stack3.push(3);
			test_stack3.push(2);
			test_stack3.push(1);
			test_stack3.push(0);
			test_stack1.swap(test_stack2);
			for (int i = 0; i < test_stack1.size(); ++i) {
				Assert::AreEqual(test_stack1.pop(), test_stack3.pop());
			}
		}
	};
}
