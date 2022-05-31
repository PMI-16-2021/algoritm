#include "SetOfStacks.h"

void SetOfStacks::push(double value)
{
    if (ptrToTop != nullptr && ptrToTop->size() < maxNodes) 
    {
        ptrToTop->push(value);
    }
    else
    {
        Stack* newStack = new Stack(value);
        newStack->otherStack = ptrToTop;
        ptrToTop = newStack;
    }
}

void SetOfStacks::pop()
{
    Stack* timeVar = ptrToTop;
    if (timeVar == nullptr)
    {
        std::cout << "\nStack is empty\n";
        return;
    }
    else if (ptrToTop->isEmpty())
    {
        ptrToTop = ptrToTop->otherStack;
    }
    else
    {
        ptrToTop->pop();
    }
}

void SetOfStacks::popAt(int stackNum)
{
    if (stackNum <= 0 || stackNum > size())
    {
        std::cout << "\nSuch a stack does not exist\n";
    }
    else
    {
        Stack* timeVar = ptrToTop;
        for (int i = 0; i < stackNum - 1; ++i)
        {
            timeVar = timeVar->otherStack;
        }
        timeVar->pop();
    }
}

void SetOfStacks::print() const
{
    Stack* timeVar = ptrToTop;
    int amountOfStacks = size();
    if (timeVar == nullptr)
    {
        std::cout << "\nSet of stacks is empty\n";
        return;
    }
    else
    {
        for (int i = 0; i < amountOfStacks; ++i)
        {
            std::cout << "#" << i + 1 << "\n";
            timeVar->print();
            timeVar = timeVar->otherStack;
        }
    }
}

int SetOfStacks::size() const
{
    int counter = 0;
    Stack* timeVar;
    if (ptrToTop == nullptr)
    {
        return 0;
    }
    else
    {
        timeVar = ptrToTop;
        while (timeVar != nullptr)
        {
            ++counter;
            timeVar = timeVar->otherStack;
        }
    }
    return counter;
}

bool SetOfStacks::isSetEmpty() const
{
    return ptrToTop == nullptr;
}

int SetOfStacks::getMaxNodesLimit() const
{
    return maxNodes;
}
