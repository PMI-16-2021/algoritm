#pragma once
#include <iostream>
#include <string>
#include "list.h"
using namespace std;

template <typename T>
struct TableElement {
    T value;
    string key;

    TableElement() : value(), key("") {}
    TableElement(T val, string k) : value(val), key(k) {}
};

template <typename T>
class HashTable {
private:
    TableElement<T>* table;
    int size;
    int count;

    int _hash(string k);
public:
    HashTable();
    HashTable(int _size);
    ~HashTable();

    bool isEmpty();
    void add(T val, string k);
    bool checkKey(string k);
    void pop(string k);
    T get(string k);
    int elemCount();
    void values();
};

template <typename T>
HashTable<T>::HashTable() : size(5), count(0) {
    table = new TableElement<T>[size];
}

template <typename T>
HashTable<T>::HashTable(int _size) : size(_size), count(0) {
    table = new TableElement<T>[size];
}

template <typename T>
HashTable<T>::~HashTable() {
    delete[] table;
}

template <typename T>
int HashTable<T>::_hash(string k) {
    int temp = 0;
    int length = k.length();
    for (int i = 0; i < length; ++i) {
        temp += k[i];
    }
    return temp % size;
}

template <typename T>
bool HashTable<T>::isEmpty() {
    return count == 0;
}

template <typename T>
void HashTable<T>::add(T val, string k) {
    if (count >= size) {
        throw "HashTable is full";
    }
    if (checkKey(k)) {
        throw "This word is already used";
    }
    int index = _hash(k);
    while (table[index].key != "" && table[index].key != k) {
        ++index;
        index %= size;
    }
    table[index] = TableElement<T>(val, k);
    ++count;
}

template <typename T>
bool HashTable<T>::checkKey(string k) {
    int index = _hash(k);
    while (table[index].key != "") {
        if (table[index].key == k) {
            return true;
        }
        ++index;
        index %= size;
    }

    return false;
}

template <typename T>
void HashTable<T>::pop(string k) {
    int index = _hash(k);
    List<TableElement<T>> temp;
    while (table[index].key != "") {
        if (table[index].key == k) {
            table[index].key = "";
            --count;
            ++index;
            index %= size;
        }
        temp.pushBack(table[index]);
        table[index].key = "";
        --count;
        ++index;
        index %= size;
    }
    while (!temp.isEmpty()) {
        add(temp.showTop()->value.value, temp.showTop()->value.key);
        temp.deleteFirst();
    }
}

template <typename T>
T HashTable<T>::get(string k) {
    int index = _hash(k);
    while (table[index].key != "") {
        if (table[index].key == k) {
            return table[index].value;
        }
        ++index;
        index %= size;
    }
    cout << "Key not found";
}

template <typename T>
int HashTable<T>::elemCount() {
    return count;
}

template <typename T>
void HashTable<T>::values() {
    std::cout << "HashTable: \n";
    for (int i = 0; i < size; ++i) {
        if (table[i].key != "") {
            std::cout << "Key [" << table[i].key << "], ";
            std::cout << "value: " << table[i].value << '\n';
        }
    }
    std::cout << '\n';
}