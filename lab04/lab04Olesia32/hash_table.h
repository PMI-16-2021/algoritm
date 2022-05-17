#pragma once
#include <iostream>
#include <string>
#include "list.h"
using namespace std;

template <typename V>
struct HashNode {
    string key;
    V value;
    HashNode() : key(""), value() {}
    HashNode(string _key, V _value) : key(_key), value(_value) {}
};

template <typename V>
class HashTable {
private:
    HashNode<V>* table;
	size_t count;
    size_t size;
    int Hash(string key);
public:
    HashTable();
	HashTable(size_t _size);
	~HashTable();
    void Add(string key, V element);
    V Get(string key);
    bool Find(string key);
    void Values();
    bool IsEmpty();
    int Size();
    void Pop(string key);
};

template <typename V>
HashTable<V>::HashTable() : count(0), size(10) {
    table = new HashNode<V>[size];
}

template <typename V>
HashTable<V>::HashTable(size_t _size): count(0), size(_size) { 
    table = new HashNode<V>[size];
}

template <typename V>
HashTable<V>::~HashTable() {
    delete[] table;
}

template <typename V>
int HashTable<V>::Hash(string key) {
    int temp = 0;
    int j = key.length();
    for (size_t i = 0; i < j; ++i) {
        temp += key[i];
    }
    return temp % size;
}

template <typename V>
void HashTable<V>::Add(string key, V element) {
   if (count >= size) {
      throw "HashTable is full";
   }
   if (Find(key)) {
      throw "This key is already used";
   }
    int index = Hash(key);
    while (table[index].key != "" && table[index].key != key) {
        ++index;
        index %= size;
    }
    table[index] = HashNode<V>(key, element);
    ++count;
}

template <typename V>
V HashTable<V>::Get(string key) {
    int index = Hash(key);
    while (table[index].key != "") {
        if (table[index].key == key) {
            return table[index].value;
        }
        ++index;
        index %= size;
    }
    cout << "Key not found";
}

template <typename V>
bool HashTable<V>::Find(string key) {
    int index = Hash(key);
    while (table[index].key != "" ) {
        if (table[index].key == key) {
            return true;
        }
        ++index;
        index %= size;
    }
    
    return false;
}

 template <typename V>
void HashTable<V>::Values() {
    for (size_t i = 0; i < size; ++i) {
        if (table[i]. key == "") {
            cout << "#" << i << " key = - " << " value = -" << '\n';
        }
        else {
            cout << "#" << i << " key = " << table[i].key << " value = " << table[i].value << '\n';
        }
    }
}

template <typename V>
bool HashTable<V>::IsEmpty() {
    return count == 0;
}

template <typename V>
int HashTable<V>::Size() {
    return count;
}

template <typename V> 
void HashTable<V>::Pop(string key) {
    int index = Hash(key);
    List<HashNode<V>> temp;
    while (table[index].key != "") {
        if (table[index].key == key) {
            table[index].key = "";
            --count;
            ++index;
            index %= size;
        }
        temp.AddBack(table[index]);
        table[index].key = "";
        --count;
        ++index;
        index %= size;
    }
    while (!temp.IsEmpty()) {
        Add(temp.Begin()->value.key, temp.Begin()->value.value);
        temp.DelFirst();
    }
}
