#include <iostream>
#include "hTable.h"
using namespace std;

int main()
{
	HashTable HT;
    HT.add("Sam", 1);
    HT.add("Peter", 3);
    HT.add("Anthony", 5);
    HT.pop("Anthony");
    HT.values();
    cout << "\nValue: " << HT.get("Peter");
    cout << "\nHash:  " << HT.hash("Sam");

	system("pause");
	return 0;
}