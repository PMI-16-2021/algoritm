﻿#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab03/queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest3
{
	TEST_CLASS(UnitTest3)
	{
	public:
		TEST_METHOD(IsEmptyTest) {
			PriorityQueue<int> P1;
			Assert::IsTrue(P1.isEmpty());
			P1.enQueue(4, 1);
			Assert::IsFalse(P1.isEmpty());
		}
		TEST_METHOD(SizeTest) {
			PriorityQueue<int> P1;
			P1.enQueue(4, 1);
			P1.enQueue(5, 4);
			P1.enQueue(7, 2);
			Assert::AreEqual(P1.size(), 3);
		}
		TEST_METHOD(TopTest) {
			PriorityQueue<int> P1;
			P1.enQueue(9, 4);
			P1.enQueue(5, 1);
			Assert::AreEqual(P1.top(), 5);
		}
		TEST_METHOD(DequeueTest) {
			PriorityQueue<int> P1;
			P1.enQueue(9, 1);
			P1.enQueue(3, 0);
			P1.enQueue(6, 4);
			Assert::AreEqual(P1.deQueue(), 3);
			Assert::AreEqual(P1.top(), 9);
		}
		TEST_METHOD(EnqueueTest) {
			PriorityQueue<int> P1;
			P1.enQueue(9, 1);
			P1.enQueue(3, 0);
			P1.enQueue(6, 4);
			P1.enQueue(2, 0);
			P1.enQueue(5, 1);
			const int n = 5;
			int resultQueue[n] = { 3, 2, 9, 5, 6 };
			for (int i = 0; i < n; ++i) {
				Assert::AreEqual(P1.deQueue(), resultQueue[i]);
			}
		}
		TEST_METHOD(EmptyTest) {
			PriorityQueue<int> P1;
			P1.enQueue(7, 1);
			P1.enQueue(3, 0);
			P1.enQueue(5, 4);
			P1.emptyQueue();
			Assert::IsTrue(P1.isEmpty());
		}
	};
}
