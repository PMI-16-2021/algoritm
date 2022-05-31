#pragma once
#include <iostream>

struct StackNode
{
    double nodeVal;
    StackNode* nextNode;

    StackNode() : nodeVal(0), nextNode(nullptr)
    {}
    StackNode(double value) : nodeVal(value), nextNode(nullptr)
    {}
};

struct Stack
{
    StackNode* Top = nullptr;
    Stack* otherStack = nullptr;

    Stack() : Top(nullptr) 
    {
        otherStack == nullptr;
    }
    Stack(int head) : Top(new StackNode(head)) 
    {
        otherStack == nullptr;
    }

    void push(double value);
    void pop();
    bool isEmpty() const;
    void print() const;
    int size() const;
    double top() const;
    void swap(Stack& anotherStack);
    void emplace(double& val);
};
