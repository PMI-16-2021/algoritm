#pragma once
#include "Stack.h"
#include<iostream>

class SetOfStacks {
private:
    Stack* MassNodes;         //pointer to stack array
    int size;               
    const int amount = 100;  //number of max elements in stack
public:
    SetOfStacks(int size); 
    void push(int value);
    void pop();
    void popAt(int index);
    void print();
};
