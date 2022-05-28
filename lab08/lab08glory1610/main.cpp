#include<iostream>
#include "MySet.h"
using namespace std;

int main()
{
	MySet<int> A;
	A.add(5);
	A.add(1);
	A.add(2);
	A.add(3);
	A.add(2);
	cout << "A = ";
	A.print();

	MySet<int> B;
	B.add(10);
	B.add(5);
	B.add(4);
	B.add(2);
	cout << "B = ";
	B.print();

	MySet<int> U;
	cout << "A union B = ";
	U = A.Union(B);
	U.print();

	MySet<int> I;
	cout << "A intersection B = ";
	I = A.Intersection(B);
	I.print();

	MySet<int> AD;
	cout << "A difference B = ";
	AD = A.Difference(B);
	AD.print();

	MySet<int> BD;
	cout << "B difference A = ";
	BD = B.Difference(A);
	BD.print();

	MySet<int> ASD;
	cout << "A S_difference B = ";
	ASD = A.Symmetric_difference(B);
	ASD.print();

	MySet<int> BSD;
	cout << "B S_difference A = ";
	BSD = B.Symmetric_difference(A);
	BSD.print();
	

	system("pause");
	return 0;
}
