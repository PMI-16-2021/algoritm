#include<iostream>
#include "Stack.h"
using namespace std;

void Stack::push(int value) {
    StackNode* nextNode = new StackNode();
    nextNode->value = value;
    nextNode->next = sTop;
    sTop = nextNode;
}

void Stack::pop() {
    if (sTop == nullptr) {
        cout << "Stack Underflow\n";
    }
    else {
        StackNode* Node = sTop;  
        sTop = sTop->next;       
        delete Node;             
    }
}

bool Stack::empty() {
    if (sTop == nullptr) {
        return true;
    }
    else {
        return false;
    }
}

int Stack::size() {
    int counter = 0;
    if (sTop == nullptr) {
        return 0;
    }
    else {
        StackNode* Node = sTop;
        while (Node != nullptr)
        {
            ++counter;
            Node = Node->next;
        }
    }
    return counter;
}

int Stack::top() {
    return sTop->value;
}

void Stack::swap(Stack& S) {
    StackNode* temp = this->sTop;
    this->sTop = S.sTop;
    S.sTop = temp;
}

void Stack::emplace(int value) {
    StackNode* nextNode, * nextNode_2;
    nextNode = sTop;
    while (nextNode != nullptr) {
        nextNode = nextNode->next;
    }
    nextNode_2 = new StackNode();
    nextNode_2->value = value;
    nextNode_2->next = sTop;
    this->sTop = nextNode_2;
}

void Stack::print() {
    if (empty())
        return;
    else
    {
        StackNode* nextNode;
        nextNode = sTop;
        while (nextNode != nullptr)
        {
            cout << nextNode->value << "\n";
            nextNode = nextNode->next;
        }
    }
}
