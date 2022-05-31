#include <iostream>
#include "has.h"
#include <string>
using namespace std;

int main() {

	string temp = "sergi";
	HashTable<double> Table;
	Table.add(temp, 1.2);
	temp = "romani";
	Table.add(temp, 0.2);
	temp = "dimi";
	Table.add(temp, 0.7);
	Table.values();
	Table.pop(temp);
	Table.values();

	system("pause");
	return 0;
}