#include "Tree.h"
using std::cout;
using std::cin;



int main()
{

	Set<int> A;
	A.add(4);
	A.add(3);
	A.add(0);
	A.add(10);

	A.print();
	cout << '\n';
	Set<int> B;
	B.add(4);
	B.add(4);
	B.add(7);
	B.add(0);
	B.add(10);
	B.print();
	cout << '\n';
	



	A = A.Union(B);
	A.print();

	

	system("pause");
	return 0;
}