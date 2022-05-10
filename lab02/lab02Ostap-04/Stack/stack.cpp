#include <iostream>
#include "stack.h"
StackNode::StackNode(int _value, StackNode* _next) : value(_value), next(_next) {}

Stack::Stack() {
    top_ = nullptr;
}
Stack::Stack(int value) {
    top_ = new StackNode(value, nullptr);
}
Stack::~Stack() {
    while (!Empty()) {
        DeleteTop();
    }
}

void Stack::DeleteTop() {
    if (Empty()) {
        return;
    }
    StackNode* temp = top_;
    top_ = top_->next;
    delete temp;
}

bool Stack::Empty() const {
    return top_ == nullptr;
}

int Stack::Size() const {
    if (Empty()) {
        return 0;
    }
    int size = 0;
    StackNode* temp = top_;
    while (temp != nullptr) {
        temp = temp->next;
        ++size;
    }
    return size;
}

int Stack::Top() const {
    if (Empty()) {
        throw EmptyStackExeption("Stack is Empty");
    }
    return top_->value;
}

void Stack::Push(int value) {
    StackNode* temp = new StackNode(value, top_);
    top_ = temp;
}

void Stack::Emplace(int& item) {
    StackNode* temp = new StackNode(item, top_);
    top_ = temp;
}

void Stack::Pop() {
    if (Empty()) {
        throw EmptyStackExeption("Stack is Empty");
    }
    StackNode* temp = top_;
    top_ = top_->next;
    delete temp;
}

void Stack::Swap(Stack& other) {
    StackNode* temp = top_;
    top_ = other.top_;
    other.top_ = temp;
}

void Stack::PrintStack() {
    if (Empty()) {
        std::cout << "Stack is Empty\n";
    }
    StackNode* temp = top_;
    while (temp != nullptr) {
        std::cout << temp->value << ',';
        temp = temp->next;
    }
}

EmptyStackExeption::EmptyStackExeption(const char* msg) {
    std::cerr << msg << '\n';
}