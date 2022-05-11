#include "Stack.h"

NodeStack::NodeStack(const int nodeValue, NodeStack* nodePtr)
    : value_(nodeValue), ptr_(nodePtr) {
}

Stack::Stack() {
    top_ = nullptr;
}

Stack::Stack(const int value) {
    top_ = new NodeStack(value, nullptr);
}

bool Stack::isEmpty() const {
    return top_ == nullptr;
}

int Stack::getSize() const {
    int counter = 0;
    NodeStack* tempPtr = top_;

    if (top_ == nullptr) {
        return 0;
    }
    else {
        while (tempPtr != nullptr) {
            ++counter;
            tempPtr = tempPtr->ptr_;
        }
    }
    delete tempPtr;
    return counter;
}

int Stack::top() const {
    return top_->value_;
}

void Stack::push(const int value) {
    NodeStack* tempPtr = new NodeStack(value, top_);
    top_ = tempPtr;
}

void Stack::emplace(const int value) {
    NodeStack* tempPtr = new NodeStack(value, top_);
    top_ = tempPtr;
}

void Stack::pop() {
        NodeStack* tempPtr;
        int temp;
        temp = top_->value_;
        tempPtr = top_;
        top_ = top_->ptr_;
        delete tempPtr;
}

void Stack::swap(Stack& stack) {
    NodeStack* buffer = top_;
    this->top_ = stack.top_;
    stack.top_ = buffer;
}

void Stack::print() const {
    if (top_ == nullptr) {
        std::cout << "\nStack is empty!\n";
        return;
    }
    std::cout << "Stack: ";
    NodeStack* tempPtr = top_;
    while (tempPtr != nullptr) {
        std::cout << tempPtr->value_ << ' ';
        tempPtr = tempPtr->ptr_;
    }
    std::cout << "\n";
}
