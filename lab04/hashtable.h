#pragma once
#include <iostream>
#include <string>
#define SIZE 200

struct TableElement {
    double value;
    std::string key;

    TableElement() : value(0), key("") {}
    TableElement(double val, std::string k) : value(val), key(k) {}
    ~TableElement() {};
};

class HashTable {
private:
    TableElement table[SIZE];

    int _hash(std::string k) {
        int index = 0;
        for (int i = 0; i < k.length(); ++i) {
            index += k[i];
        }
        return index % SIZE;
    }
public:
    HashTable() {}
    HashTable(double val, std::string k) { add(val, k); }
    ~HashTable() {}

    bool isEmpty() {
        for (int i = 0; i < SIZE; ++i) {
            if (table[i].key.length() > 0) {
                return false;
            }
        }
        return true;
    }
    
    void add(double val, std::string k) {
        int index = _hash(k);
        table[index].value = val;
        table[index].key = k;
    }

    void pop(std::string k) {
        int index = _hash(k);
        table[index].value = 0.0;
        table[index].key = "";
    }

    double get(std::string k) {
        int index = _hash(k);
        return table[index].value;
    }

    int elemCount() {
        int count = 0;
        for (int i = 0; i < SIZE; ++i) {
            if (table[i].key.length() > 0) {
                ++count;
            }
        }
        return count;
    }

    void values() {
        std::cout << "HashTable: \n";
        for (int i = 0; i < SIZE; ++i) {
            if (table[i].key.length() > 0) {
                std::cout << "Key [" << table[i].key << "], ";
                std::cout << "value: " << table[i].value << '\n';
            }
        }
        std::cout << '\n';
    }
};