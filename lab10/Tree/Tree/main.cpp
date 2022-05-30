#include "tree.h"

int main()
{
	Tree<int> tree;

	tree.insert(1);
	tree.insert(2);
	tree.print();

	tree.insert(3);
	std::cout << '\n';
	tree.print();

	tree.insert(6);
	tree.insert(2);
	tree.insert(8);
	tree.insert(7);
	tree.insert(5);
	tree.insert(4);
	std::cout << "\nheight: " << tree.height() << '\n';
	tree.print();



	system("pause");
	return 0;
}