#include<iostream>
#include"Sparse_Matrix.h"
using namespace std;

int main() 
{

	SparseMatrix A(3, 3);
	A.Set_Value(0, 1, 5);     // 0 5 0
	A.Set_Value(1, 2, 9);     // 0 0 9
	A.Set_Value(2, 0, 4);    // 4 0 0
	SparseMatrix B(3, 3);
	B.Set_Value(0, 0, 5);  // 5 0 0
	B.Set_Value(1, 1, 8);  // 0 8 0
	B.Set_Value(2, 2, 7); // 0 0 7
	SparseMatrix R = A + B;
	R.Print();





    system("pause");
    return 0;
}

