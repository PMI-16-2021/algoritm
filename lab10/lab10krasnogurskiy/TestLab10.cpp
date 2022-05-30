#include "pch.h"
#include "CppUnitTest.h"
#include "..//lab10/tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest10
{
	TEST_CLASS(UnitTest10)
	{
	public:
		TEST_METHOD(TestCtor)
		{
			AvlTree avl;
			Assert::AreEqual(size_t(0), avl.getSize());
			bool nullroot = avl.getRoot().getHeight() == -1;
			Assert::IsTrue(nullroot);
		}

		TEST_METHOD(TestInsert)
		{
			AvlTree avl;
			Assert::AreEqual(size_t(0), avl.getSize());
			avl.insert(10);
			Assert::AreEqual(size_t(1), avl.getSize());
			avl.insert(20);
			avl.insert(-40);
			Assert::AreEqual(size_t(3), avl.getSize());
		}

		TEST_METHOD(TestGetAt)
		{
			AvlTree avl;
			avl.insert(10);
			Assert::AreEqual(10, avl.getAt(10).getKey());
			avl.insert(20);
			avl.insert(-40);
			Assert::AreEqual(20, avl.getAt(20).getKey());
			Assert::AreEqual(-40, avl.getAt(-40).getKey());
		}

		TEST_METHOD(TestBalance)
		{
			AvlTree avl;
			bool goodbalanced = true;
			for (size_t i = 0; i < 20; i++)
			{
				avl.insert((int)i);
				int balance = avl.getBalanceAt(avl.getRoot().getKey());
				if (balance > 1 || balance < -1)
				{
					goodbalanced = false;
				}
			}
			for (size_t i = 4; i < 10; i++)
			{
				avl.insert((int)i*10);
			}

			for (size_t i = 0; i < 5; i++)
			{
				int balance = avl.getBalanceAt((int)i);
				if (balance > 1 || balance < -1)
				{
					goodbalanced = false;
				}
			}

			Assert::IsTrue(goodbalanced);
		}
	};
}
