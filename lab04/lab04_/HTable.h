#pragma once
#include<iostream>
#include<string>
using namespace std;
//struct row = node
struct Row
{
    string key; // key
    string Workplace; // value
    Row() : key(" "), Workplace(" ") {} // default constructor
    Row(string key, string workplace); // constructor with parameters
    bool IsEmpty();// method check if row is Empty
    void OutPut();//method print rows
};

int HashIndex(string key, int hash_size); // hashing func
class Hash_Table
{
private:
    int capacity;// max size
    int count; // used side
    const int size = 10;
    Row* Table; // pointer
public:
    Hash_Table(int size); // constructor
    ~Hash_Table();//destructor
    int getSize() { return count; } // get used size
    int getCapacity(){return capacity;}//get max size
    void add(Row new_element); // add a row
    bool find(string key); // find a row by key
    void pop(string key);// pop a row by key
    void values(); // print table

};

