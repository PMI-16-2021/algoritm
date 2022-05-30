#include "Header.h"

int main()
{
	cout << "Container #1 :" << endl;
	MySet<int> mySet;
	mySet.add(5);
	mySet.add(2);
	mySet.add(9);
	mySet.add(11);
	mySet.add(2);
	mySet.add(2);
	mySet.add(3);
	mySet.print();

	cout << endl << "Remove 5 from container #1" << endl;
	mySet.remove(5);
	mySet.print();

	cout << "Current length = " << mySet.len() << endl << endl;
	const int check = 3;
	if (mySet.in(check)) cout << "Container #1 contains element " << check << endl;
	else cout << "Set does not contain element " << check << endl;

	cout << endl << "Container #2 :" << endl;
	MySet<int> other;
	other.add(7);
	other.add(2);
	other.add(3);
	other.add(3);
	other.add(5);
	other.add(5);
	other.print();

	cout << endl << "Union container :" << endl;
	MySet<int> resultSet = mySet.unionOther(other);
	resultSet.print();
	resultSet.makeEmpty();

	cout << endl << "Intersection container :" << endl;
	resultSet = mySet.intersection(other);
	resultSet.print();
	resultSet.makeEmpty();

	cout << endl << "Difference container :" << endl;
	resultSet = mySet.difference(other);
	resultSet.print();
	resultSet.makeEmpty();

	cout << endl << "Symmetric_difference container :" << endl;
	resultSet = mySet.symmetric_difference(other);
	resultSet.print();
	resultSet.makeEmpty();

	mySet.makeEmpty();
	other.makeEmpty();
	return 0;
}