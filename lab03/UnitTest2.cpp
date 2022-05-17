#include "pch.h"
#include "CppUnitTest.h"
#include "..\\Project28\queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest2
{
	TEST_CLASS(UnitTest2)
	{
	public:
		
		TEST_METHOD(SizeTest) {
			PriorityQueue<int> Queue;
			Assert::AreEqual(0, Queue.size());
			Queue.enqueue(1, 3);
			Queue.enqueue(4, 1);
			Assert::AreEqual(2, Queue.size());
			Queue.dequeue();
			Assert::AreEqual(1, Queue.size());
		}
		TEST_METHOD(isEmptyTest) {
			PriorityQueue<int> Queue;
			Assert::IsTrue(Queue.isEmpty());
			Queue.enqueue(3, 1);
			Assert::IsFalse(Queue.isEmpty());
		}
		TEST_METHOD(EmptyTest) {
			PriorityQueue<int> Queue;
			Queue.enqueue(2, 0);
			Queue.enqueue(1, 1);
			Queue.emptyQueue();
			Assert::IsTrue(Queue.isEmpty());
		}
		TEST_METHOD(TopTest) {
			PriorityQueue<int> Queue;
			Queue.enqueue(14, 0);
			Assert::AreEqual(14, Queue.top());
			Queue.enqueue(2, 1);
			Assert::AreEqual(14, Queue.top());
			Queue.dequeue();
			Assert::AreEqual(2, Queue.top());
		}
		TEST_METHOD(EnqueueTest) {
			PriorityQueue<int> Queue;
			Queue.enqueue(14, 0);
			Queue.enqueue(2, 1);
			Assert::IsFalse(Queue.isEmpty());
			Assert::AreEqual(14, Queue.top());
			Queue.dequeue();
			Assert::AreEqual(2, Queue.top());
		}
		TEST_METHOD(DequeueTest) {
			PriorityQueue<int> Queue;
			Queue.enqueue(4, 3);
			Queue.enqueue(7, 1);
			Queue.dequeue();
			Assert::AreEqual(4, Queue.top());
			Queue.dequeue();
			Assert::IsTrue(Queue.isEmpty());
		}
	};
}
