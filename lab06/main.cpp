#include <iostream>
#include "matrix.h"
using namespace std;

int main() {

	SpaceMatrix<int> s(8, 8);
	s.set(1, 5, 2);
	s.set(3, 2, 6);
	s.set(6, 3, 2);
	s.print();
	SpaceMatrix<int> s1(8, 8);
	s1.set(2, 3, 4);
	s1.set(3, 2, 4);
	s1.set(5, 3, 6);
	s1.set(4, 3, 8);
	//s.addition(s1);
	//s.subtraction(s1);
	s.multiplication(s1);
	cout << "\n\n";

	s.print();

	system("pause");
	return 0;
}