#pragma  once
#include "Stack.h"

class SetOfStacks {
private:
    Stack* ptr_; // array of Stacks
    //int maxSize; // max size of stack , for add another stack
    //int sizeOfSet; // number od all stacks in set
    int limitOfStackNodes_;
public:
    SetOfStacks();
    SetOfStacks(Stack* ptr, const int stackNodesLimit);
    SetOfStacks(const int value, const int stackNodesLimit);

    void push(const int value);
    void pop();
    void popAt(int index);
    void print() const;
    int getSize() const;

};

/*#pragma once
#include <vector>
#include "Stack.h"

class SetOfStacks{
private:
    std::vector<Stack*> arr;
    int max;
    int size;

public:
    SetOfStacks(int);
    ~SetOfStacks();

    void push(int);
    void pop();
    void popAt(int);
    void printSetOfStacks();
};*/