#pragma once
#include <iostream>
using namespace std;

struct Element {
    std::string key;
    int value;

    Element();
    Element(std::string k, int v);
    ~Element();
};

class HashTable {
private:
    static const size_t MAX = 100;
    Element dictionary[MAX];

    int _hash(std::string k);
public:
    HashTable();
    HashTable(std::string k, int v);
    ~HashTable();

    void add(std::string k, int v);
    int get(std::string k);
    void pop(std::string k);
    int elemCount();
    bool isEmpty();

    void values();
};

