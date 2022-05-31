#include "pch.h"
#include "CppUnitTest.h"
#include"..\avl_tree.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AvlTreeTest
{
	TEST_CLASS(AvlTreeTest)
	{
	public:
		TEST_METHOD(PreorderTest) {
			AvlTree<int> Tree;
			Tree.Insert(1);
			Tree.Insert(2);
			Tree.Insert(3);
			Tree.Insert(4);
			Tree.Insert(5); 
			std::vector<int> preorder;;
			Tree.Preorder(preorder);
			std::vector<int> result = { 1, 2, 4, 5, 3 };
			for (int i = 0; i < preorder.size(); ++i) {
				Assert::AreEqual(preorder[i], result[i]);
			}
		}
		TEST_METHOD(InorderTest) {
			AvlTree<int> Tree;
			Tree.Insert(1);
			Tree.Insert(2);
			Tree.Insert(3);
			Tree.Insert(4);
			Tree.Insert(5);
			std::vector<int> inorder;;
			Tree.Preorder(inorder);
			std::vector<int> result = { 4, 2, 5, 1, 3 };
			for (int i = 0; i < inorder.size(); ++i) {
				Assert::AreEqual(inorder[i], result[i]);
			}
		}
		TEST_METHOD(PostorderTest) {
			AvlTree<int> Tree;
			Tree.Insert(1);
			Tree.Insert(2);
			Tree.Insert(3);
			Tree.Insert(4);
			Tree.Insert(5);
			std::vector<int> postorder;;
			Tree.Preorder(postorder);
			std::vector<int> result = { 4, 5, 2, 3, 1 };
			for (int i = 0; i < postorder.size(); ++i) {
				Assert::AreEqual(postorder[i], result[i]);
			}
		}
	};
}
