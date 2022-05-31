#pragma once
#include <iostream>
template<typename T>
struct StackNode {
    T value;
    StackNode<T>* next;
    StackNode(T _value, StackNode<T>* _next);
};
template<typename T>
class Stack {
private:
    StackNode<T>* top_;
    void DeleteTop();
public:
    Stack();
    Stack(T value);
    ~Stack();
    bool Empty() const;
    int Size() const;
    T Top() const;
    void Push(T value);
    void Emplace(T& item);
    T Pop();
    void Swap(Stack& other);
    void PrintStack();
};

template<typename T>
StackNode<T>::StackNode(T _value, StackNode* _next) : value(_value), next(_next) {}
template<typename T>
Stack<T>::Stack() {
    top_ = nullptr;
}
template<typename T>
Stack<T>::Stack(T value) {
    top_ = new StackNode<T>(value, nullptr);
}
template<typename T>
Stack<T>::~Stack() {
    while (!Empty()) {
        DeleteTop();
    }
}
template<typename T>
void Stack<T>::DeleteTop() {
    if (Empty()) {
        return;
    }
    StackNode<T>* temp = top_;
    top_ = top_->next;
    delete temp;
}
template<typename T>
bool Stack<T>::Empty() const {
    return top_ == nullptr;
}
template<typename T>
int Stack<T>::Size() const {
    if (Empty()) {
        return 0;
    }
    int size = 0;
    StackNode<T>* temp = top_;
    while (temp != nullptr) {
        temp = temp->next;
        ++size;
    }
    return size;
}
template<typename T>
T Stack<T>::Top() const {
    if (Empty()) {
        throw "Stack is Empty";
    }
    return top_->value;
}
template<typename T>
void Stack<T>::Push(T value) {
    StackNode<T>* temp = new StackNode<T>(value, top_);
    top_ = temp;
}
template<typename T>
void Stack<T>::Emplace(T& item) {
    StackNode<T>* temp = new StackNode<T>(item, top_);
    top_ = temp;
}
template<typename T>
T Stack<T>::Pop() {
    if (Empty()) {
        throw "Stack is Empty";
    }
    T return_value = top_->value;
    DeleteTop();
    return return_value;
}
template<typename T>
void Stack<T>::Swap(Stack& other) {
    StackNode<T>* temp = top_;
    top_ = other.top_;
    other.top_ = temp;
}
template<typename T>
void Stack<T>::PrintStack() {
    if (Empty()) {
        std::cout << "Stack is Empty\n";
    }
    StackNode<T>* temp = top_;
    while (temp != nullptr) {
        std::cout << temp->value << ',';
        temp = temp->next;
    }
}