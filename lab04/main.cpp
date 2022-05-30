#include <iostream>
#include "hashTable.h"
using namespace std;

int main()
{
	HashTable<double> Table;
	cout << "HashTable is empty(1), if not(0): " << Table.isEmpty() << "\n\n";
	Table.add(0.0, "leon");
	Table.add(1.6, "squeak");
	Table.add(2.7, "pam");
	Table.add(3.8, "elprimo");
	Table.add(5.7, "edgar");
	Table.values();
	cout << "HashTable is empty(1), if not(0): " << Table.isEmpty() << "\n\n";
	Table.pop("pam");
	Table.pop("edgar");
	Table.values();
	cout << "Get by key (elprimo) a value: " << Table.get("elprimo") << "\n\n";
	cout << "Elements in HashTable: " << Table.elemCount() << "\n\n";
	
	return 0;
}