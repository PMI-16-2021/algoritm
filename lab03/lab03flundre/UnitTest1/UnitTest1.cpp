#include "pch.h"
#include "CppUnitTest.h"
#include "../alg lab03 (queue)/queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1 {
	TEST_CLASS(UnitTest1) {
	public:
		
		TEST_METHOD(enqueue) {
			QueueP<int> temp;
			temp.enqueue(1, 1);
			temp.dequeue();
			Assert::IsTrue(temp.isEmpty());
		}

		TEST_METHOD(dequeue) {
			QueueP<int> temp;
			temp.enqueue(1, 1);
			temp.enqueue(1, 1);
			temp.dequeue();
			Assert::AreEqual(1, temp.dequeue());
		}

		TEST_METHOD(isEmpty) {
			QueueP<int> temp;
			Assert::IsTrue(temp.isEmpty());
			temp.enqueue(1, 1);
			temp.dequeue();
			Assert::IsTrue(temp.isEmpty());
		}

		TEST_METHOD(size) {
			QueueP<int> temp;
			for (int i = 0; i < 10; i++)
			{
				temp.enqueue(1, 1);
			}
			Assert::AreEqual(10, temp.size());
		}

		TEST_METHOD(top) {
			QueueP<int> temp;
			temp.enqueue(1, 1);
			temp.enqueue(2, 1);
			temp.enqueue(3, 1);
			Assert::AreEqual(3, temp.top());
		}
	};
}
