#include "pch.h"
#include "CppUnitTest.h"
#include "..//AVLTree/tree.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace AVLTreeTest {

	TEST_CLASS(AVLTreeTest) {

	public:
		TEST_METHOD(InsertTest) {
			AVLTree<int> Tree;
			Tree.Insert(3);
			Tree.Insert(4);
			Assert::IsTrue(Tree.Find(4));
			Assert::IsFalse(Tree.Find(9));
		}
		TEST_METHOD(FindTest) {
			AVLTree<int> Tree;
			Assert::IsFalse(Tree.Find(10));
			Tree.Insert(3);
			Assert::IsTrue(Tree.Find(3));
		}
		TEST_METHOD(RemoveTest) {
			AVLTree<int> Tree;
			Tree.Insert(3);
			Tree.Insert(4);
			Tree.Remove(3);
			Assert::IsFalse(Tree.Find(3));
		}
		TEST_METHOD(PreorderTest) {
			AVLTree<int> Tree;     ///////////////////////////////////////////
			Tree.Insert(2);        //                 5                     //
			Tree.Insert(7);        //             ___/ \___                 //
			Tree.Insert(5);        //          3             7              //
			Tree.Insert(3);        //      ___/ \___     ___/ \___          //
			Tree.Insert(6);        //    2          4  6          9         //
			Tree.Insert(9);        //                         ___/ \___     //
			Tree.Insert(4);        //                        8          11  //
			Tree.Insert(8);        ///////////////////////////////////////////
			Tree.Insert(11);
			Tree.Print();
			std::vector<int> preorder;;
			Tree.Preorder(preorder);
			std::vector<int> result = { 5, 3, 2, 4, 7, 6, 9, 8, 11 };
			for (int i = 0; i < preorder.size(); ++i) {
				Assert::AreEqual(preorder[i], result[i]);
			}
		}
		TEST_METHOD(InorderTest) {
			AVLTree<int> Tree;
			Tree.Insert(2);
			Tree.Insert(7);
			Tree.Insert(5);
			Tree.Insert(3);
			Tree.Insert(6);
			Tree.Insert(9);
			Tree.Insert(4);
			Tree.Insert(8);
			Tree.Insert(11);
			Tree.Print();
			std::vector<int> inorder;;
			Tree.Inorder(inorder);
			std::vector<int> result = { 2, 3, 4, 5, 6, 7, 8, 9, 11 };
			for (int i = 0; i < inorder.size(); ++i) {
				Assert::AreEqual(inorder[i], result[i]);
			}
		}
		TEST_METHOD(PostorderTest) {
			AVLTree<int> Tree;
			Tree.Insert(2);
			Tree.Insert(7);
			Tree.Insert(5);
			Tree.Insert(3);
			Tree.Insert(6);
			Tree.Insert(9);
			Tree.Insert(4);
			Tree.Insert(8);
			Tree.Insert(11);
			Tree.Print();
			std::vector<int> postorder;;
			Tree.Postorder(postorder);
			std::vector<int> result = { 2, 4, 3, 6, 8, 11, 9, 7, 5 };
			for (int i = 0; i < postorder.size(); ++i) {
				Assert::AreEqual(postorder[i], result[i]);
			}
		}
	};
}
