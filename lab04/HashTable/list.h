#pragma once
#include <iostream>
#include<fstream>
template<typename T>
struct Node {
    T value;
    Node<T>* next;
    Node() : value(T(0)), next(nullptr) {}
    Node(T _value, Node<T>* _next = nullptr) : value(_value), next(_next) {}
};

template<typename T>
class List {
private:
    Node<T>* head_;
    Node<T>* tail_;
public:
    List() : head_(nullptr), tail_(nullptr) {}
    List(Node<T>* head, Node<T>* tail) : head_(head), tail_(tail) {}
    ~List();
    Node<T>* GetHead() const { return head_; }
    Node<T>* GetTail() const { return tail_; }
    int GetSize() const;
    bool IsEmpty() const;
    void PushFront(T value);
    void PushBack(T value);
    void Insert(int position, const T& value);
    T PopFront();
    void Clear();
    void Print() const;
    T& Front() const;
};
template<typename T>
List<T>::~List() {
    Clear();
}
template<typename T>
int List<T>::GetSize() const {
    int counter = 0;
    Node<T>* temp = head_;
    while (temp != nullptr) {
        counter++;
        temp = temp->next;
    }
    return counter;
}
template<typename T>
bool List<T>::IsEmpty() const {
    return head_ == nullptr && tail_ == nullptr;
}
template<typename T>
void List<T>::PushFront(T value) {
    Node<T>* temp = new Node<T>(value, head_);
    if (IsEmpty()) {
        tail_ = temp;
    }
    head_ = temp;
    temp = nullptr;
}
template<typename T>
void List<T>::PushBack(T value) {
    Node<T>* temp = new Node<T>(value, nullptr);
    if (IsEmpty()) {
        tail_ = temp;
        head_ = tail_;
        temp = nullptr;
        return;
    }
    tail_->next = temp;
    tail_ = tail_->next;
    temp = nullptr;
}
template<typename T>
void List<T>::Insert(int index, const T& value) {
    if (index < 0) {
        throw "Wrong index";
    }
    if (index > GetSize() - 1) {
        PushBack(value);
        return;
    }
    if (index == 0 && !IsEmpty()) {
        PushFront(value);
        return;
    }
    else if (IsEmpty()) {
        PushBack(value);
        return;
    }
    Node<T>* ptr = new Node<T>(value);
    Node<T>* temp = head_;
    while (index > 1 && temp != tail_) {
        temp = temp->next;
        --index;
    }
    Node<T>* linker = temp;
    temp = temp->next;
    linker->next = ptr;
    ptr->next = temp;
    linker = nullptr;
    temp = nullptr;
    ptr = nullptr;
}
template<typename T>
T List<T>::PopFront() {
    Node<T>* temp = head_->next;
    T to_return = head_->value;
    if (GetSize() == 1) {
        tail_ = temp;
    }
    delete head_;
    head_ = temp;
    return to_return;
}
template<typename T>
void List<T>::Clear() {
    while (head_ != nullptr) {
        if (head_ == tail_) {
            tail_ = nullptr;
        }
        Node<T>* temp = head_;
        head_ = head_->next;
        delete temp;
    }
}
template<typename T>
void List<T>::Print() const {
    Node<T>* temp = head_;
    std::cout << "\nList:\n";
    while (temp != nullptr) {
        std::cout << temp->value << '\t';
        temp = temp->next;
    }
}
template<typename T>
T& List<T>::Front() const {
    return head_->value;
}