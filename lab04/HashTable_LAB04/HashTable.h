#pragma once
#include<iostream>
#include<string>
using std::cout;
using std::cin;
using std::string;

struct Row
{
    string surname, name;
    double mark;
    Row(string a = "", string t = "", double m = 0.);
};

int hash(string key, int hash_length);

class HashTable
{
private:
    int free_size;
    int used_size;
    Row* rows;

public:
    HashTable(int size = 0);
    void add(Row new_elem);
    int find(string find_key);
    bool isEmpty() { return free_size == 0; }
    int sizeOf() { return free_size; }
    void pop(string key);
    void clear();
    void print();
    ~HashTable() { delete[] rows; }
};

std::istream& operator >>(std::istream& is, Row& elem);
std::ostream& operator <<(std::ostream& os, const Row& elem);


