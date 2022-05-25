#pragma once
#include<iostream>
template <typename T>
struct Node {
    T value;
    Node<T>* link;
    Node(T _value, Node<T>* _link);
    Node(T _value);
};

template<typename T>
Node<T>::Node(T _value, Node<T>* _link) : value(_value), link(_link) {}

template<typename T>
Node<T>::Node(T _value) : value(_value), link(nullptr) {}

template <typename T>
class List {
private:
    Node<T>* first;
    Node<T>* last;
public:
    List();
    List(Node<T>* _first, Node<T>* _last);
    ~List();
    Node<T>* top();
    int getSize();
    void addBack(T data);
    bool isEmpty();
    Node<T>* move(int index);
    Node<T>* pop(int index);
    Node<T>* delFirst();
    void empty();
};
template<typename T>
List<T>::List() : first(nullptr), last(nullptr) {};

template<typename T>
List<T>::List(Node<T>* _first, Node<T>* _last) : first(_first), last(_last) {};

template<typename T>
List<T>::~List()
{
    empty();
};

template <typename T>
Node<T>* List<T>::move(int index)
{
    Node<T>* temp = first;
    for (int i = 0; i < index; ++i)
    {
        temp = temp->link;
    }

    return temp;
}

template<typename T>
void List<T>::addBack(T data)
{
    Node<T>* temp = new Node<T>(data);
    if (first == nullptr)
    {
        first = last = temp;
    }
    last->link = temp;
    last = temp;
    temp = nullptr;
}

template<typename T>
bool List<T>::isEmpty()
{
    return first == nullptr;
}

template<typename T>
Node<T>* List<T>::top()
{
    return first;
}

template<typename T>
int List<T>::getSize()
{
    int count = 0;
    Node<T>* temp = first;
    while (temp != nullptr)
    {
        temp = temp->link;
        ++count;
    }

    return count;
}

template<typename T>
Node<T>* List<T>::pop(int index)
{
    if (first == nullptr)
    {
        throw "List is empty";
    }

    if ((index < 0) || (index >= getSize()))
    {
        throw "Index is invalid";
    }
    if (index == 0)
    {
        Node<T>* temp = first;
        first = first->link;
        return temp;
        delete temp;
    }
    else
    {
        Node<T>* temp = move(index - 1);
        Node<T>* victim = temp->link;
        temp->link = victim->link;
        return victim;
        delete victim;
    }
}

template<typename T>
Node<T>* List<T>::delFirst()
{
    return pop(0);
}

template<typename T>
void List<T>::empty()
{
    while (first != nullptr)
    {
        int i = 0;
        pop(i);
        ++i;
    }
}



