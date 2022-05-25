#include "pch.h"
#include "CppUnitTest.h"
#include "../priorityQueue/queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestPriorityQueue
{
	TEST_CLASS(UnitTestPriorityQueue)
	{
	public:
		
		TEST_METHOD(empty)
		{
			PriorityQueue P;
			Assert::IsTrue(P.isEmpty());
			P.enqueue(1, 1);
			Assert::IsFalse(P.isEmpty());
		}
		TEST_METHOD(enqueue)
		{
			PriorityQueue P;
			P.enqueue(1, 1);
			Assert::AreEqual(1, P.head());
			P.enqueue(4, 2);
			Assert::AreEqual(1, P.head());
			Assert::AreEqual(4, P.taill());
		}
		TEST_METHOD(denqueue)
		{
			PriorityQueue P;
			P.enqueue(1, 1);
			P.enqueue(4, 2);
			Assert::AreEqual(1, P.head());
			P.dequeue();
			Assert::AreEqual(4, P.head());
		}
		TEST_METHOD(size)
		{
			PriorityQueue P;
			P.enqueue(1, 1);
			P.enqueue(4, 2);
			Assert::AreEqual(2, P.size());
		}

	};
}
