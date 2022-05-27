#pragma  once
#include "stack.h"

class SetOfStacks
{
private:
    Stack* pointer;
    int maxSize;
    int sizeOfSet;
public:
    SetOfStacks();
    SetOfStacks(Stack* ptr, int max);
    SetOfStacks(int value, int max);

    void push(int value);
    void pop();
    void popAt(int index);
    void printSet();
    int getSize() const;
};