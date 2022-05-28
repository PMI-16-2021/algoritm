#pragma once
#include <iostream>

class MySet {
private:
    char* array_;
    size_t count_;
    size_t capacity_;
public:
    MySet();
    MySet(size_t capacity);
    ~MySet();

    void add(char elem_to_add);
    void remove(char elem_to_remove);
    int len() const;
    bool in(char elem_to_find) const;
    MySet Union(const MySet& other) const;
    MySet intersection(const MySet& other);
    MySet difference(const MySet& other);
    MySet symmetric_difference(MySet& other);
    void print() const;
    char& operator[](size_t index);
};