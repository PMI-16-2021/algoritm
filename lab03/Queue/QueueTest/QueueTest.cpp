#include "pch.h"
#include "CppUnitTest.h"
#include "..\\queue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTest
{
	TEST_CLASS(QueueTest)
	{
	public:
		
		TEST_METHOD(TestConstructors)
		{
			QueueP<int> Q1;
			Q1.Push(10, 1);
			Q1.Push(5,2);
			QueueP<int> Q2(Q1);
			Assert::AreEqual(Q2.Count(), 2);
		}

		TEST_METHOD(TestPush)
		{
			QueueP<int> Q1;
			Q1.Push(10, 1);
			Q1.Push(5, 2);
			Q1.Push(5, 5);
			Q1.Push(5, 6);
			Q1.Push(5, 7);
			Q1.Push(5, 10);
			Assert::AreEqual(Q1.Count(), 6);
		}

		TEST_METHOD(TestPop)
		{
			QueueP<int> Q2;
			Q2.Push(10, 1);
			Q2.Push(5, 2);
			Q2.Push(5, 5);
			Q2.Push(5, 6);
			Q2.Push(5, 7);
			Q2.Push(5, 10);
			int pop;
			pop = Q2.Pop();
			pop = Q2.Pop();
			pop = Q2.Pop();
			pop = Q2.Pop();
			Assert::AreEqual(Q2.Count(), 2);
		}

		TEST_METHOD(TestCount)
		{
			QueueP<int> Q2;
			Q2.Push(10, 1);
			Q2.Push(5, 2);
			Q2.Push(5, 5);
			Q2.Push(5, 6);
			Q2.Push(5, 7);
			Q2.Push(5, 10);
			int pop;
			pop = Q2.Pop();
			pop = Q2.Pop();
			pop = Q2.Pop();
			pop = Q2.Pop();
			pop = Q2.Pop();
			pop = Q2.Pop();
			Assert::AreEqual(Q2.Count(), 0);
		}

		TEST_METHOD(TestOperator)
		{
			QueueP<int> Q1;
			QueueP<int> Q3;
			Q1.Push(10, 1);
			Q1.Push(5, 2);
			Q1.Push(5, 5);
			Q1.Push(5, 6);
			Q1.Push(5, 7);
			Q1.Push(5, 10);
			Q3 = Q1;
			Assert::AreEqual(Q3.Count(), 6);
		}

		TEST_METHOD(TestClear)
		{
			QueueP<int> Q1;
			Q1.Push(10, 1);
			Q1.Push(5, 2);
			Q1.Push(5, 5);
			Q1.Push(5, 6);
			Q1.Push(5, 7);
			Q1.Push(5, 10);
			Q1.Clear();
			Assert::AreEqual(Q1.Count(), 0);
		}
	};
}
