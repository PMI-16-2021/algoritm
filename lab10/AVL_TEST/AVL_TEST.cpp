#include "pch.h"
#include "CppUnitTest.h"
#include "../AVL/AVLTree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AVLTEST
{
	TEST_CLASS(AVLTEST)
	{
	public:
		
		TEST_METHOD(insert_TEST)
		{
			Tree<int> tr;
			Assert::IsFalse(tr.find(5));
			Assert::AreEqual(-1, tr.height());
			tr.insert(5);
			Assert::IsTrue(tr.find(5));
			Assert::AreEqual(0, tr.height());
			tr.insert(3);
			Assert::AreEqual(1, tr.height());
			tr.insert(2);
			Assert::AreEqual(1, tr.height());
			tr.insert(6);
		}

		TEST_METHOD(erase_TEST)
		{
			Tree<int> tr;
			Assert::IsFalse(tr.find(5));
			Assert::AreEqual(-1, tr.height());
			tr.insert(5);
			Assert::IsTrue(tr.find(5));
			tr.erase(5);
			Assert::IsFalse(tr.find(5));
			tr.insert(6);
			tr.insert(6); //twice
			Assert::IsTrue(tr.find(6));
			tr.erase(6);
			Assert::IsTrue(tr.find(6));
			tr.erase(6);
			Assert::IsFalse(tr.find(6));
		}

		TEST_METHOD(find_TEST)
		{
			Tree<int> tr;
			Assert::IsFalse(tr.find(5));
			tr.insert(3);
			Assert::IsFalse(tr.find(5));
			tr.insert(5);
			Assert::IsTrue(tr.find(5));
			tr.insert(6);
			Assert::IsTrue(tr.find(6));
			Assert::IsTrue(tr.find(5));
			tr.erase(5);
			tr.erase(6);
			Assert::IsFalse(tr.find(5));
			Assert::IsFalse(tr.find(6));


		}

		TEST_METHOD(height_TEST)
		{
			Tree<int> tr;
			Assert::IsFalse(tr.find(5));
			Assert::AreEqual(-1, tr.height());
		    Assert::IsFalse(tr.find(7));
			tr.insert(7);
			Assert::IsTrue(tr.find(7));
			Assert::AreEqual(0, tr.height()); 
			tr.insert(5);
			Assert::AreEqual(1, tr.height());
			tr.insert(7);
			Assert::AreEqual(1, tr.height());
			tr.insert(5);
			Assert::AreEqual(2, tr.height());
			tr.insert(6);
			Assert::AreEqual(2, tr.height());
			tr.insert(1);
			Assert::AreEqual(2, tr.height());
			
		}
	};
}
