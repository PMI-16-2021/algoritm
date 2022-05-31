#include "pch.h"
#include "CppUnitTest.h"
#include "..\\TreeAvl.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AVLTreeTest
{
	TEST_CLASS(AVLTreeTest)
	{
	public:
		
		TEST_METHOD(TestInsert)
		{
			 AVL_Tree demo;
			 demo.insertNode(33);
			 demo.insertNode(25);
			 demo.insertNode(21);
			 demo.insertNode(44);
			Assert::AreEqual(demo.balanceFactor(demo.getRoot()), 1);
		}

		TEST_METHOD(TestDelete)
		{
			AVL_Tree demo;
			demo.insertNode(33);
			demo.insertNode(25);
			demo.insertNode(21);
			demo.insertNode(44);
			demo.insertNode(55);
			demo.insertNode(87);
			demo.remove(25);
			demo.remove(44);
			Assert::AreEqual(demo.balanceFactor(demo.getRoot()), -1);
		}

		TEST_METHOD(TestGetBalanceFactor)
		{
			AVL_Tree demo;
			demo.insertNode(33);
			demo.insertNode(25);
			demo.insertNode(21);
			demo.insertNode(44);
			demo.insertNode(55);
			demo.insertNode(87);
			Assert::AreEqual(demo.balanceFactor(demo.getRoot()), 0);
		}

		TEST_METHOD(TestHeight)
		{
			AVL_Tree demo;
			demo.insertNode(33);
			demo.insertNode(25);
			demo.insertNode(21);
			demo.insertNode(44);
			demo.insertNode(55);
			demo.insertNode(87);
			Assert::AreEqual(demo.getHeight(demo.getRoot()), 2);
		}
	};
}
