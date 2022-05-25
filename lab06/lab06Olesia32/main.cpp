#include <iostream>
#include "matrix.h"
using namespace std;

int main() {
	SparseMatrix<int> S1(5, 5);
	S1.Set(1, 3, 4);
	S1.Set(1, 2, 6);
	S1.Set(3, 1, 7);
	SparseMatrix<int> S2(5, 5);
	S2.Set(2, 3, 4);
	S2.Set(1, 2, 6);
	S2.Set(0, 1, 7);
	S2.Set(4, 3, 8);
	S2.Set(0, 4, 9);
	cout << "Matrix 1: \n";
	S1.Print();
	cout << "\nMatrix 2: \n";
	S2.Print();
	SparseMatrix<int> S3(5, 5);
	cout << "\n\nMultiplication: \n";
	S3 = S1.Multiplication(S2);
	S3.Print();
	SparseMatrix<int> S4(5, 5);
	cout << "\n\nAddition: \n";
	S4 = S1.Addition(S2);
	S4.Print();
	SparseMatrix<int> S5(5, 5);
	cout << "\n\nSubtraction: \n";
	S5 = S1.Subtraction(S2);
	S5.Print();
	system("pause");
	return 0;
}