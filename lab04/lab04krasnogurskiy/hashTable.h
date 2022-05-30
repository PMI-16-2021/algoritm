#pragma once
#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
class HashTable
{
	int m_size;
	int m_capacity;
	std::vector<std::pair<int, std::string>> m_hashtable;
	std::pair<int, std::string>** m_ptable;
	static std::pair<int, std::string> null_data;
public:
	HashTable();
	HashTable(int power_of_2_capacity);
	~HashTable();
	int size();
	int capacity();
	bool isEmpty() const;
	bool insert(int key, std::string data);
	void erase(int key);
	int hash(int key, bool& rehashing);
	int hash(int key);
	int find(int key, int r = 1);
	void print();
	std::string& operator[](int key);
	int key_colision(int key);
private:
	int rehash(int index_init, int r);
	int binaryToDecimal(std::string n);
	std::string decimalToBinary(int num);
	bool colision_check(int index);
	void reallocate(int new_capacity);
};