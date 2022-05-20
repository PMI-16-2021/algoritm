#pragma once
#include <iostream>
#include<string>
using namespace std;

template<typename K, typename V>
struct HashElement {
    K key;
    V value;
    HashElement(K key, V value) 
        : key(key), value(value) {}
};

template<typename K, typename V>
class HashTable
{
private:
    HashElement<K, V>** elem;
    int capacity;
    int size;   //current size
    HashElement<K, V>* dummy;   
public:
    HashTable();
    int hash(K key);
    void add(K key, V value);
    V pop(K key);
    V get(K key);
    int sizeofTable();
    void values();
};

template<typename K, typename V>
HashTable<K, V>::HashTable() 
    : capacity(20), size(0) 
{
    elem = new HashElement<K, V>*[capacity];
    for (int i = 0; i < capacity; ++i) { 
        elem[i] = NULL;
    }
    dummy = new HashElement<K, V>("", -1);  
}

template<typename K, typename V>
int HashTable<K, V>::hash(K key) {
    return key.length() % capacity;
}

template<typename K, typename V>
void HashTable<K, V>::add(K key, V value) {
    HashElement<K, V>* temp = new HashElement<K, V>(key, value);
    int hashIndex = hash(key);    
    while (elem[hashIndex] != NULL && elem[hashIndex]->key != key && elem[hashIndex]->key.length() != -1) { 
        ++hashIndex;
        hashIndex %= capacity;
    }
    if (elem[hashIndex] == NULL || elem[hashIndex]->key.length() == -1) {    
        ++size;
    }
    elem[hashIndex] = temp;
}

template<typename K, typename V>
V HashTable<K, V>::pop(K key) {
    int hashIndex = hash(key);     
    while (elem[hashIndex] != NULL) {   
        if (elem[hashIndex]->key == key)   {
            HashElement<K, V>* temp = elem[hashIndex];
            elem[hashIndex] = dummy;  
            --size;
            return temp->value;
        }
        ++hashIndex;
        hashIndex %= capacity;
    }
    return NULL; 
}

template<typename K, typename V>
V HashTable<K, V>::get(K key) {
    int hashIndex = hash(key);      
    while (elem[hashIndex] != NULL) {     
        int counter = 0;
        if (++counter > capacity)  
            return NULL;
        else if (elem[hashIndex]->key == key) {   
            return elem[hashIndex]->value;
        }
        ++hashIndex;
        hashIndex %= capacity;
    }
    return NULL;
}

template<typename K, typename V>
int  HashTable<K, V>::sizeofTable() {
    return size;
}

template<typename K, typename V>
void HashTable<K, V>::values() {
    for (int i = 0; i < capacity; ++i)
    {
        if (elem[i] != nullptr) {
            cout << "key = " << elem[i]->key << "  value = " << elem[i]->value << "\n";
        }
    }
}