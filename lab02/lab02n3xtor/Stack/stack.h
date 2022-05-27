#pragma once

struct Node
{
    Node* ptr;
    int value;
    Node(int NodeValue, Node* Nodeptr);
};

class Stack
{
private:
    Node* head = nullptr;
    int size;
    Stack* top;
public:
    Stack();
    Stack(int value);
    ~Stack() {};
    Stack* next = nullptr;
    void push(int value);
    bool isEmpty() const;
    int pop();
    void delTop();
    void print()const;
    int getSize();
    void swap(Stack& stack);
    void emplace(int& value);
    int topValue();
};