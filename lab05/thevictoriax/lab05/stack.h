#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct NodeStack 
{
    T value;
    NodeStack* link;
    NodeStack(T _value, NodeStack* _link);
};

template<typename T>
NodeStack<T>::NodeStack(T _value, NodeStack* _link) : value(_value), link(_link) 
{
}

template<typename T>
class Stack 
{
private:
    NodeStack<T>* top;
public:
    Stack<T>();
    Stack<T>(T item);
    ~Stack<T>();
    bool isEmpty();
    void empty();
    void print();
    void push(T item);
    T peek();
    T pop();
};

template<typename T>
Stack<T>::Stack() : top(nullptr)
{
}

template<typename T>
Stack<T>::Stack(T item) 
{
    top = new NodeStack<T>(item, nullptr);
}

template<typename T>
Stack<T>::~Stack() 
{
    empty();
}

template<typename T>
bool Stack<T>::isEmpty() 
{
    return top == nullptr;
}

template<typename T>
void Stack<T>::push(T item) 
{
    NodeStack<T>* element = new NodeStack<T>(item, top);
    top = element;
}

template<typename T>
T Stack<T>::pop() 
{
    if (isEmpty()) 
    {
        throw "Stack is empty";
    }
    else 
    {
        NodeStack<T>* temp;
        T item;
        item = top->value;
        temp = top;
        top = top->link;
        delete temp;
        return item;
    }
}

template<typename T>
void Stack<T>::empty() 
{
    NodeStack<T>* temp_top = top;
    NodeStack<T>* temp;
    while (temp_top != nullptr) 
    {
        temp = temp_top;
        temp_top = temp_top->link;
        delete temp;
    }
    top = nullptr;
}

template<typename T>
T Stack<T>::peek() 
{
    if (isEmpty()) 
    {
        throw "ERROR";
    }
    else 
    {
        return top->value;
    }
}

template<typename T>
void Stack<T>::print() 
{
    if (isEmpty()) 
    {
        cout << "ERROR";
    }
    else 
    {
        NodeStack<T>* temp = top;
        while (temp != nullptr) 
        {
            cout << temp->value << "; ";
            temp = temp->link;
        }
    }
}