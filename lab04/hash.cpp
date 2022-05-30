#include "hash.h"
#include <iostream>
using namespace std;


HashTable::HashTable() {}
HashTable::HashTable(int v, std::string k)
{

}
HashTable::~HashTable() 
{
	//for (size_t i = 0; i < n; ++i)
	//	delete hashTable[i];
}
int HashTable::_hash(std::string key)
{
	int value = 0;
	for (int i = 0; i < key.length(); ++i) {
		value += key[i];
	}
	return value % n;
}
void HashTable::add(int v, std::string k)
{
	//hashNode h (int v, std::string k);
	int index = _hash(k);
	if (hashTable[index].key != " ")
	{
		while (hashTable[index].key != " ") {
			++index;
		}
	}
	hashTable[index].key = k;
	hashTable[index].value = v;
}
void HashTable::elements() 
{
	for (int i = 0; i < n; ++i)
	{
		if (hashTable[i].key != " ") {
			cout << "key: " << hashTable[i].key << " value: " << hashTable[i].value << "\n";
		}
	}
}
int HashTable::get(std::string k)
{
	int index = _hash(k);
	for (int i = index; i < n; ++i)
	{
		if (hashTable[i].key == k) {
			return hashTable[i].value;
		}
		++index;
		index %= n;
	}
	cout << "WRONG KEY\n";
}
void  HashTable::pop(std::string k)
{
	int index = _hash(k);
	for (int i = index; i < n; ++i)
	{
		if (hashTable[i].key == k) {
			hashTable[i].key = " ";
			hashTable[i].value = 0;
			return;
		}
		++index;
		index %= n;
	}
	cout << "WRONG KEY\n";
}

int HashTable::size()
{
	int count = 0;
	for (int i = 0; i < n; ++i)
	{
		if (hashTable[i].key != " ") {
			++count;
		}
	}
	return count;
}

bool  HashTable::isEmpty()
{
	for (int i = 0; i < n; ++i)
	{
		if (hashTable[i].key == " ") {
			continue;
		}
		else {
			return false;
		}
	}
	return true;
}