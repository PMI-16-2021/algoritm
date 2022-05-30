#pragma once
#include <iostream>
#include "list.h"
#include <string>

template <typename T>
struct Elem
{
	T value;
	std::string key;
	Elem() : value(), key("") {}
	Elem(T val, std::string k);
};

template <typename T>
Elem<T>::Elem(T val, std::string k)
{
	value = val;
	key = k;
}

template <typename T>
class HashTable
{
private:
	Elem<T>* arr;
	int size;
	int count;
	int hash(std::string k);
	bool getInd(int& ind, std::string k);
public:
	HashTable();
	~HashTable();
	void add(T val, std::string k);
	T getElem(std::string k);
	void pop(std::string k);
	void values();
	int getSize();
	bool findElem(std::string k);
	bool isEmpty();
};

template <typename T>
HashTable<T>::HashTable()
	: count(0), size(10)
{
	arr = new Elem<T>[size];
}

template <typename T>
HashTable<T>::~HashTable()
{
	delete[] arr;
}

template <typename T>
bool HashTable<T>::findElem(std::string k)
{
	int _hash = hash(k);
	while (arr[_hash].key != "")
	{
		if (arr[_hash].key == k)
		{
			return true;
		}
		++_hash;
		_hash %= size;
	}
	return false;
}

template <typename T>
void HashTable<T>::add(T val, std::string k)
{
	if (findElem(k))
	{
		cout << "Key had already used";
	}
	 if (count >= size)
	 {
		 cout << "Hash table is full";
	 }
	int hashed = hash(k);
	while (arr[hashed].key != "" && arr[hashed].key != k)
	{
		++hashed;
		hashed %= size;
	}
	arr[hashed].key = k;
	arr[hashed].value = val;
	++count;
}

template <typename T>
T HashTable<T>::getElem(std::string k)
{
	int hashed = hash(k);
	while (arr[hashed].key != "")
	{
		if (arr[hashed].key == k)
		{
			return arr[hashed].value;
		}
		++hashed;
		hashed %= size;
	}
	cout << "There aren't such key\n";
	return -1;
}

template <typename T>
int HashTable<T>::hash(std::string k)
{
	int temp = 0;
	for (int i = 0; i < k.length(); ++i)
	{
		temp += k[i];
	}
	return temp % size;
}

template <typename T>
bool HashTable<T>::isEmpty()
{
	return count == 0;
}

template <typename T>
void HashTable<T>::pop(std::string k)
{
	int place = 0;
	bool exist = false;
	int hashed = hash(k);
	List<Elem<T>> temp;
	exist = getInd(place, k);
	if (exist)
	{
		arr[place].key = "";
		--count;
		place = (place + hashed) % (size - 7);
	}
	while (!temp.isEmpty())
	{
		add(temp.getHead()->value.value, temp.getHead()->value.key);
		temp.deleteHead();
	}
}

template <typename T>
bool HashTable<T>::getInd(int& ind, std::string k)
{
	bool result = false;                                  
	int step = hash(k);                               
	int hashed = step;                                      

	while (arr[hashed].key != k && arr[hashed].key != "")  
	{
		hashed = (hashed + step) % (size - 7);              
	}
	if (arr[hashed].key == k)                        
	{
		ind = hashed;                                     
		result = true;                                    
	}
	return result;
}

template <typename T>
void HashTable<T>::values()
{
	for (int i = 0; i < size; ++i)
	{
		if (arr[i].key == "")
		{
			
			cout << "#" << i << " key : " <<"\n" << " value : " << "\n";
		}
		else
		{
			cout << "#" << i << " key : "; cout << arr[i].key <<"\n" << "  value :  " << arr[i].value << "\n";
		}
	}
}