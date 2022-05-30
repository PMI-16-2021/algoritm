#pragma once
#include <iostream>
#include <string>

struct hashNode {
	int value;
	std::string key;
	hashNode() :
		value(0), key(" ")
	{}
	hashNode(int v, std::string k):
		value(v), key(k)
	{}
};

class HashTable {
private:
	static const int n = 100;
	hashNode hashTable[n];
	int _hash(std::string key);
public:
	HashTable();
	HashTable(int v, std::string k);
	~HashTable();
	void add(int v, std::string k);
	void elements();
	int get(std::string k);
	void pop(std::string k);
	int size();
	bool isEmpty();
};
