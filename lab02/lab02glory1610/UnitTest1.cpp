#include "pch.h"
#include "CppUnitTest.h"
#include "..//Stack/Stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(PushPopTopTest)
		{
			Stack S;
			S.push(3);
			S.push(6);
			Assert::AreEqual(6, S.top());
			S.pop();
			S.pop();
			Assert::IsTrue(S.empty());
		}
		TEST_METHOD(EmptyTest)
		{
			Stack D;
			Assert::IsTrue(D.empty());
			D.push(9);
			Assert::IsFalse(D.empty());
		}
		TEST_METHOD(SizeTest)
		{
			Stack B;
			Assert::AreEqual(0, B.size());
			B.push(7);
			B.push(5);
			B.push(3);
			Assert::AreEqual(3, B.size());
		}
		TEST_METHOD(EmplaceTest)
		{
			Stack C;
			C.emplace(5);
			C.emplace(7);
			Assert::AreEqual(2, C.size());
			Assert::AreEqual(7, C.top());
		}
		TEST_METHOD(SwapTest)
		{
			Stack A;
			A.push(2);
			A.push(9);
			Stack H;
			H.push(4);
			A.swap(H);
			Assert::AreEqual(4, A.top());
		}
	};
}
