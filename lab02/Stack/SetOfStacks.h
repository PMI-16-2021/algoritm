#pragma once
#include "Stack.h"

struct SetOfStacks
{
    Stack* ptrToTop;
    int maxNodes;

    SetOfStacks() : ptrToTop(nullptr), maxNodes(5) 
    {
    }
    SetOfStacks(Stack* stack, int stackNodesLimit) : maxNodes(stackNodesLimit)
    {
        ptrToTop = stack;
    }
    SetOfStacks(int value, int stackNodesLimit) : maxNodes(stackNodesLimit) 
    {
        ptrToTop = new Stack(value);
    }
  
    void push(double value);
    void pop();
    void popAt(int stackNum);
    void print() const;
    int size() const;
    bool isSetEmpty() const;
    int getMaxNodesLimit() const;
};


