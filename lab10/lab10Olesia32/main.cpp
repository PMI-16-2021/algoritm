#include <iostream>
#include "tree.h";
#include <vector>

int main() {
	AVLTree<int> Tree;
	Tree.Insert(8);
	Tree.Insert(3);
	Tree.Insert(10);
	Tree.Insert(1);
	Tree.Insert(6);
	Tree.Insert(14);
	Tree.Insert(11);
	Tree.Insert(4);
	Tree.Insert(7);
	Tree.Print();
	std::vector<int> preorder;
	std::vector<int> inorder;
	std::vector<int> postorder;
	Tree.Preorder(preorder);
	Tree.Inorder(inorder);
	Tree.Postorder(postorder);
	std::cout << "\nPreorder: \n";
	for (std::vector<int>::const_iterator it = preorder.cbegin(); it != preorder.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nInorder: \n";
	for (std::vector<int>::const_iterator it = inorder.cbegin(); it != inorder.cend(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << "\nPostorder: \n";
	for (std::vector<int>::const_iterator it = postorder.cbegin(); it != postorder.cend(); ++it) {
		std::cout << *it << " ";
	}
	system("pause");
	return 0;
}