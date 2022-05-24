#pragma once
#include <iostream>

class Set{
private:
    char *arr{};
    size_t count{};
    size_t size{};
public:
    Set(); //default constructor
    Set(size_t capacity); // constructor with parameters
    ~Set() {delete [] arr;}
    void add(char element); // add elem in set
    void del(char element);//delete elem from set
    size_t len() const;//get count of set
    bool inSet(char element) const; //check if this element is in set
    Set unionSet(Set &anotherSet) const; // return new set, which contains set1+set2
    Set intersection(Set &anotherSet);//return new set, which contains similar elements from two sets
    Set difference(Set &anotherSet);//return new set, which contains different elements from two sets
    Set symmetricDifference(Set &anotherSet);//
    void print() const;
    char &operator[](int i);
};

