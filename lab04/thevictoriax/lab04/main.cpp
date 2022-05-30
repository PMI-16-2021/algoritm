#include <iostream>
#include "hashTable.h"
using namespace std;

int main()
{
	HashTable<int> HT;
	HT.add(7, "Jamie");
	HT.add(11, "Jack");
	HT.add(5, "Amie");
	HT.values();
	cout << "\n\n";
	HT.pop("Jack");
	HT.values();
	cout << "\nValue from key: " << HT.getElem("Amie")<<"\n\n";

	system("pause");
	return 0;
}