#pragma once
#include <iostream>
#include "list.h"

using std::string;

template<typename T>
struct TableElem {
    string key;
    T value;
    TableElem();
    TableElem(string _key, T _value);
    TableElem(const TableElem<T>& other);
    friend std::ostream& operator<<(std::ostream& out, const TableElem<T>& _elem){
        return out << _elem.key << ':' << _elem.value;
    }
};

template<typename T>
TableElem<T>::TableElem() : key(""), value(T(0)) {}

template<typename T>
TableElem<T>::TableElem(string _key, T _value) : key(_key), value(_value) {}

template<typename T>
TableElem<T>::TableElem(const TableElem<T>& other) : key(other.key), value(other.value) {}

template<typename T>
class HashTable {
private:
    size_t size_;
    List<TableElem<T>>* table_;  // array of lists

public:
    HashTable();
    explicit HashTable(size_t size);
    ~HashTable();
    size_t _hash(string _key);

    void Add(TableElem<T>& _elem);
    T& Get(const string& _key);
    T Pop(const string& _key);
    void Values() const;

    class NotFound {
    public:
        NotFound(const string& _key) { std::cerr << "Element by key: " << _key << " not found.";}
    };
};

template<typename T>
HashTable<T>::HashTable() : size_(10), table_(new List<TableElem<T>>[size_]) {}

template<typename T>
HashTable<T>::HashTable(size_t size) : size_(size), table_(new List<TableElem<T>>[size_]) {}

template<typename T>
HashTable<T>::~HashTable() {
    delete[] table_;
}

template<typename T>
size_t HashTable<T>::_hash(string _key) {
    size_t ret_val = 0;
    if(_key.length() == 1) {
        ret_val = _key[0] % size_;
    }
    else{
        ret_val = (_key[0]*7 + _key[1]) % size_;
    }
    return ret_val;
}

template<typename T>
T& HashTable<T>::Get(const string& _key) {
    size_t hash_val = _hash(_key);
    if(!table_[hash_val].IsEmpty()) {
        if (table_[hash_val].Front().key == _key) {
            return table_[hash_val].Front().value;
        } else if (table_[hash_val].Size() > 1) {
            auto check = table_[hash_val].Begin();  // auto == ListNode<TableElem<T>>*
            while (check->value.key != _key) { //searching element in list of collided elements
                check = check->ptr_next;
            }
            return check->value.value;
        }
        else {
            throw NotFound(_key);
        }
    }
    else {
        throw NotFound(_key);
    }
}

template<typename T>
void HashTable<T>::Add(TableElem<T> &_elem) {
    size_t hash_val = _hash(_elem.key);
    // if no collision and also in case of collision
    table_[hash_val].PushBack(_elem);
}

template<typename T>
T HashTable<T>::Pop(const string &_key) {
    T ret_val;
    size_t hash_val = _hash(_key);
    if(!table_[hash_val].IsEmpty()) {
        size_t size = table_[hash_val].Size();
        if (size == 1) {
            ret_val = table_[hash_val].PopFront().value;
        } else if (size > 1) {
            auto it = table_[hash_val].Begin();
            while (it->ptr_next->value.key != _key) {
                it = it->ptr_next;
            }
            auto poper = it->ptr_next;
            ret_val = poper->value.value;
            it->ptr_next = poper->ptr_next;
            delete poper;
            poper = nullptr;
        }
        else {
            throw NotFound(_key);
        }
    }
    else {
        throw NotFound(_key);
    }
    return ret_val;
}

template<typename T>
void HashTable<T>::Values() const {
    std::cout << "Hashtable:\n";
    for(int i = 0; i < size_; i++) {
        std::cout << i << ": \t";
        table_[i].Print(); std::cout << '\n';
    }
}






