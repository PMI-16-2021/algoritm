#pragma once
#include"list.h"
using std::string;

template<typename T>
struct HashTableNode {
    string key;
    T value;
    HashTableNode();
    HashTableNode(string _key, T _value);
    HashTableNode(const HashTableNode<T>& other);
    friend std::ostream& operator<<(std::ostream& out, const HashTableNode<T>& _element) {
        return out << _element.key << ':' << _element.value;
    }
};
template<typename T>
HashTableNode<T>::HashTableNode() : key(""), value(T(0)) {}
template<typename T>
HashTableNode<T>::HashTableNode(string _key, T _value) : key(_key), value(_value) {}
template<typename T>
HashTableNode<T>::HashTableNode(const HashTableNode<T>& other) : key(other.key), value(other.value) {}

template<typename T>
class HashTable {
private:
    int size_;
    List<HashTableNode<T>>* table_;
public:
    HashTable();
    HashTable(int size);
    ~HashTable();
    void Add(HashTableNode<T>& _element);
    T& Get(const string& _key);
    int Hash(string _key);
    T Pop(const string& _key);
    void Values() const;
};

template<typename T>
HashTable<T>::HashTable() : size_(10), table_(new List<HashTableNode<T>>[size_]) {}
template<typename T>
HashTable<T>::HashTable(int size) : size_(size), table_(new List<HashTableNode<T>>[size_]) {}
template<typename T>
HashTable<T>::~HashTable() {
    delete[] table_;
}

template<typename T>
int HashTable<T>::Hash(string _key) {
    int temp = 0;
    int j = _key.length();
    for (int i = 0; i < j; ++i) {
        temp += _key[i];
    }
    return temp % size_;
}

template<typename T>
T& HashTable<T>::Get(const string& _key) {
    int hash_v = Hash(_key);
    if (!table_[hash_v].IsEmpty()) {
        if (table_[hash_v].Front().key == _key) {
            return table_[hash_v].Front().value;
        }
        else if (table_[hash_v].GetSize() > 1) {
            auto check = table_[hash_v].GetHead();
            while (check->value.key != _key) {
                check = check->next;
            }
            return check->value.value;
        }
        else {
            throw "Element by this key is not found";
        }
    }
    else {
        throw "Element by this key is not found";
    }
}

template<typename T>
void HashTable<T>::Add(HashTableNode<T>& _element) {
    int hash_v = Hash(_element.key);
    table_[hash_v].PushBack(_element);
}

template<typename T>
T HashTable<T>::Pop(const string& _key) {
    T temp;
    int hash_v = Hash(_key);
    if (!table_[hash_v].IsEmpty()) {
        int size = table_[hash_v].GetSize();
        if (size == 1) {
            temp = table_[hash_v].PopFront().value;
        }
        else if (size > 1) {
            auto it = table_[hash_v].GetHead();
            while (it->next->value.key != _key) {
                it = it->next;
            }
            auto poper = it->next;
            temp = poper->value.value;
            it->next = poper->next;
            delete poper;
            poper = nullptr;
        }
        else {
            throw "Element by this key is not found";
        }
    }
    else {
        throw "Element by this key is not found";
    }
    return temp;
}

template<typename T>
void HashTable<T>::Values() const {
    std::cout << "Hashtable:\n";
    for (int i = 0; i < size_; i++) {
        std::cout << i << ": \t";
        table_[i].Print(); std::cout << '\n';
    }
}