#include <iostream>
#include "Hashtable.h"

using namespace std;

int main() {
	TableElement t1(1, true, 'c', 3.0);
	TableElement t2(2, false, 'd', 4.4);
	TableElement t3(3, false, 'e', 5.1);
	TableElement t4(0, true, 'h', 6.2);

	HashTable H;
	H.addRow(t1);
	H.addRow(t2);
	H.addRow(t3);
	H.addRow(t4);

	H.printTable();

	system("pause");
	return 0;
}