#include "Stack.h"

void Stack::push(double value) 
{
    StackNode* newNode = new StackNode(value);
    newNode->nextNode = Top;
    Top = newNode;
}

void Stack::pop()
{
    if (Top == nullptr)
    {
        std::cout << "\nStack is empty\n";
    }
    else 
    {
        Top = Top->nextNode;
    }
}

bool Stack::isEmpty() const
{
    return Top == nullptr;
}


void Stack::print() const
{
    StackNode* timeVar;
    if (Top == nullptr)
    {
        std::cout << "\nStack is empty\n";
        return;
    }
    else
    {
        timeVar = Top;
        while (timeVar != nullptr)
        {
            std::cout << timeVar->nodeVal << "\n";
            timeVar = timeVar->nextNode;
        }
    }
}

int Stack::size() const
{
    int counter = 0;
    StackNode* timeVar = Top;

    if (timeVar->nextNode == nullptr)
    {
        return 0;
    }
    else
    {
        while (timeVar != nullptr)
        {
            ++counter;
            timeVar = timeVar->nextNode;
        }
    }
    return counter;
}

double Stack::top() const 
{
    if (Top == nullptr) 
    {
        std::cout << "\nStack is empty\n";
        return 0;
    }
    return Top->nodeVal;
}

void Stack::swap(Stack& anotherStack)
{
    StackNode* timeVar = this->Top;
    this->Top = anotherStack.Top;
    anotherStack.Top = timeVar;
}

void Stack::emplace(double& val)
{
    StackNode* newNode = new StackNode(val);
    newNode->nextNode = Top;
    Top = newNode;
}
