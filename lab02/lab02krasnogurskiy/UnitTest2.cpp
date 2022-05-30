#include "pch.h"
#include "CppUnitTest.h"
#include"..//lab02/stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(PushPopTest)
		{
			Stack S;
			S.push(3);
			S.push(6);
			Assert::AreEqual(6, S.topVal());
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
			Stack B(1);
			Assert::AreEqual(B.size(), 0);
		}
		TEST_METHOD(TopValTest)
		{
			Stack C(2);
			Assert::AreEqual(2, C.topVal());
		}
		TEST_METHOD(SwapTest)
		{
			Stack A;
			A.push(2);
			A.push(9);
			Stack H;
			H.push(4);
			A.swap(H);
			Assert::AreEqual(4, A.topVal());
		}
	};
}
