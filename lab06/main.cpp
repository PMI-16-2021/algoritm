#include <iostream>
#include "sparseMatrix.h"
using namespace std;

int main() {
	SparseMatrix S1(3, 3);
	S1.set(1, 2, 2);
	S1.set(2, 1, 3);
	S1.set(2, 2, 9);
	SparseMatrix S2(3, 3);
	S2.set(0, 1, 5);
	S2.set(1, 1, 2);
	S2.set(1, 2, 4);
	cout << "Matrix 1:\n";
	S1.print();
	cout << "\nMatrix 2:\n";
	S2.print();
	SparseMatrix S3(3, 3);
	cout << "\nAddition:\n";
	S3 = S1.addition(S2);
	S3.print();
	SparseMatrix S4(3, 3);
	cout << "\nSubtraction:\n";
	S4 = S1.subtraction(S2);
	S4.print();
	SparseMatrix S5(3, 3);
	cout << "\nMultiplication:\n";
	S5 = S1.multiplication(S2);
	S5.print();

	return 0;
}