#include <iostream>
#include "hashTable.h"




int main()
{
	HashTable table(6);
	int count = 0;
	for (int i = 5; i < 35; i++)
	{
		if (table.insert(i * i, "abc"))
		{
			count++;
		}
	}
	for (int i = 5; i < 35; i++)
	{
		std::cout << table.find(i * i) << "\t";
	}
	std::cout << "\n\n" << count << std::endl;

	table.print();
	//HashTable table;

	//table.insert(16, "16 data");
	//table.insert(5, "5 data");
	//table.insert(21, "21 data");
	//table.insert(17, "17 data");
	//table.insert(299, "299 data");
	//table.erase(21);
	//table.print();
	return 0;
}