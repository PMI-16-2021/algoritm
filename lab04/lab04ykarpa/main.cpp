#include <iostream>
#include "hashTable.h"
using namespace std;

int main() {
	TableElement t1(1, true, 'c', 3.2);
	TableElement t2(2, true, 'd', 4.3);
	TableElement t3(3, false, 'e', 5.4);
	TableElement t4(0, true, 'h', 6.5);

	HashTable H;
	H.addRow(t1);
	H.addRow(t2);
	H.addRow(t3);
	H.addRow(t4);

	H.printTable();

	system("pause");
	return 0;
}