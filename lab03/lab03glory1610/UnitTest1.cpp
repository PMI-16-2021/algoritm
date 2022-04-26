#include "pch.h"
#include "CppUnitTest.h"
#include "..//PriorityQueue/PrQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(EnqueueDequeueMethod)
		{
			PriorityQueue P;
			P.enqueue(5, 4);
			P.enqueue(4, 3);
			P.enqueue(10, 8);
			P.enqueue(3, 1);
			Assert::AreEqual(3, P.top());
			P.dequeue();
			P.dequeue();
			Assert::AreEqual(5, P.top());
		}
		TEST_METHOD(TopMethod)
		{
			PriorityQueue Q;
			Q.enqueue(10, 3);
			Q.enqueue(9, 2);
			Q.enqueue(6, 4);
			Q.enqueue(7, 9);
			Assert::AreEqual(9, Q.top());
		}
		TEST_METHOD(SizeMethod)
		{
			PriorityQueue S;
			S.enqueue(5, 2);
			S.enqueue(6, 7);
			S.enqueue(3, 1);
			S.enqueue(9, 6);
			Assert::AreEqual(4, S.size());
		}
		TEST_METHOD(EmptyMethod)
		{
			PriorityQueue M;
			Assert::IsTrue(M.isEmpty());
			M.enqueue(9, 7);
			M.enqueue(7, 2);
			Assert::IsFalse(M.isEmpty());
		}
	};
}
