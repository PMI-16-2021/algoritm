#include "pch.h"
#include "CppUnitTest.h"
#include "..//лр3/priorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(PriorityQueueTest) {
	public:
		TEST_METHOD(isEmptyTest) {
			PriorQueue<int> PQ;
			Assert::IsTrue(PQ.isEmpty());
			PQ.enqueue(4, 2);
			Assert::IsFalse(PQ.isEmpty());
		}
		TEST_METHOD(sizeTest) {
			PriorQueue<int> PQ;
			PQ.enqueue(1, 6);
			PQ.enqueue(3, 2);
			PQ.enqueue(5, 0);
			Assert::AreEqual(PQ.size(), 3);
		}
		TEST_METHOD(topTest) {
			PriorQueue<int> PQ;
			PQ.enqueue(4, 2);
			PQ.enqueue(3, 0);
			Assert::AreEqual(PQ.top(), 3);
		}
		TEST_METHOD(dequeueTest) {
			PriorQueue<int> PQ;
			PQ.enqueue(4, 2);
			PQ.enqueue(6, 1);
			PQ.enqueue(2, 3);
			Assert::AreEqual(PQ.dequeue(), 6);
			Assert::AreEqual(PQ.top(), 4);
		}
		TEST_METHOD(enqueueTest) {
			PriorQueue<int> PQ;
			PQ.enqueue(-2, 2);
			PQ.enqueue(1, 3);
			PQ.enqueue(0, 1);
			PQ.enqueue(3, 1);
			const size_t n = 4;
			int resultPriorityQueue[n] = { 0, 3, -2, 1 };
			for (size_t i = 0; i < n; ++i) {
				Assert::AreEqual(PQ.dequeue(), resultPriorityQueue[i]);
			}
		}
		TEST_METHOD(emptyTest) {
			PriorQueue<int> PQ;
			PQ.enqueue(7, 8);
			PQ.enqueue(1, 5);
			PQ.enqueue(3, 3);
			PQ.empty();
			Assert::IsTrue(PQ.isEmpty());
		}
	};
}