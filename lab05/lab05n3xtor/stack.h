#pragma once
#include <iostream>
using namespace std;

template<typename T>
struct Node
{
    T item_value;
    Node<T>* next_item_link;
    Node(T value, Node<T>* link = nullptr);
};

template<typename T>
class Stack
{
private:
    size_t size_;
    Node<T>* item_;
    void DeleteTop();
public:
    Stack();
    Stack(T item_value);
    ~Stack(); 

    Node<T>* GetTopPtr() const { return item_; }
    bool IsEmpty() const;                 
    int GetSize() const { return size_; }     
    void CutSize() { --size_; }           
    void Push(T value_to_push);       
    T Top() const;                   
    void Emplace(T& to_emplace);       
    T Pop();                            
    void Swap(Stack& other);              
    void ClearStack();                      
    void PrintStack();                    
 class EmptyStack
    {
    public:
        EmptyStack(const char* message) { cout << message << endl; }
    };
};


template<typename T>
Node<T>::Node(T value, Node<T>* link) : item_value(value), next_item_link(link)
{
}

template<typename T>
Stack<T>::Stack()
{
    item_ = nullptr;
    size_ = 0;
}

template<typename T>
Stack<T>::Stack(T item_value)
{
    item_ = new Node<T>(item_value, nullptr);
    ++size_;
}

template<typename T>
Stack<T>::~Stack()
{
    ClearStack();
}

template<typename T>
void Stack<T>::PrintStack()
{
    if (IsEmpty())
    {
        throw EmptyStack("Empty stack.");
    }
    Node<T>* helper = item_;
    while (helper != nullptr)
    {
        cout << helper->item_value << '\n';
        helper = helper->next_item_link;
    }
}

template<typename T>
bool Stack<T>::IsEmpty() const
{
    return (item_ == nullptr);
}

template<typename T>
void Stack<T>::Push(T value_to_push)
{ 
    Node<T>* helper = new Node<T>(value_to_push, item_);
    item_ = helper;           
    ++size_;
}

template<typename T>
T Stack<T>::Top() const
{
    if (IsEmpty())
    {
        throw EmptyStack("Empty stack.");
    }
    return item_->item_value;
}

template<typename T>
void Stack<T>::Emplace(T& to_emplace)
{ 
    Node<T>* to_emplace_item = new Node<T>(to_emplace, item_);
    item_ = to_emplace_item;
    ++size_;
}

template<typename T>
T Stack<T>::Pop()
{
    if (IsEmpty())
    {
        throw EmptyStack("Empty stack.");
    }
    T return_value = item_->item_value;
    DeleteTop();
    return return_value;
}

template<typename T>
void Stack<T>::Swap(Stack<T>& other)
{
    Node<T>* helper = item_;
    item_ = other.item_;
    other.item_ = helper;
}

template<typename T>
void Stack<T>::DeleteTop()
{
    if (size_ == 1)
    { 
        delete item_;
        --size_;
        item_ = nullptr;
    }
    else
    {
        Node<T>* helper = item_;
        item_ = item_->next_item_link;
        delete helper;
        --size_;
    }
}

template<typename T>
void Stack<T>::ClearStack()
{
    while (!IsEmpty())
    {
        DeleteTop();
    }
}