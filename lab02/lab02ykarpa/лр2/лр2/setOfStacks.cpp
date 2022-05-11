#include "SetOfStacks.h"

SetOfStacks::SetOfStacks()
    : ptr_(nullptr), limitOfStackNodes_(5) {
}

SetOfStacks::SetOfStacks(Stack* ptr, const int stackNodesLimit)
    : limitOfStackNodes_(stackNodesLimit), ptr_(ptr) {
}

SetOfStacks::SetOfStacks(const int value, const int stackNodesLimit)
    : limitOfStackNodes_(stackNodesLimit) {
    ptr_ = new Stack(value);
}

void SetOfStacks::push(int value) {
    if (ptr_ != nullptr && ptr_->getSize() < limitOfStackNodes_) {
        ptr_->push(value);
    }
    else {
        Stack* newStack = new Stack(value);
        newStack->nextStack = ptr_;
        ptr_ = newStack;
    }
}

void SetOfStacks::pop() {
    Stack* tempPtr = ptr_;
    if (tempPtr==nullptr) {
        std::cout << "'nStack is empty\n";
    }
    else if (ptr_->isEmpty()) {
        ptr_ = ptr_->nextStack;
    }
    else {
        ptr_->pop();
    }
}

void SetOfStacks::popAt(int index)
{
    if (index <= 0 || index > getSize()) {
        std::cout << "\nThis stack does not exist\n";
    }
    else {
        Stack* tempPtr = ptr_;
        for (int i = 0; i < index - 1; ++i) {
            tempPtr = tempPtr->nextStack;
        }
        tempPtr->pop();
    }
}


void SetOfStacks::print() const {
    Stack* tempPtr = ptr_;
    int amountOfStacks = getSize();
    if (tempPtr == nullptr) {
        std::cout << "\nSet of stacks is empty\n";
        return;
    }
    else {
        for (int i = 0; i < amountOfStacks; ++i) {
            std::cout << "Stack #" << i + 1 << "\n";
            tempPtr->print();
            tempPtr = tempPtr->nextStack;
        }
    }
}

int SetOfStacks::getSize() const {
    int counter = 0;
    Stack* tempPtr;
    if (ptr_ == nullptr) {
        return 0;
    }
    else {
        tempPtr = ptr_;
        while (tempPtr != nullptr) {
            ++counter;
            tempPtr = tempPtr->nextStack;
        }
    }
    return counter;
}