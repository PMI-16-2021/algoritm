#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
	SparseMatrix SM1(4, 4);
	SM1.set(1, 0, 1);
	SM1.set(0, 1, 2);
	SM1.set(1, 2, 3);
	SM1.set(2, 1, 4);
	cout << "Matrix1:\n";
	SM1.print();

	SparseMatrix SM2(4, 4);
	SM2.set(0, 3, 4);
	SM2.set(1, 2, 3);
	SM2.set(2, 1, 2);
	SM2.set(3, 0, 1);
	cout << "Matrix 2:\n";
	SM2.print();
	
	SparseMatrix result(4, 4);

	cout << "Addition:\n";
	result = SM1.addition(SM2);
	result.print();

	cout << "Subtraction:\n";
	result = SM1.subtraction(SM2);
	result.print();

	cout << "Multiplication:\n";
	result = SM1.multiplication(SM2);
	result.print();

	system("pause");
	return 0;
}