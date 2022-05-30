#include<iostream>
#include "SparseMatrix.h"
using namespace std;

int main() {
	SparseMatrix<int> A(2, 2);
	A.set(0, 1, 5);
	A.set(1, 0, 9);
	A.set(1, 1, 4);
	cout << "Matrix A:\n";
	A.print();
	cout << "\n";
	SparseMatrix<int> B(2, 2);
	B.set(0, 1, 3);
	B.set(1, 1, 7);
	cout << "Matrix B:\n";
	B.print();
	cout << "\n";
	SparseMatrix<int> AD(2, 2);
	AD = A.addition(B);
	cout << "A + B:\n";
	AD.print();
	cout << "\n";
	SparseMatrix<int> SB(2, 2);
	SB = A.subtraction(B);
	cout << "A - B:\n";
	SB.print();
	cout << "\n";
	SparseMatrix<int> M(2, 2);
	M = A.multiplication(B);
	cout << "A * B:\n";
	M.print();

	system("pause");
	return 0;
}