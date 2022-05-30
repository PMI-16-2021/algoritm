#pragma once
#include "Stack.h"
#include<iostream>

class SetOfStacks {
private:
    Stack* MassNodes;         
    int size;
    const int amount = 100;  
public:
    SetOfStacks(int size);
    void push(int value);
    void pop();
    void popAt(int index);
    void print();
};
