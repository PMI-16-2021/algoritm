#include "pch.h"
#include "CppUnitTest.h"
#include "..//Project20/queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTest {
	TEST_CLASS(QueueTest) {
	public:
		TEST_METHOD(IsEmptyTest) {
			PriorityQueue<int> P1;
			Assert::IsTrue(P1.IsEmpty());
			P1.Enqueue(9, 1);
			Assert::IsFalse(P1.IsEmpty());
		}
		TEST_METHOD(SizeTest) {
			PriorityQueue<int> P1;
			P1.Enqueue(9, 1);
			P1.Enqueue(6, 4);
			P1.Enqueue(8, 2);
			Assert::AreEqual(P1.Size(), 3);
		}
		TEST_METHOD(TopTest) {
			PriorityQueue<int> P1;
			P1.Enqueue(9, 4);
			P1.Enqueue(5, 1);
			Assert::AreEqual(P1.Top(), 5);
		}
		TEST_METHOD(DequeueTest) {
			PriorityQueue<int> P1;
			P1.Enqueue(9, 1);
			P1.Enqueue(3, 0);
			P1.Enqueue(6, 4);
			Assert::AreEqual(P1.Dequeue(), 3);
			Assert::AreEqual(P1.Top(), 9);
		}
		TEST_METHOD(EnqueueTest) {
			PriorityQueue<int> P1;
			P1.Enqueue(9, 1);
			P1.Enqueue(3, 0);
			P1.Enqueue(6, 4);
			P1.Enqueue(2, 0);
			P1.Enqueue(5, 1);
			const int n = 5;
			int ResultQueue[n] = { 3, 2, 9, 5, 6 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(P1.Dequeue(), ResultQueue[i]);
			}
		}
		TEST_METHOD(EmptyTest) {
			PriorityQueue<int> P1;
			P1.Enqueue(9, 1);
			P1.Enqueue(3, 0);
			P1.Enqueue(6, 4);
			P1.EmptyQueue();
			Assert::IsTrue(P1.IsEmpty());
		}
	};
}
