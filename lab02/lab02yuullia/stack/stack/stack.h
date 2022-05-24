#pragma once
#include <iostream>
#define MAX 5

class Stack {
private:
    int stack_top;
    int arr[MAX];
public:
    Stack();
    ~Stack();

    bool isEmpty() const;
    bool isFull();
    int size();
    void push(int value);
    void pop();
    int top();
    void emplace(const int& item);
    void swap(int i, int j);

    void printStack();
};
