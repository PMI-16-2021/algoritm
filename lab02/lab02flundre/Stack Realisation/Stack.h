#pragma once
#include <iostream>

class SizeException
{
public:
    void print() const { std::cout << "ERROR: Wrong size" << '\n'; };
};

class IndexException
{
public:
    void print() const { std::cout << "ERROR: Wrong index input, element does not exist" << '\n'; };
};

class Stack {
public:
    int index;
    int memory[100];
public:
    Stack() : index(0) {};
    ~Stack() {};
    bool empty();
    int size();
    int top();
    virtual void push(int x);
    void emplace(int x);
    virtual int pop();
    void swap(Stack& second_stack);
    virtual void print();
};

