#include "Stack.h"


bool Stack::isEmpty() const {
    return pTop == nullptr;
}

void Stack::push(double value) {
    StackNode *newStackNode = new StackNode(value);
    newStackNode->nextNode = pTop;
    pTop = newStackNode;
}

void Stack::print() const {
    StackNode *temp;
    if (pTop == nullptr) {
        std::cout << "\nStack Underflow\n";
        return;
    } else {
        temp = pTop;
        while (temp != nullptr) {
            std::cout << temp->nodeValue << "\n";
            temp = temp->nextNode;
        }
    }
}


void Stack::pop() {
    if (pTop == nullptr) {
        std::cout << "\nStack Underflow\n";
    } else {
        pTop = pTop->nextNode;
    }
}

void Stack::empty() {
    if (pTop == nullptr) {
        std::cout << "\nStack Underflow\n";
    } else {
        while (pTop != nullptr) {
            pTop = pTop->nextNode;
        }
    }
}

int Stack::size() const {
    int counter = 0;
    StackNode *temp = pTop;

    if (temp->nextNode == nullptr) {
        return 0;
    } else {
        while (temp != nullptr) {
            ++counter;
            temp = temp->nextNode;
        }
    }
    return counter;
}

double Stack::top() const {
    if (pTop == nullptr) {
        std::cout << "\nStack Underflow\n";
        return 0;
    }
    return pTop->nodeValue;
}

void Stack::swap(Stack &otherStack) {
    StackNode *temporary = this->pTop;
    this->pTop = otherStack.pTop;
    otherStack.pTop = temporary;
}

void Stack::emplace(double &element) {
    StackNode *newStackNode = new StackNode(element);
    newStackNode->nextNode = pTop;
    pTop = newStackNode;
}

