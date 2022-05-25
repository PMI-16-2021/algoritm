#include "pch.h"
#include "CppUnitTest.h"
#include "..//Stack/stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Test {
	TEST_CLASS(Test) {
	public:
		TEST_METHOD(ConstructorTest) {
			Stack<double> S1(6.0);
			Assert::AreEqual(6.0, S1.Top());
		}
		TEST_METHOD(PushTest) {
			Stack<int> S1;
			S1.Push(10);
			Assert::AreEqual(10, S1.Top());
		}
		TEST_METHOD(IsEmptyTest) {
			Stack<int> S1;
			Assert::IsTrue(S1.IsEmpty());
			S1.Push(5);
			Assert::IsFalse(S1.IsEmpty());
		}
		TEST_METHOD(PopTest) {
			Stack<int> S1;
			S1.Push(11);
			S1.Push(6);
			Assert::AreEqual(6, S1.Pop());
		}
		TEST_METHOD(SizeTest) {
			Stack<int> S1;
			S1.Push(11);
			S1.Push(6);
			S1.Push(30);
			Assert::AreEqual(3, S1.Size());
		}
		TEST_METHOD(TopTest) {
			Stack<int> S1;
			S1.Push(11);
			Assert::AreEqual(11, S1.Top());
		}
		TEST_METHOD(SwapTest) {
			Stack<int> S1;
			S1.Push(11);
			Stack<int> S2;
			S2.Push(23);
			S1.Swap(S2);
			Assert::AreEqual(23, S1.Top());
			Assert::AreEqual(11, S2.Top());
		}
		TEST_METHOD(EmplaceTest) {
			Stack<int> S1;
			int a = 10000;
			S1.Emplace(a);
			Assert::AreEqual(10000, S1.Top());
		}
		TEST_METHOD(EmptyTest) {
			Stack<int> S1(9);
			S1.Push(11);
			S1.Push(6);
			S1.Push(10);
			S1.Empty();
			Assert::IsTrue(S1.IsEmpty());
		}
	};

}