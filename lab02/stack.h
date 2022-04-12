#pragma once
#include <iostream>

#define SIZE 5//preprocessor - changes one in another

using namespace std;

class Stack {
private:
    int stackArray[SIZE] {};
    int top = -1;
public:
    Stack();
    ~Stack();

    bool isEmpty();
    bool isFull();
    int size();
    int showTop();
    void push(int elem);
    void emplace(int pos, int elem);
    void swap(int pos1, int pos2);
    void pop();
    void printStack();
};
