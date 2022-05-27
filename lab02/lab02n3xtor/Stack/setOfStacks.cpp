#include <iostream>
#include "setOfStacks.h"
using namespace std;

SetOfStacks::SetOfStacks(Stack* ptr, int max) : maxSize(max)
{
    pointer = ptr;
}

SetOfStacks::SetOfStacks() : maxSize(0)
{
    pointer = nullptr;
}

SetOfStacks::SetOfStacks(int value, int max) : maxSize(max)
{
    pointer = new Stack(value);
}

void SetOfStacks::push(int value)
{
    if (pointer != nullptr && pointer->getSize() < maxSize)
    {
        pointer->push(value);
    }
    else {
        Stack* newStack = new Stack(value);
        newStack->next = pointer;
        pointer = newStack;
    }
    ++sizeOfSet;
}

void SetOfStacks::pop()
{
    Stack* temp = pointer;
    if (temp->isEmpty())
    {
        throw  "Stack is empty";
    }
    else if (pointer->isEmpty())
    {
        pointer = pointer->next;
    }
    else
    {
        pointer->pop();
    }
}

void SetOfStacks::popAt(int index)
{
    if (index <= 0 || index > getSize())
    {
        throw "\nStack is absent\n";
    }
    else {
        Stack* temp = pointer;
        for (int i = 0; i < index - 1; ++i)
        {
            temp = temp->next;
        }
        temp->pop();
    }
}

void SetOfStacks::printSet()
{
    int sizeSet = getSize();
    Stack* temp = pointer;
    if (temp == nullptr)
    {
        throw "\nSet of stacks is empty\n";
    }
    else
    {
        for (size_t i = 0; i < sizeSet; ++i)
        {
            cout << "\nStack - " << i + 1 << ": " << endl;
            temp->print();
            temp = temp->next;
        }
    }
}
int SetOfStacks::getSize() const
{
    int size = 0;
    Stack* temp;
    if (pointer == nullptr)
    {
        return 0;
    }
    else
    {
        temp = pointer;
        while (temp != nullptr)
        {
            ++size;
            temp = temp->next;
        }
    }
    return size;
}