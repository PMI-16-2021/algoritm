#pragma once
#include <string>
using std::string;


template<typename T = int>
class HashTable
{
public:
	struct TableElem
	{
		string key;
		T value;

		TableElem( T val = T(), string _key = string());
	};

private:
	TableElem* m_memory;
	int m_size;

public:
	HashTable() : m_size(5), m_memory(m_size) {}
	HashTable(int _size);
	void add(string k);

};

template<typename T>
HashTable<T>::HashTable(int _size)
{
	m_size = (_size > 0) ? _size : 5;
	m_memory = new TableElem[m_size];
}

template<typename T>
void HashTable<T>::add(string k)
{
	
}


template<typename T>
HashTable<T>::TableElem::TableElem(T val, string _key)
{
	value = val;
	key = _key;
}
