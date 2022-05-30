#include "MySet.h"

int main() {
	MySet<int> myset1;
	myset1.add(3);
	myset1.add(7);
	myset1.add(9);
	myset1.print();

	MySet<int> myset2;
	myset2.add(3);
	myset2.add(5);
	myset2.add(4);
	myset2.print();

	std::cout << "DIFFERENCE\n";
	MySet<int> difference = myset1.differenceSet(myset2);
	difference.print();
	std::cout << "INTERSACTION\n";
	MySet<int> intersection = myset1.intersectionSet(myset2);
	intersection.print();
	std::cout << "UNION\n";
	MySet<int> unionS = myset1.unionSet(myset2);
	unionS.print();
	std::cout << "SYMETRIC\n";
	MySet<int> symetric = myset1.symmetricDifferenceSet(myset2);
	symetric.print();

	return 0;
}