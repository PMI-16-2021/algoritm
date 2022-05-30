#include <iostream>
#include "matrix.h"
using namespace std;

int main()
{
	Matrix M(2, 2);
	M.setVal(1, 1, 4);
	M.setVal(1, 2, 1);
	M.setVal(2, 1, 2);
	M.setVal(2, 2, 6);
	M.print();

	Matrix M2(2, 2);
	M2.setVal(1, 1, 3);
	M2.setVal(1, 2, 1);
	M2.setVal(2, 1, -3);
	M2.setVal(2, 2, 4);
	M2.print();

	
	system("pause");
	return 0;
}