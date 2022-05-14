#include "SparceMatrix.h"

using std::cin;
using std::cout;

int main()
{
	
	SparceMatrix<int> matr(3, 3);
	SparceMatrix<int> other(3, 3);
	matr.set(2, 2, 5);       // 8 0 0
	matr.set(2, 1, 10);      // 0 0 7
	matr.set(1, 2, 7);       // 0 10 5
	matr.set(0, 0, 8);
	

	other.set(0, 0, 5);      // 5 0 7 
	other.set(1, 2, 5);      // 3 0 5
	other.set(0, 2, 7);      // 1 3 4
	other.set(2, 0, 1);
	other.set(1, 0, 3);
	other.set(2, 1, 3);
	other.set(2, 2, 4);
	cout << "matr: \n";
	matr.print();
	cout << "other: \n";
	other.print();
	SparceMatrix<int> result = matr.multiplication(other);
	cout << "result: \n";
	result.print();
	system("pause");
	return 0;
}