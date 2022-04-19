#include "pch.h"
#include "CppUnitTest.h"
#include "..//queue/queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PrQueueUnitTest
{
	TEST_CLASS(PrQueueUnitTest)
	{
	public:

		TEST_METHOD(TestEnqueue) {
			PriorityQ prQ;
			prQ.enqueue(3, 3);
			prQ.enqueue(2, 2);
			prQ.enqueue(1, 1);
			Assert::AreEqual(prQ.top(), 1);
			Assert::AreEqual(prQ.size(), 3);
		}
		
		TEST_METHOD(TestDequeue) {
			PriorityQ prQ;
			prQ.enqueue(3, 3);
			prQ.enqueue(2, 2);
			prQ.enqueue(1, 1);

			prQ.dequeue();
			Assert::AreEqual(prQ.top(), 2);

			prQ.dequeue();
			Assert::AreEqual(prQ.top(), 3);
		}
		
		TEST_METHOD(TestEmpty) {
			PriorityQ prQ;
			Assert::IsTrue(prQ.isEmpty());

			prQ.enqueue(1, 1);
			Assert::IsFalse(prQ.isEmpty());
		}
		
		TEST_METHOD(TestSize) {
			PriorityQ prQ;
			Assert::AreEqual(prQ.size(), 0);

			prQ.enqueue(1, 1);
			Assert::AreEqual(prQ.size(), 1);
		}
		
		TEST_METHOD(TestTop) {
			PriorityQ prQ;
			prQ.enqueue(2, 2);
			Assert::AreEqual(prQ.top(), 2);

			prQ.enqueue(1, 1);
			Assert::AreEqual(prQ.top(), 1);
		}

	};
}
