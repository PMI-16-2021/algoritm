#pragma once
#include <iostream>
using namespace std;
struct Node {
    int value;
    Node* next;
    Node(int NodeValue, Node* NodeNext);
};

class Stack {
private:
    Node* top;
public:
    Stack();
    Stack(int value);
    ~Stack();

    bool isEmpty();
    int size();
    int showTop();
    void push(int elem);
    void emplace(int& elem);
    void swap(Stack& stack);
    void pop();
    void printStack();
};