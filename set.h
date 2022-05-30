#pragma once
#include <iostream>

class MySet
{
private:
    char* arr;
    int counter;
    int size;

public:
    MySet();
    MySet(int newSize);
    ~MySet();

    void add(char element);
    bool in(char element) const;
    void remove(char element);
    int len() const;
    MySet unionSet(MySet& other);
    MySet intersection(MySet& other);
    MySet difference(MySet& other);
    MySet symmetric_difference(MySet& other);
    void print() const;
};