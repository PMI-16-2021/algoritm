#include "pch.h"
#include "CppUnitTest.h"
#include"..//proirity queue/PriorityQueue.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorityQueueTests
{
	PriorityQueue myQ;
	TEST_CLASS(PriorityQueueTests)
	{
	public:
		
		TEST_METHOD(EnqueueTest)
		{
			myQ.enqueue(2, 2);
			Assert::AreEqual(myQ.top(), 2);
		}
		TEST_METHOD(DequeueTest)
		{
			myQ.enqueue(1, 1);
			myQ.enqueue(2, 2);
			myQ.dequeue();
			Assert::AreEqual(myQ.top(), 2);
		}
		TEST_METHOD(IsEmptyTest)
		{
			PriorityQueue queue;
			Assert::AreEqual(queue.isEmpty(), true);
		}
		TEST_METHOD(SizeTest)
		{
			PriorityQueue queue;
			queue.enqueue(1, 1);
			queue.enqueue(2, 2);
			Assert::AreEqual(queue.size(), 2);
		}
		TEST_METHOD(TopTest)
		{
			myQ.enqueue(1, 1);
			Assert::AreEqual(myQ.top(), 1);
		}
		TEST_METHOD(ClearTest)
		{
			myQ.clear();
			Assert::AreEqual(myQ.isEmpty(), true);
		}
	};
}
