#include "pch.h"
#include "CppUnitTest.h"
#include"../Priority_Queue/List_and_Queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1Queue
{
	TEST_CLASS(UnitTest1Queue)
	{
	public:
		
		TEST_METHOD(enqueue_element)
		{
			PriorityQueue a;
			a.enqueue(1, 1);
			a.dequeue();
			Assert::IsTrue(a.isEmpty());
		}
		TEST_METHOD(dequeue_element)
		{
			PriorityQueue a;
			for (int i = 0; i < 10; i++)
			{
				a.enqueue(rand(), rand() % 10);
			}
			a.dequeue();
			a.dequeue();
			a.dequeue();
			Assert::AreEqual(a.size(), 7);
		}
		TEST_METHOD(size_queue)
		{
			PriorityQueue a;
			for (int i = 0; i < 22; i++)
			{
				a.enqueue(rand(), rand() % 10);
			}
			Assert::AreEqual(22, a.size());
		}
		TEST_METHOD(empty_queue)
		{
			PriorityQueue a;
			Assert::IsTrue(a.isEmpty());

			a.enqueue(1, 1);

			Assert::IsFalse(a.isEmpty());

			a.dequeue();
			Assert::IsTrue(a.isEmpty());
		}
		TEST_METHOD(top_queue)
		{
			PriorityQueue a;

			a.enqueue(1, 1);
			a.enqueue(2, 1);
			Assert::AreEqual(1, a.top());
			a.dequeue(); a.dequeue();
			Assert::IsTrue(a.isEmpty());
		}
	};
}
