#include "pch.h"
#include "CppUnitTest.h"
#include "..\lab03\prQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QueueTest
{
	TEST_CLASS(QueueTest)
	{
	public:
		
		TEST_METHOD(Constructors)
		{
			PrQueue Q;
			Assert::IsTrue(Q.isEmpty());
		}
		TEST_METHOD(Size)
		{
			PrQueue Q;
			Assert::AreEqual(0, Q.size());
			Q.enQueue(7, 1);
			Assert::AreEqual(1, Q.size());
		}
		TEST_METHOD(TopAndEnqueue)
		{
			PrQueue Q;
			Q.enQueue(3, 7);
			Q.enQueue(1, 9);
			Q.enQueue(5, 11);
			Assert::AreEqual(3, Q.top());
		}
		TEST_METHOD(DeQueue)
		{
			PrQueue Q;
			Q.enQueue(7, 3);
			Q.deQueue();
			Assert::IsTrue(Q.isEmpty());
		}
	};
}
