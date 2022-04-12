#include "pch.h"
#include "CppUnitTest.h"
#include "../lab02/stack.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(Constructors)
		{
			Stack stk1;
			Assert::IsTrue(stk1.isEmpty());

			Stack stk2;
			stk2.push(4);
			Assert::IsFalse(stk2.isEmpty());
		}
		
		TEST_METHOD(Size)
		{
			Stack stk1;
			Assert::AreEqual(0, stk1.size());

			Stack stk2;
			stk2.push(7);
			Assert::AreEqual(1, stk2.size());
		}
		
		TEST_METHOD(TopElement)
		{
			Stack stk1;
			stk1.push(3);
			Assert::AreEqual(3, stk1.topElement());
			stk1.push(7);
			Assert::AreEqual(7, stk1.topElement());
		}
		
		TEST_METHOD(Push)
		{
			Stack stk;
			stk.push(5);
			Assert::AreEqual(5, stk.topElement());
			stk.push(7);
			Assert::AreEqual(7, stk.topElement());
		}
		
		TEST_METHOD(Pop)
		{
			Stack stk;
			stk.push(5);
			stk.pop();
			Assert::IsTrue(stk.isEmpty());
		}
		
		TEST_METHOD(Emplace)
		{
			Stack stk;
			stk.push(7);
			Assert::AreEqual(7, stk.topElement());
			stk.push(10);
			Assert::AreEqual(10, stk.topElement());
		}
		
		TEST_METHOD(Swap)
		{
			Stack stk;
			stk.push(1);
			stk.push(2);
			stk.push(3);

			stk.swap(1, 2);
			Assert::AreEqual(2, stk.topElement());
		}
	};
}
