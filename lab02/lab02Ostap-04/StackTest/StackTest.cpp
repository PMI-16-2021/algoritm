#include "pch.h"
#include "CppUnitTest.h"
#include"..\Stack\stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace StackTest
{
	TEST_CLASS(StackTest)
	{
	public:
		TEST_METHOD(EmptyTest) {
			Stack S1;
			Assert::IsTrue(S1.Empty());
			Stack S2(8);
			Assert::IsFalse(S2.Empty());
		}

		TEST_METHOD(ConstructorsTest) {
			Stack S1;
			Assert::IsTrue(S1.Empty());
			Stack S2(3);
			Assert::AreEqual(3, S2.Top());
			S2.~Stack();
			Assert::IsTrue(S2.Empty());
		}

		TEST_METHOD(TopTest) {
			Stack S1;
			try {
				S1.Top();
			}
			catch (EmptyStackExeption& msg) {
			}
			Stack S2(8);
			Assert::AreEqual(8, S2.Top());
		}

		TEST_METHOD(PushTest) {
			Stack S(4);
			S.Push(5);
			S.Push(3);
			Assert::AreEqual(3, S.Top());
		}

		TEST_METHOD(SizeTest) {
			Stack S;
			Assert::AreEqual(0, S.Size());
			S.Push(5);
			S.Push(5);
			S.Push(3);
			Assert::AreEqual(3, S.Size());
		}

		TEST_METHOD(EmplaseTest) {
			Stack S(4);
			int s = 7;
			S.Emplace(s);
			Assert::AreEqual(7, S.Top());
		}

		TEST_METHOD(PopTest) {
			Stack S1;
			try {
				S1.Pop();
			}
			catch (EmptyStackExeption& msg) {
			}
			Stack S(1);
			S.Push(2);
			S.Push(5);
			S.Push(3);
			Assert::AreEqual(4, S.Size());
			Assert::AreEqual(3, S.Top());
			S.Pop();
			Assert::AreEqual(3, S.Size());
			Assert::AreEqual(5, S.Top());
		}

		TEST_METHOD(SwapTest) {
			Stack S1(2);
			S1.Push(4);
			Assert::AreEqual(4, S1.Top());
			Stack S2(3);
			S2.Push(6);
			S2.Push(9);
			Assert::AreEqual(9, S2.Top());

			S1.Swap(S2);
			Assert::AreEqual(4, S2.Top());
			Assert::AreEqual(9, S1.Top());
			Assert::AreEqual(3, S1.Size());
			Assert::AreEqual(2, S2.Size());
		}
	};
}
