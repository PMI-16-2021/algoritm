#include <iostream>
#include "set.h"
using namespace std;

int main() {

	Set S1;
	S1.add(1);
	S1.add(2);
	S1.add(3);
	S1.add(4);
	S1.print();
	cout << "\n";

	Set S2;
	S2.add(1);
	S2.add(3);
	S2.add(5);
	S2.add(7);
	S2.print();
	cout << "\n";

	Set result;
	cout << "\nUnion ";
	result = S1.unionS(S2);
	result.print();

	cout << "\nIntersection ";
	result = S1.intersectionS(S2);
	result.print();

	cout << "\nDifference ";
	result = S1.differenceS(S2);
	result.print();

	cout << "\nSymmetric difference ";
	result = S1.symmetricDifferenceS(S2);
	result.print();
	cout << "\n\n";

	system("pause");
	return 0;
}