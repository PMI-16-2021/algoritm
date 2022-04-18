#include "pch.h"
#include "CppUnitTest.h"
#include "../PriorityQueue/priorityqueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTest
{
	TEST_CLASS(QueueTest)
	{
	public:
		
		TEST_METHOD(ConstructorTest){
			PriorityQueue<int> PQ;
			Assert::IsTrue(PQ.isEmpty());
		}
		TEST_METHOD(EnqueueAndTopTest) {
			PriorityQueue<int> PQ;
			PQ.enqueue(1, 3);
			Assert::AreEqual(1, PQ.top());
			PQ.enqueue(2, 1);
			Assert::AreEqual(2, PQ.top());
		}
		TEST_METHOD(DequeueTest) {
			PriorityQueue<int> PQ;
			PQ.enqueue(1, 3);
			PQ.dequeue();
			Assert::IsTrue(PQ.isEmpty());
		}
		TEST_METHOD(SizeTest) {
			PriorityQueue<int> PQ;
			Assert::AreEqual(0, PQ.size());
			PQ.enqueue(1, 3);
			Assert::AreEqual(1, PQ.size());

			PriorityQueue<int> PQ1;
			Assert::AreEqual(1, PQ.size());
		}
		TEST_METHOD(EmptyTest) {
			PriorityQueue<int> PQ;
			PQ.enqueue(1, 3);
			PQ.enqueue(2, 1);
			PQ.empty();
			Assert::IsTrue(PQ.isEmpty());
		}
	};
}
