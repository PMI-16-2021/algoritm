#pragma once
#include <iostream>

template <typename T>
struct Node {
    T data;
    Node* next;
    Node(T _data, Node* link);
};

template<typename T>
Node<T>::Node(T _data, Node* link) : data(_data), next(link) {} //constructor

template<typename T>
class Stack {
private:
    Node<T>* top;//pointer to top
public:
    Stack<T>();
    Stack<T>(T item);
    ~Stack<T>();
    bool isEmpty();
    void push(T item);
    T pop();
    T getTop();
    void clear();

};

template<typename T>
Stack<T>::Stack() : top(nullptr) {}

template<typename T>
Stack<T>::Stack(T item)
{
    top = new Node<T>(item, nullptr);
}

template<typename T>
Stack<T>::~Stack()
{
    clear();
}

template<typename T>
bool Stack<T>::isEmpty()
{
    return top == nullptr;
}

template<typename T>
void Stack<T>::push(T item)
{
    Node<T>* element = new Node<T>(item, top);
    top = element;
}

template<typename T>
T Stack<T>::pop()
{
    if (isEmpty())
    {
        throw "Stack is empty";
    }
    else {
        Node<T>* temp;
        T item;
        item = top->data;
        temp = top;
        top = top->next;
        delete temp;
        return item;
    }
}

template<typename T>
T Stack<T>::getTop()
{
    if (isEmpty())
    {
        throw "Stack is empty.";
    }
    else
    {
        return top->data;
    }
}

template<typename T>
void Stack<T>::clear()
{
    Node<T>* temp_top = top;
    Node<T>* temp;
    while (temp_top != nullptr)
    {
        temp = temp_top;
        temp_top = temp_top->next;
        delete temp;
    }
    top = nullptr;
}



