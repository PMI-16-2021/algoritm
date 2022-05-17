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

		TEST_METHOD(TestSizeMethod) {
			Stack S;
			Assert::AreEqual(0, S.size());
			S.push(7);
			S.push(3);
			Assert::AreEqual(2, S.size());
			S.pop();
			Assert::AreEqual(1, S.size());
		}

		TEST_METHOD(TestShowTopMethod) {
			Stack S;
			S.push(4);
			Assert::AreEqual(4, S.showTop());
			S.push(9);
			S.push(1);
			Assert::AreEqual(1, S.showTop());
			S.pop();
			Assert::AreEqual(9, S.showTop());
		}

		TEST_METHOD(TestPushMethod) {
			Stack S;
			S.push(4);
			Assert::AreEqual(4, S.showTop());
			S.push(1);
			S.push(7);
			Assert::AreEqual(7, S.showTop());
			S.pop();
			Assert::AreEqual(1, S.showTop());
		}

		TEST_METHOD(TestEmplaceMethod) {
			Stack S;
			int a = 14;
			S.emplace(a);
			Assert::AreEqual(14, S.showTop());
			int b = 16;
			S.emplace(b);
			Assert::AreEqual(16, S.showTop());
		}

		TEST_METHOD(TestSwapMethod) {
			Stack S1;
			S1.push(4);
			Stack S2;
			S2.push(13);
			S1.swap(S2);
			Assert::AreEqual(13, S1.showTop());
			Assert::AreEqual(4, S2.showTop());
		}

		TEST_METHOD(TestPopMethod) {
			Stack S;
			S.push(4);
			S.pop();
			Assert::IsTrue(S.isEmpty());
			S.push(7);
			S.push(9);
			S.pop();
			Assert::AreEqual(7, S.showTop());
		}
	};
}
