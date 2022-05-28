#include "pch.h"
#include "CppUnitTest.h"
#include "..//лр10/tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest {
	TEST_CLASS(AVLTreeTest) {
	public:
		TEST_METHOD(heightTest) {
			Node* root = NULL;
			root = insert(root, 1);
			root = insert(root, 2);
			root = insert(root, 3);
			Assert::AreEqual(root->height_, 2);
			root = insert(root, 5);
			root = insert(root, -1);
			Assert::AreEqual(root->height_, 3);
		}
		TEST_METHOD(insertTest) {
			Node* root = NULL;
			root = insert(root, 10);
			root = insert(root, 20);
			root = insert(root, 30);
			root = insert(root, 40);
			root = insert(root, 50);
			root = insert(root, 60);

			std::vector<int> v1;
			preOrder(root, v1);
			Assert::AreEqual(v1[0], 40);
			Assert::AreEqual(v1[1], 20);
			Assert::AreEqual(v1[2], 10);
			Assert::AreEqual(v1[3], 30);
			Assert::AreEqual(v1[4], 50);
			Assert::AreEqual(v1[5], 60);
			root = insert(root, 100);

			std::vector<int> v2;
			preOrder(root, v2);
			Assert::AreEqual(v2[0], 40);
			Assert::AreEqual(v2[1], 20);
			Assert::AreEqual(v2[2], 10);
			Assert::AreEqual(v2[3], 30);
			Assert::AreEqual(v2[4], 60);
			Assert::AreEqual(v2[5], 50);
			Assert::AreEqual(v2[6], 100);
		}
		TEST_METHOD(preOrderTest) {
			Node* root = NULL;
			root = insert(root, 1);
			root = insert(root, 2);
			root = insert(root, 3);
			root = insert(root, 4);
			root = insert(root, 5);
			root = insert(root, 6);

			std::vector<int> v;
			preOrder(root, v);
			Assert::AreEqual(v[0], 4);
			Assert::AreEqual(v[1], 2);
			Assert::AreEqual(v[2], 1);
			Assert::AreEqual(v[3], 3);
			Assert::AreEqual(v[4], 5);
			Assert::AreEqual(v[5], 6);
		}
		TEST_METHOD(postOrderTest) {
			Node* root = NULL;
			root = insert(root, 1);
			root = insert(root, 2);
			root = insert(root, 3);
			root = insert(root, 4);
			root = insert(root, 5);
			root = insert(root, 6);

			std::vector<int> v;
			postOrder(root, v);
			Assert::AreEqual(v[0], 1);
			Assert::AreEqual(v[1], 3);
			Assert::AreEqual(v[2], 2);
			Assert::AreEqual(v[3], 6);
			Assert::AreEqual(v[4], 5);
			Assert::AreEqual(v[5], 4);
		}
		TEST_METHOD(infixOrderTest) {
			Node* root = NULL;
			root = insert(root, 1);
			root = insert(root, 2);
			root = insert(root, 3);
			root = insert(root, 4);
			root = insert(root, 5);
			root = insert(root, 6);

			std::vector<int> v;
			postOrder(root, v);
			Assert::AreEqual(v[0], 1);
			Assert::AreEqual(v[1], 3);
			Assert::AreEqual(v[2], 2);
			Assert::AreEqual(v[3], 6);
			Assert::AreEqual(v[4], 5);
			Assert::AreEqual(v[5], 4);
		}
		TEST_METHOD(deleteNodeTest)	{
			Node* root = NULL;
			root = insert(root, 10);
			root = insert(root, 20);
			root = insert(root, 30);
			root = insert(root, 40);
			root = insert(root, 50);
			root = insert(root, 60);

			std::vector<int> v1;
			postOrder(root, v1);
			Assert::AreEqual(v1[0], 10);
			Assert::AreEqual(v1[1], 30);
			Assert::AreEqual(v1[2], 20);
			Assert::AreEqual(v1[3], 60);
			Assert::AreEqual(v1[4], 50);
			Assert::AreEqual(v1[5], 40);
			root = deleteNode(root, 50);

			std::vector<int> v2;
			postOrder(root, v2);
			Assert::AreEqual(v2[0], 10);
			Assert::AreEqual(v2[1], 30);
			Assert::AreEqual(v2[2], 20);
			Assert::AreEqual(v2[3], 60);
			Assert::AreEqual(v2[4], 40);
		}
	};
}
