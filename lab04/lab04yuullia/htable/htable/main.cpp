#include <iostream>
#include "hash.h"
using namespace std;

int main()
{
	HashTable hashT;
	hashT.add("a", 0);
	hashT.add("b", 1);
	hashT.add("c", 2);
	hashT.add("d", 3);

	hashT.values();

	hashT.pop("d");
	hashT.pop("c");

	hashT.values();

	system("pause");
	return 0;
}