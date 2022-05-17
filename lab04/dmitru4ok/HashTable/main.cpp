#include "HashTable.h"
#include <iostream>

using std::cout;
using std::cin;


int main()
{
	HashTable<int> B(50);
	B.add("one", 1);
	B.add("two", 2);
	B.add("three", 3);
	B.add("four", 4);
	B.add("five", 5);
	B.add("six", 6);
	B.add("seven", 7);
	B.add("eight", 8);
	B.add("nine", 9);
	B.add("ten", 10);
	B.add("eleven", 11);
	B.add("twelve", 12);
	B.add("thirteen", 13);
	B.add("fourteen", 14);
	B.add("fifteen", 15);
	B.add("sixteen", 16);
	B.add("seventeen", 17);
	B.add("eighteen", 18);
	B.add("nineteen", 19);
	B.add("twenty", 20);
	B.add("twentyone", 21);
	B.add("twentytwo", 22);
	B.add("twentythree", 23);
	B.add("twentyfour", 24);
	B.add("twentyfive", 25);
	B.pop("twentyfive"); //no 25
	B.pop("eighteen");   //no 18
	B.pop("two");        //no 2
	B.add("smth", 5);    //add "smth"
	TableElem<int> a;
	pair<TableElem<int>*,int> arr  = B.values();
	
	for (int i = 0; i < arr.second; i++)
	{
		cout << arr.first[i];
	}
	
	if (B.get("one", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("two", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("three", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("four", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("five", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("six", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("seven", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("eight", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("nine", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("ten", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("eleven", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("twelve", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("thirteen", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("fourteen", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("fifteen", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("sixteen", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("seventeen", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("eighteen", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("nineteen", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	if (B.get("twenty", a))
	{
		cout << a.key << ' ' << a.value << '\n';
	}
	else
	{
		cout << "Not found\n";
	}
	system("pause");
	return 0;
}