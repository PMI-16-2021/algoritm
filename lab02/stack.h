#pragma once
#include <iostream>

template <typename T>
struct Node
{
    T value;
    Node* next;
    Node(T new_value, Node* ptr_next);
};

template <typename T>
Node<T>::Node(T new_value, Node* ptr_next)
{
    value = new_value;
    next = ptr_next;
}

template <typename T>
class Stack
{
private:
    Node<T>* top;
public:
    Stack() { top = nullptr; }
    Stack(T new_value);
    ~Stack() { empty(); }

    void empty();
    void push(T value);
    T pop();
    int size() const;
    bool isEmpty() const;
    void emplace(T& value);
    T Top() const;
    void swap(Stack<T>& other);
    void print() const;
};

template <typename T>
Stack<T>::Stack(T new_value)
{
    top = new Node<T>(new_value, nullptr);
}

template <typename T>
void Stack<T>::empty()
{
    Node<T>* ptr1;
    Node<T>* ptr2;
    ptr1 = top;
    while (ptr1 != nullptr)
    {
        ptr2 = ptr1;
        ptr1 = ptr1->next;
        delete ptr2;
    }
    top = nullptr;
}

template <typename T>
void Stack<T>::push(T value)
{
    Node<T>* temp = new Node<T>(value, top);
    top = temp;
}

template <typename T>
T Stack<T>::pop()
{
    if (top == nullptr) return 0;
    else
    {
        Node<T>* ptr;
        T temp_value;
        temp_value = top->value;
        ptr = top;
        top = top->next;
        delete ptr;
        return temp_value;
    }
}

template <typename T>
int Stack<T>::size() const
{
    if (top == nullptr) return 0;
    else
    {
        Node<T>* ptr = top;
        int counter = 0;
        while (ptr != nullptr)
        {
            ++counter;
            ptr = ptr->next;
        }
        return counter;
    }
}

template <typename T>
bool Stack<T>::isEmpty() const
{
    return top == nullptr;
}

template <typename T>
void Stack<T>::emplace(T& value)
{
    Node<T>* temp = new Node<T>(value, top);
    top = temp;
}

template <typename T>
T Stack<T>::Top() const
{
    if (top == nullptr) return 0;
    return this->value;
}

template <typename T>
void Stack<T>::swap(Stack<T>& other)
{
    Node<T>* temp;
    temp = this->top;
    this->top = other.Top;
    other.top = temp;
}

template <typename T>
void Stack<T>::print() const
{
    if (isEmpty()) {
        std::cout << "This stack is empty\n";
    }
    Node<T>* temp = top;
    while (temp != nullptr)
    {
        std::cout << temp->value << ' ';
        temp = temp->next;
    }
}