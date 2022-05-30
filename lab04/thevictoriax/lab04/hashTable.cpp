#include <iostream>
#include "hashTable.h"
using namespace std;

//Elem::Elem() : value(), key(" ")
//{
//
//}
//
//Elem::Elem(int val, std::string k)
//{
//	value = val;
//	key = k;
//}

HashTable::HashTable()
	: count(0), size(10) 
{
	arr = new Elem[size];
}

HashTable::~HashTable() 
{
	delete[] arr;
}

bool HashTable::findElem(std::string k) 
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

void HashTable::add(int val, std::string k)
{
    if (findElem(k))
    {
        cout << "Key had already used";
    }
   /* if (count >= size)
    {
        cout << "Hash table is full";
    }*/
    int hashed = hash(k);
    while (arr[hashed].key != "" && arr[hashed].key != k)
    {
        ++hashed;
        hashed %= size;
    }
    arr[hashed].key = k;
    arr[hashed].value = val;
    //arr[hashed] = Elem(val, k);
    //++count;
}

int HashTable::getElem(std::string k)
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

int HashTable::hash(std::string k)
{
    int temp = 0;
    for (int i = 0; i < k.length(); ++i)
    {
        temp += k[i];
    }
    return temp % size;
}

bool HashTable::isEmpty() 
{
    return count == 0;
}

void HashTable::pop(std::string k)
{
    int hashed = hash(k);
    List<Elem> temp;
    while (arr[hashed].key != "") 
    {
        if (arr[hashed].key == k)
        {
            arr[hashed].key = "";
            --count;
            ++hashed;
            hashed %= size;
        }
        temp.addBack(arr[hashed]);
        arr[hashed].key = "";
        --count;
        ++hashed;
        hashed %= size;
    }
    while (!temp.isEmpty())
    {
        add(temp.getHead()->value.value, temp.getHead()->value.key);
        temp.deleteHead();
    }
}

void HashTable::values()  
{
    for (int i = 0; i < size; ++i) 
    {
        if (arr[i].key == "") 
        {
            cout << "¹" << i;
            cout << " key : "; /* cout.width(20);*/ cout << " value : " << '\n';
        }
        else 
        {
            cout << "¹" << i;
            cout << " key : "; cout << arr[i].key;/* cout.width(15);*/ cout << "  value :  " << arr[i].value << '\n';
        }
    }
}