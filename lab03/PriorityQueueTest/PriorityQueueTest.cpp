#include "pch.h"
#include "CppUnitTest.h"
#include"../lab03Ostap-04/priority_queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorityQueueTest
{
	TEST_CLASS(PriorityQueueTest)
	{
	public:
		TEST_METHOD(IsEmpty_Test)
		{
			PriorityQueue<int> A;
			Assert::IsTrue(A.IsEmpty());
			A.Enqueue(5, 1);
			A.Enqueue(1, 0);
			Assert::IsFalse(A.IsEmpty());
			A.Dequeue();
			Assert::IsFalse(A.IsEmpty());
			A.Dequeue();
			Assert::IsTrue(A.IsEmpty());
		}
		TEST_METHOD(Equeue_Dequeue_Test)
		{
			PriorityQueue<int> A;
			try {
				A.Dequeue();
				Assert::Fail();
			}
			catch (const char* msg) {
				std::cerr << msg;
			}
			A.Enqueue(3, 1);
			A.Enqueue(5, 0);
			A.Enqueue(4, 2);
			A.Enqueue(2, 0);
			Assert::AreEqual(5, A.Dequeue());
			Assert::AreEqual(2, A.Dequeue());
			Assert::AreEqual(3, A.Dequeue());
			Assert::AreEqual(4, A.Dequeue());
			Assert::IsTrue(A.IsEmpty());
		}
		TEST_METHOD(Top_Test)
		{
			PriorityQueue<int> A;
			A.Enqueue(5, 2);
			A.Enqueue(1, 0);
			Assert::AreEqual(1, A.Top());
			Assert::AreEqual(1, A.Dequeue());
			Assert::AreEqual(5, A.Top());
			Assert::AreEqual(5, A.Dequeue());
			Assert::IsTrue(A.IsEmpty());
			try {
				A.Top();
				Assert::Fail();
			}
			catch (const char* msg) {
				std::cerr << msg;
			}
		}
		TEST_METHOD(size_Test)
		{
			PriorityQueue<int> A;
			Assert::AreEqual(0, A.Size());
			A.Enqueue(1, 0);
			A.Enqueue(2, 1);
			A.Enqueue(3, 2);
			A.Enqueue(4, 3);
			Assert::AreEqual(4, A.Size());
			A.Dequeue();
			Assert::AreEqual(3, A.Size());
			A.Dequeue();
			A.Dequeue();
			A.Dequeue();
			Assert::AreEqual(0, A.Size());
			Assert::IsTrue(A.IsEmpty());
		}
	};
}
