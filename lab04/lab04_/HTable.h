#pragma once
#include <iostream>
#include <string>
#include "list.h"
using namespace std;
//row on string
struct Row {
    string key;
    string  value;
    Row() : key(""), value() {}
    Row(string _key, string _value) : key(_key), value(_value) {}
};

class HTable {
private:
    Row* table;
    size_t capacity; // count
    size_t size; // max size
    int hash(string key);
public:
    HTable();
    HTable(size_t _size);
    ~HTable();
    void add(string key, string element);
    bool find(string key);
    void pop(string key);
    void values();//print
    bool isEmpty();
    int getSize();

};

