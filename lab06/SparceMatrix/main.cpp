#include "SparceMatrix.h"
#include <iostream>

using std::cin;
using std::cout;

int main()
{
	
	SparceMatrix<int> A(4, 4);
	
	A.set(0, 0, 10);
	A.set(0, 1, 5);
	A.set(0, 2, 6);
	A.set(3, 3, 5);
	A.set(2, 2, 17);
	A.erase_elem(2, 1);
	cout << "OPERATOR: " << A[0][1] << '\n';
	vector<RawElem<int>> vect;
	A.significant_elements(vect);
	
	A.print();
	
	
	SparceMatrix<int> NEW(A);
	cout << '\n';
	cout << "OPERATOR: " << NEW[0][1] << '\n';
	NEW.print();


	system("pause");
	return 0;
}