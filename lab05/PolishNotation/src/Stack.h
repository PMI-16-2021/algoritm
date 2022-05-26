#pragma once
#include <iostream>

template<typename T>
struct NodeStack {
    T value;
    NodeStack *link;

    NodeStack(T _value, NodeStack *_link);
};

template<typename T>
NodeStack<T>::NodeStack(T _value, NodeStack *_link) : value(_value), link(_link) {
}

template<typename T>
class Stack {
private:
    NodeStack<T> *mTop;
public:
    //empty constructor
    Stack<T>();

    //constructor with parameter
    Stack<T>(T item);

    //destructor
    ~Stack<T>();

    //method that checks whether stack is empty
    bool isEmpty();

    //method that swaps element of two stacks
    void swap(Stack<T> &other_stack);

    //put into array element by reference
    void emplace(T &item);

    //method that clear stacks
    void empty();

    //method that prints stack into console
    void print();

    //method that add elements to stack
    void push(T item);

    //method that returns size pf stack
    int size();

    //method that return top element of stack
    T top();

    //method that deletes last element of stack
    T pop();
};

template<typename T>
Stack<T>::Stack() : mTop(nullptr) {
}

template<typename T>
Stack<T>::Stack(T item) {
    mTop = new NodeStack<T>(item, nullptr);
}

template<typename T>
Stack<T>::~Stack() {
    empty();
}

template<typename T>
bool Stack<T>::isEmpty() {
    return mTop == nullptr;
}

template<typename T>
void Stack<T>::push(T item) {
    NodeStack<T> *element = new NodeStack<T>(item, mTop);
    mTop = element;
}


template<typename T>
void Stack<T>::swap(Stack<T> &other_stack) {
    NodeStack<T> *temp = mTop;
    mTop = other_stack.mTop;
    other_stack.mTop = temp;
}

template<typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw "Stack is empty";
    } else {
        NodeStack<T> *temp;
        T item;
        item = mTop->value;
        temp = mTop;
        mTop = mTop->link;
        delete temp;
        return item;
    }
}

template<typename T>
int Stack<T>::size() {
    if (isEmpty()) {
        return 0;
    } else {
        NodeStack<T> *temp = mTop;
        int size = 0;
        while (temp != nullptr) {
            ++size;
            temp = temp->link;
        }
        delete temp;
        return size;
    }
}

template<typename T>
void Stack<T>::empty() {
    NodeStack<T> *temp_top = mTop;
    NodeStack<T> *temp;
    while (temp_top != nullptr) {
        temp = temp_top;
        temp_top = temp_top->link;
        delete temp;
    }
    mTop = nullptr;
}

template<typename T>
T Stack<T>::top() {
    if (isEmpty()) {
        throw "Stack underflow.";
    } else {
        return mTop->value;
    }
}

template<typename T>
void Stack<T>::emplace(T &item) {
    NodeStack<T> *element = new NodeStack<T>(item, mTop);
    mTop = element;
}

template<typename T>
void Stack<T>::print() {
    if (isEmpty()) {
        std::cout << "Stack underflow.";
    } else {
        NodeStack<T> *temp = mTop;
        while (temp != nullptr) {
            std::cout << temp->value << "; ";
            temp = temp->link;
        }
    }
}