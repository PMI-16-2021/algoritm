#include <iostream>
#include "tree.h"

int main()
{
	AvlTree avl;
	avl.insert(10);
	avl.insert(20);
	avl.insert(30);
	avl.insert(40);
	avl.insert(50);
	avl.insert(25);
	avl.printPreOrder();
	AvlTree::Node twenty = avl.getAt(20);
	std::cout << std::endl << twenty.getKey() << std::endl << twenty.getHeight();
	std::cout << std::endl << avl.getRoot().getKey() << std::endl << avl.getRoot().getHeight();

	system("pause");
	return 0;
}