#pragma once
#include <iostream>

struct NodeStack {
    NodeStack* ptr_;
    int value_;
    NodeStack(const int nodeValue, NodeStack* nodeptr);
};

class Stack {
private:
    NodeStack* top_;

public:
    Stack* nextStack = nullptr;

    Stack();
    Stack(const int value);

    bool isEmpty() const;
    int getSize() const;
    int top() const;
    void push(const int value);
    void emplace(const int value);
    void pop();
    void swap(Stack& stack);
    void print() const;
};
