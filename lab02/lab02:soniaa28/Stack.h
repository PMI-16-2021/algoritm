#pragma once
#include <iostream>
using namespace std;
struct Node{
    Node* ptr; //  pointer to next Node
    int value; // our value
    Node(int NodeValue, Node* Nodeptr); // constructor for Node
};

class Stack{
private:
    Node* head= nullptr; // pointer to head
    int size;
    Stack* top;
public:
    Stack(); // default constructor
    Stack(int value);
    ~Stack(){}; // destructor
    Stack * next = nullptr; // pointer to next Stack
    int push(int value); // add a value to Stack
    bool isEmpty() const; // check if Stack  is empty or not
    int pop(); // delete a node from Stack
    void delTop(); // delete HEAD of Stack
    void print()const; // print Stack
    int getSize(); // get size of Stack
    void swap(Stack& stack); // swap Stacks by values
    void emplace(int &value); // add Node to Stack
    int topValue(); // obtain a value od HEAD

};