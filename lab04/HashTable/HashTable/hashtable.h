#pragma once
#include <string>

#include "list.h"

template <typename T>
struct Node {
    std::string key;
    T value;

    Node(): key(""), value() {}
    Node(std::string _key, T _value);
};

template <typename T>
Node<T>::Node(std::string _key, T _value) {
    key = _key;
    value = _value;
}

template <typename T>
class HashTable {
private:
    Node<T>* table;
    int count;
    int size; //max size
    int hash(std::string _key);

public:
    HashTable();
    ~HashTable();

    void add(std::string _key, T _value);
    T get(std::string _key);
    void pop(std::string _key);
    void values() const;
    bool find(std::string _key);
    bool IsEmpty();
    int Size();
};

template <typename T>
HashTable<T>::HashTable()
    : count(0), size(10) {
    table = new Node<T>[size];
}

template <typename T>
HashTable<T>::~HashTable() {
    delete[] table;
}

template <typename T>
void HashTable<T>::add(std::string key, T value) {
    if (find(key)) {
        std::cerr << "This key is already used";
    }
    if (count >= size){
        std::cout << "Your hash table is already full";
    }
    int _hash = hash(key);
    while (table[_hash].key != "" && table[_hash].key != key) {
        ++_hash;
        _hash %= size;
    }
    table[_hash] = Node<T>(key, value);
    ++count;
}

template <typename T>
T HashTable<T>::get(std::string key) {
    int _hash = hash(key);
    while (table[_hash].key != "") {
        if (table[_hash].key == key) {
            return table[_hash].value;
        }
        ++_hash;
        _hash %= size;
    }
    std::cout << "Key not found";
    return -1;
}

template <typename T>
int HashTable<T>::hash(std::string _key) {
    int temp = 0;
    for (int i = 0; i < _key.length(); ++i) {
        temp += _key[i];
    }
    return temp % size;
}

template <typename T>
void HashTable<T>::pop(std::string key) {
    int _hash = hash(key);
    List<Node<T>> local;
    while (table[_hash].key != "") {
        if (table[_hash].key == key) {
            table[_hash].key = "";
            --count;
            ++_hash;
            _hash %= size;
        }
        local.addBack(table[_hash]);
        table[_hash].key = "";
        --count;
        ++_hash;
        _hash %= size;
    }
    while (!local.isEmpty()) {
        add(local.First()->value.key, local.First()->value.value);
        local.deleteFirst();
    }
}

template <typename T>
void HashTable<T>::values() const {
    for (size_t i = 0; i < size; ++i) {
        if (table[i].key == "") {
            std::cout << "¹" << i;
            std::cout << " key : ";  std::cout.width(20); std::cout << " value : " << '\n';
        }
        else {
            std::cout << "¹" << i;
            std::cout << " key : "; std::cout << table[i].key; std::cout.width(15); std::cout << "  value :  " << table[i].value << '\n';
        }
    }
}

template <typename T>
bool HashTable<T>::find(std::string _key) {
    int _hash = hash(_key);
    while (table[_hash].key != "") {
        if (table[_hash].key == _key) {
            return true;
        }
        ++_hash;
        _hash %= size;
    }
    return false;
}

template <typename T>
bool HashTable<T>::IsEmpty() {
    return count == 0;
}

template <typename T>
int HashTable<T>::Size() {
    return count;
}