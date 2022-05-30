﻿#include "pch.h"
#include "CppUnitTest.h"
#include "../PriorityQueue/PriorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorityQueueTest
{
	TEST_CLASS(PriorityQueueTest)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			PriorQueue<int> P1;
			P1.enqueue(3, 4);
			P1.enqueue(3, 1);
			P1.enqueue(3, 5);
			P1.enqueue(7, 2);
			P1.enqueue(1, 4);
			Assert::AreEqual(P1.dequeue(), 3);
		}
		TEST_METHOD(TestMethodEmpty)
		{
			PriorQueue<int> P2;
			Assert::IsTrue(P2.isEmpty());
			P2.enqueue(4, 3);
			Assert::IsFalse(P2.isEmpty());
		}
		TEST_METHOD(TestMethodSize)
		{
			PriorQueue<int> P3;
			Assert::AreEqual(P3.size(), 0);
			P3.enqueue(2, 3);
			P3.enqueue(7, 0);
			P3.enqueue(4, 1);
			Assert::AreEqual(P3.size(), 3);
		}
		TEST_METHOD(TestMethodTop)
		{
			PriorQueue<int> P4;
			P4.enqueue(3, 0);
			P4.enqueue(2, 9);
			P4.enqueue(1, 7);
			Assert::AreEqual(P4.top(), 3);
		}
		TEST_METHOD(TestMethodDequeue)
		{
			PriorQueue<int> P5;
			P5.enqueue(7, 2);
			P5.enqueue(4, 6);
			P5.enqueue(3, 2);
			P5.dequeue();
			P5.dequeue();
			Assert::AreEqual(P5.top(), 4);
		}
	};
}
