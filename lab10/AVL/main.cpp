#include "AVLTree.h"
using std::cout;

int main()
{
	Tree<int> A;
	
	cout << "\nheight: " << A.height() << '\n';
	A.insert(1);
	A.insert(2);
	cout << "\nheight: " << A.height() << '\n';
	A.print(); 
	A.insert(3);

	cout << '\n';
	A.print();
	A.insert(6);
	A.insert(2);
	A.insert(8);
	cout << "\nheight: " << A.height() << '\n';
	A.print();
	


	system("pause");
	return 0;
}