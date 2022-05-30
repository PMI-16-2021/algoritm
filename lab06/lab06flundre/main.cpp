#include <iostream>
#include "SparseMatrix.h"

using namespace std;

int main() {

	SparseMatrix<int> A(3, 3);
	A.set(1, 1, 5);     
	A.set(1, 2, 9);     
	A.set(2, 1, 4);    
	SparseMatrix<int> B(3, 3);
	B.set(1, 1, 5);  
	B.set(1, 2, 8);  
	B.set(2, 2, 7); 
	SparseMatrix<int> C = A.addition(B);
	C.print();

	system("pause");
	return 0;
}