#include <iostream>
#include "matrix.h"

int main()
{
	SparseMatrix m(20, 21);
	m.set_value(0, 0, 1);
	m.set_value(0, 0, 4);
	m.set_value(0, 1, 1);
	m.set_value(1, 0, 1);
	m.set_value(1, 1, 1);
	m.set_value(2, 1, 1);
	m.set_value(1, 2, 2);
	m.set_value(0, 3, 3);
	m.set_value(2, 2, 1);
	m.set_value(7, 9, 1);
	m.set_value(10, 7, 1);
	//
	m.set_value(11, 11, 11);
	m.set_value(11, 4, 11);
	//
	m.set_value(10, 10, 3);
	m.set_value(17, 19, 2);

	m.print(std::cout);
	std::cout << '\n';

	SparseMatrix m1(7, 5);
	//
	m1.set_value(4, 3, 2);
	//
	m1.set_value(0, 0, 1);
	m1.set_value(0, 0, 4);
	m1.set_value(0, 1, 1);
	m1.set_value(1, 2, 7);
	m1.set_value(2, 2, 7);
	m1.set_value(3, 0, 12);
	m1.print(std::cout);
	std::cout << '\n';
	SparseMatrix m2(7, 5);
	m2.set_value(4, 3, 2);
	//
	m2.set_value(0, 0, 1);
	m2.set_value(0, 0, 4);
	m2.set_value(0, 1, 1);
	m2.set_value(1, 2, 7);
	m2.set_value(2, 2, 7);
	m2.set_value(3, 0, 12);

	SparseMatrix r(100, 100);

	r = m2 + m1;
	r.print(std::cout);
	std::cout << '\n';
	r = r * 2;
	r.print(std::cout);
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';
	r + r;
	r.print(std::cout);
	std::cout << '\n';
	std::cout << '\n';
	std::cout << '\n';


	// ПОЛОМКА ЯКАСЬ :-(
	//SparseMatrix m3(3, 3);			
	//SparseMatrix m31(1000, 2000);
	//SparseMatrix m32(2000, 900);
	//m31.set_value(10, 100, 7);
	//m32.set_value(100, 20, 7);

	//m3 = m31 * m32;

	//std::cout << m3.get_value(10, 20); // 49 ?

	//m3.print(std::cout);
	//std::cout << '\n';

	std::cout << '\n';
	std::cout << '\n';

	system("pause");
	return 0;
}