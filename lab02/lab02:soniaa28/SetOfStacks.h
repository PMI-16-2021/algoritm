#pragma  once
#include "Stack.h"

class SetOfStacks{
private:
    Stack* pointer; // array of Stacks
    int maxSize; // max size of stack , for add another stack
    int sizeOfSet; // number od all stacks in set

public:
    SetOfStacks(); // default constructor
    SetOfStacks(Stack* ptr, int max); // constructor with parameters
    SetOfStacks(int value, int max); // constructor with parameters

    void push(int value); // add a  value in stack
    void pop(); // delete value from head
    void popAt(int index); // delete value by index of Stack
    void printSet(); // print all stacks
    int getSize() const; // obtain size of SetOfStacks

};
