#include<iostream>
#include"sparse_matrix.h"
using namespace std;
int main() {
	SparseMatrix<int> M1 (4,4);
    M1.Set(0, 2, 8);
    M1.Set(0, 0, 6);
    M1.Set(0, 3, 5);
    M1.Set(1, 0, 5);
    M1.Set(1, 2, 4);
    M1.Set(1, 3, 3);
    M1.Set(2, 2, 2);
    M1.Set(2, 1, 2);
    M1.Set(3, 3, 1);
    SparseMatrix<int>M2(4,4);
    M2.Set(0, 1, 2);
    M2.Set(0, 2, 4);
    M2.Set(0, 3, 4);
    M2.Set(1, 0, 5);
    M2.Set(1, 1, 6);
    M2.Set(1, 2, 6);
    M2.Set(2, 3, 7);
    M2.Set(2, 1, 8);
    M2.Set(3, 3, 9);
    M2.Print();
    cout<<"---------- \n";
    M1.Print();
    SparseMatrix<int> newMatrix1= M1.Addition(M2);
    cout<<"---------- \n";
    newMatrix1.Print();

    SparseMatrix<int> newMatrix2 = M1.Multiplication(M2);
    cout << "---------- \n";
    newMatrix2.Print();

    SparseMatrix<int> newMatrix3 = M1.Substraction(M2);
    cout << "---------- \n";
    newMatrix3.Print();




	system("pause");
	return 0;
}