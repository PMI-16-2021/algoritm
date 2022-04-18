#include "pch.h"
#include "CppUnitTest.h"
#include "../dmitru4ok/PriorityQueue.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace PriorQueueTesting
{
	TEST_CLASS(PriorQueueTesting)
	{
	public:
		
		TEST_METHOD(isEmpty_Test)
		{
<<<<<<< Updated upstream
			PriorityQueue<> A; 
=======
			PriorityQueue<int> A;
>>>>>>> Stashed changes
			Assert::IsTrue(A.isEmpty());

			A.enqueue(3, 0);

			Assert::IsFalse(A.isEmpty());

			A.top();
			Assert::IsFalse(A.isEmpty());

			A.dequeue();
			Assert::IsTrue(A.isEmpty());
		}

		TEST_METHOD(dequeue_Test)
		{
<<<<<<< Updated upstream
			PriorityQueue<> A;
=======
			PriorityQueue<int> A;
>>>>>>> Stashed changes
			try
			{
				A.dequeue();
				Assert::Fail();
			}
			catch (const char* msg)
			{
				std::cerr << msg;
			}

			A.enqueue(3, 1);// Queue: 3(pr1)
			A.enqueue(5, 0); // Queue: 5(pr0), 3(pr1)
			A.enqueue(4, 0);  // Queue: 5(pr0), 4(pr0), 3(pr1)

<<<<<<< Updated upstream
			Assert::AreEqual(5, A.dequeue()); 
=======
			Assert::AreEqual(5, A.dequeue());
>>>>>>> Stashed changes
			Assert::AreEqual(4, A.dequeue());
			Assert::AreEqual(3, A.dequeue());
		}

		TEST_METHOD(top_Test)
		{
<<<<<<< Updated upstream
			PriorityQueue<List, Pair, double> A;
=======
			PriorityQueue<double> A;
>>>>>>> Stashed changes
			try
			{
				A.top();
				Assert::Fail();
			}
			catch (const char* msg)
			{
				std::cerr << msg;
			}

			A.enqueue(3.5, 1);
			A.enqueue(4.0, 0);
			Assert::AreEqual(4.0, A.top());
			Assert::AreEqual(4.0, A.dequeue());
			Assert::AreEqual(3.5, A.top());
			Assert::IsFalse(A.isEmpty());
			Assert::AreEqual(3.5, A.dequeue());
			Assert::IsTrue(A.isEmpty());
		}

		TEST_METHOD(enqueue_Test)
		{
<<<<<<< Updated upstream
			PriorityQueue<> A;
=======
			PriorityQueue<int> A;
>>>>>>> Stashed changes
			Assert::IsTrue(A.isEmpty());

			try
			{
				A.enqueue(3, -1);
				Assert::Fail();
			}
<<<<<<< Updated upstream
			catch (const char* msg )
=======
			catch (const char* msg)
>>>>>>> Stashed changes
			{
				std::cerr << msg;
			}
			Assert::IsTrue(A.isEmpty());

			A.enqueue(4, 2);
			A.enqueue(3, 1);
			A.enqueue(2, 2);

			Assert::AreEqual(3, A.dequeue());
			Assert::AreEqual(4, A.dequeue());
			Assert::AreEqual(2, A.dequeue());
			Assert::IsTrue(A.isEmpty());
		}

		TEST_METHOD(size_Test)
		{
<<<<<<< Updated upstream
			PriorityQueue<> A;
=======
			PriorityQueue<int> A;
>>>>>>> Stashed changes
			Assert::IsTrue(A.isEmpty());
			Assert::AreEqual(0, A.size());
			A.enqueue(4, 0); //Queue: 4(pr0)
			Assert::IsFalse(A.isEmpty());
			Assert::AreEqual(1, A.size());
			A.enqueue(5, 0); //Queue: 4(pr0), 5(pr0)
			Assert::AreEqual(2, A.size());
			Assert::AreEqual(4, A.top());//top deesn't remove
			Assert::AreEqual(2, A.size());
			Assert::AreEqual(4, A.dequeue());//Queue: 5(pr0)
			Assert::AreEqual(1, A.size());
			Assert::AreEqual(5, A.top());
			Assert::AreEqual(1, A.size());
			Assert::AreEqual(5, A.dequeue()); //Queue: *empty*
			Assert::AreEqual(0, A.size());
			Assert::IsTrue(A.isEmpty());
		}
	};
}
