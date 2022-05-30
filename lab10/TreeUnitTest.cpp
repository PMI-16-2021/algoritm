#include "pch.h"
#include "CppUnitTest.h"
#include "..//Project10/tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace TreeUnitTest
{
	TEST_CLASS(TreeUnitTest)
	{
	public:
		
		TEST_METHOD(InsertTest)
		{
			AVLTree avl;
			root = avl.insert(root, 1234);
			root = avl.insert(root, 456);
			root = avl.insert(root, 711);
			root = avl.insert(root, 21);
			Assert::IsTrue(avl.search(1234) != NULL);
			Assert::IsTrue(avl.search(456) != NULL);
			Assert::IsTrue(avl.search(711) != NULL);
			Assert::IsTrue(avl.search(21) != NULL);
		}

		TEST_METHOD(SearchTest)
		{
			AVLTree avl;
			root = avl.insert(root, 5);
			root = avl.insert(root, 20);
			root = avl.insert(root, 13);
			root = avl.insert(root, 999);
			Assert::IsTrue(avl.search(5) != NULL);
			Assert::IsTrue(avl.search(124) == NULL);
		}
		TEST_METHOD(DeleteTest)
		{
			AVLTree avl;
			root = avl.insert(root, 1);
			root = avl.insert(root, 2);
			root = avl.insert(root, 3);
			root = avl.insert(root, 4);

			root = avl.deleteNode(root, 2);
			root = avl.deleteNode(root, 3);
			root = avl.deleteNode(root, 4);
			Assert::IsTrue(avl.search(1) != NULL);
			Assert::IsTrue(avl.search(2) == NULL);
			Assert::IsTrue(avl.search(3) == NULL);
			Assert::IsTrue(avl.search(4) == NULL);
		}

		TEST_METHOD(isEmptyTest)
		{
			AVLTree avl;
			root = avl.insert(root, 1);
			root = avl.insert(root, 2);
			root = avl.insert(root, 3);

			root = avl.deleteNode(root, 1);
			root = avl.deleteNode(root, 2);
			root = avl.deleteNode(root, 3);

			Assert::IsTrue(avl.isEmpty());
			Assert::AreEqual(avl.height(root), -1);
		}

		TEST_METHOD(HeightTest)
		{
			AVLTree avl;
			root = avl.insert(root, 37);
			root = avl.insert(root, 24);
			root = avl.insert(root, 7);
			root = avl.insert(root, 32);
			root = avl.insert(root, 2);
			root = avl.insert(root, 5);
			root = avl.insert(root, 42);
			root = avl.insert(root, 40);
			root = avl.insert(root, 43);
			root = avl.insert(root, 100);

			Assert::AreEqual(avl.height(root), 3);

			root = avl.deleteNode(root, 24);
			root = avl.deleteNode(root, 7);
			root = avl.deleteNode(root, 32);
			root = avl.deleteNode(root, 2);
			root = avl.deleteNode(root, 5);
			root = avl.deleteNode(root, 42);
			root = avl.deleteNode(root, 40);
			root = avl.deleteNode(root, 43);
			root = avl.deleteNode(root, 100);

			Assert::AreEqual(avl.height(root), 0);

			root = avl.deleteNode(root, 37);
			Assert::AreEqual(avl.height(root), -1);
		}
	};
}
