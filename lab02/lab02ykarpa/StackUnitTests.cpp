#include "pch.h"
#include "CppUnitTest.h"
#include "..//лр2/stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackUnitTests {
	TEST_CLASS(StackUnitTests) {
	public:
		TEST_METHOD(ConstructorTest) {
			Stack S1(6);
			Assert::AreEqual(6, S1.top());
		}
		TEST_METHOD(pushTest) {
			Stack S1;
			S1.push(10);
			Assert::AreEqual(10, S1.top());
		}
		TEST_METHOD(isEmptyTest) {
			Stack S1;
			Assert::IsTrue(S1.isEmpty());
			S1.push(5);
			Assert::IsFalse(S1.isEmpty());
		}
		TEST_METHOD(popTest) {
			Stack S1;
			S1.push(11);
			S1.push(6);
			S1.pop(); S1.pop();
			Assert::IsTrue(S1.isEmpty());
		}
		TEST_METHOD(getSizeTest) {
			Stack S1;
			S1.push(11);
			S1.push(6);
			S1.push(30);
			Assert::AreEqual(3, S1.getSize());
		}
		TEST_METHOD(topTest) {
			Stack S1;
			S1.push(11);
			Assert::AreEqual(11, S1.top());
		}
		TEST_METHOD(swapTest) {
			Stack S1;
			S1.push(11);
			Stack S2;
			S2.push(23);
			S1.swap(S2);
			Assert::AreEqual(23, S1.top());
			Assert::AreEqual(11, S2.top());
		}
		TEST_METHOD(emplaceTest) {
			Stack S1;
			int a = 10000;
			S1.emplace(a);
			Assert::AreEqual(10000, S1.top());
		}
	};
}