#pragma  once
#include "Stack.h"

class SetOfStacks {
private:
    Stack* ptr_;
    int limitOfStackNodes_;
public:
    SetOfStacks();
    SetOfStacks(Stack* ptr, const int stackNodesLimit);
    SetOfStacks(const int value, const int stackNodesLimit);

    void push(const int value);
    void pop();
    void popAt(int index);
    void print() const;
    int getNumber() const;
};