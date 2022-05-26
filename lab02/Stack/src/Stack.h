#pragma once

#include <iostream>


//structure of Stack Node
//it contains node value and pointer to next node
struct StackNode {
    double nodeValue;
    StackNode *nextNode;

    //empty constructor
    StackNode() : nodeValue(0), nextNode(nullptr) {
    }

    //constructor with parameters
    StackNode(double value) : nodeValue(value), nextNode(nullptr) {
    }
};

//structure of Stack
struct Stack {
    StackNode *pTop = nullptr;
    Stack *nextStack = nullptr;

    //default empty constructor
    Stack() : pTop(nullptr) {
        this->nextStack = nullptr;
    }

    //constructor with parameters
    Stack(int headValue) : pTop(new StackNode(headValue)) {
        this->nextStack = nullptr;
    }

    //method that adds element to stack
    void push(double value);

    //method that deletes element from stack
    void pop();

    //checks whether stack is empty
    bool isEmpty() const;

    //method that cleans stack and makes it empty
    void empty();

    //method that prints all elements of stack
    void print() const;

    //method that returns amount of elements in stack
    int size() const;

    //method that returns top (last added) element of stack
    double top() const;

    //method that swap stacks between each other
    void swap(Stack &otherStack);

    //method that constructs new element and insert it
    void emplace(double &element);
};
