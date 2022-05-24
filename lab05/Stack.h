#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node {
    T value;
    Node* next;
    Node(T NodeValue, Node* NodeNext);
};

template <typename T>
Node<T>::Node(T NodeValue, Node<T>* NodeNext) : value(NodeValue), next(NodeNext) {}

template <typename T>
class Stack {
private:
    Node<T>* top;
public:
    Stack<T>();
    Stack<T>(T value);
    ~Stack<T>();

    T stackTop();
    void push(T elem);
    T pop();
    bool isEmpty();
    int size();
    void swap(Stack<T>& stack);
    void emplace(T& elem);
    
    void print();
};

template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
Stack<T>::Stack(T value) {
    top = new Node<T>(value, nullptr);
}

template <typename T>
Stack<T>::~Stack() {
    Node<T>* temp_top = top;
    Node<T>* temp;
    while (temp_top != nullptr) {
        temp = temp_top;
        temp_top = temp_top->next;
        delete temp;
    }
    top = nullptr;
}

template <typename T>
T Stack<T>::stackTop() {
    if (isEmpty()) {
        throw "Stack is empty.";
    }
    else {
        return top->value;
    }
}

template <typename T>
void Stack<T>::push(T elem)
{
    Node<T>* local = new Node<T>(elem, top);
    top = local;
}

template <typename T>
T Stack<T>::pop()
{
    if (isEmpty()) {
        throw "Stack is empty";
    }
    else {
        Node<T>* temp;
        T elem;
        elem = top->value;
        temp = top;
        top = top->next;
        delete temp;
        return elem;
    }
}

template <typename T>
bool Stack<T>::isEmpty() {
    return top == nullptr;
}

template <typename T>
int Stack<T>::size() {
    if (isEmpty()) {
        return 0;
    }
    else {
        Node<T>* temp = top;
        int counter = 0;
        while (temp != nullptr) {
            ++counter;
            temp = temp->next;
        }
        delete temp;
        return counter;
    }
}

template <typename T>
void Stack<T>::swap(Stack<T>& stack) {
    Node<T>* temp = top;
    top = stack.top;
    stack.top = temp;
}

template <typename T>
void Stack<T>::emplace(T& elem) {
    Node<T>* local = new Node<T>(elem, top);
    top = local;
}


template <typename T>
void Stack<T>::print() {
    if (isEmpty()) {
        cout << "Stack is empty";
    }
    else {
        Node* temp = top;
        cout << "Stack: ";
        while (temp != nullptr) {
            cout << temp->value << " ";
            temp = temp->next;
        }
       cout << "\n\n";
    }
}