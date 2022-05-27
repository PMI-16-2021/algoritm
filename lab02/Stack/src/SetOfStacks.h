//
// Created by Ostap Kilbasovych on 30.03.2022.
//
#pragma once

#include "Stack.h"

struct SetOfStacks {
    Stack *pointerToTopStack;
    //maximal possible amount of Stack Nodes (Elements in Stack) in one Stack;
    int limitOfStackNodes;

    //default constructor with empty parameters
    SetOfStacks() : pointerToTopStack(nullptr), limitOfStackNodes(7) {
    }

    //constructor that takes pointer to stack and maximal amount of stacks in set of stacks
    SetOfStacks(Stack *stack, int stackNodesLimit) : limitOfStackNodes(stackNodesLimit) {
        pointerToTopStack = stack;
    }

    //constructor that takes first value of top stack and maximal amount of stacks in set of stacks
    SetOfStacks(int value, int stackNodesLimit) : limitOfStackNodes(stackNodesLimit) {
        pointerToTopStack = new Stack(value);
    }

    //method that adds element to the top stack
    void push(double value);

    //method that deletes element of the top stack
    void pop();

    //method that deletes element of stack at some position
    void popAt(int numberOfStack);

    //method that prints set of stacks
    void print() const;

    //method that returns amount of stacks in size of stacks
    int size() const;
};


