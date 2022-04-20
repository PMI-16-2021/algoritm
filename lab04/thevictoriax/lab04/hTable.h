#pragma once
#include <string>
struct Pair
{
	std::string key;
	int value;
	Pair* next;
	Pair* previous;

	Pair(std::string k, int val);
};

class HashTable
{
private:
	int num;
	Pair* head;
	Pair* tail;

public:
	HashTable();
	void add(std::string, int);
	int get(std::string);
	int hash(std::string);
	bool pop(std::string);
	void values();
	bool isEmpty();
};