#include "pch.h"
#include "CppUnitTest.h"
#include "..\Project27\stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestIsEmptyMethod)
		{
			Stack S;
			Assert::IsTrue(S.isEmpty());
			S.push(2);
			Assert::IsFalse(S.isEmpty());
		}

		TEST_METHOD(TestIsFullMethod)
		{
			Stack S;
			Assert::IsFalse(S.isFull());
			S.push(2);
			S.push(4);
			S.push(3);
			S.push(1);
			S.push(8);
			Assert::IsTrue(S.isFull());
		}

		TEST_METHOD(TestSizeMethod) {
			Stack S;
			Assert::AreEqual(S.size(), 0);
			S.push(7);
			S.push(3);
			Assert::AreEqual(S.size(), 2);
			S.pop();
			Assert::AreEqual(S.size(), 1);
		}

		TEST_METHOD(TestShowTopMethod) {
			Stack S;
			S.push(4);
			Assert::AreEqual(S.showTop(), 4);
			S.push(9);
			S.push(1);
			Assert::AreEqual(S.showTop(), 1);
			S.pop();
			Assert::AreEqual(S.showTop(), 9);
		}

		TEST_METHOD(TestPushMethod) {
			Stack S;
			S.push(4);
			Assert::AreEqual(S.showTop(), 4);
			S.push(1);
			S.push(7);
			Assert::AreEqual(S.showTop(), 7);
			S.pop();
			Assert::AreEqual(S.showTop(), 1);
		}

		TEST_METHOD(TestEmplaceMethod) {
			Stack S;
			S.push(4);
			S.push(3);
			S.push(1);
			S.push(8);
			S.emplace(3, 5);
			Assert::AreEqual(S.showTop(), 5);
			S.emplace(2, 14);
			S.pop();
			Assert::AreEqual(S.showTop(), 14);
		}

		TEST_METHOD(TestSwapMethod) {
			Stack S;
			S.push(4);
			S.push(3);
			S.push(1);
			S.push(8);
			S.swap(2, 3);
			Assert::AreEqual(S.showTop(), 1);
			S.pop();
			Assert::AreEqual(S.showTop(), 8);
		}

		TEST_METHOD(TestPopMethod) {
			Stack S;
			S.push(4);
			S.pop();
			Assert::IsTrue(S.isEmpty());
			S.push(7);
			S.push(9);
			S.pop();
			Assert::AreEqual(S.showTop(), 7);
		}
	};
}
