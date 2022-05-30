#pragma once
#include <iostream>

template<typename T>
struct ListNode {
    T value;
    ListNode<T>* ptr_next;
    ListNode() : value(T(0)), ptr_next(nullptr) {}
    explicit ListNode(T _val, ListNode<T>* ptr = nullptr) : value(_val), ptr_next(ptr) {}
};

template<typename T>
class List {
private:
    ListNode<T>* head_;
    ListNode<T>* tail_;

public:
    List();
    explicit List(T _val);
    ~List();
    ListNode<T>* Begin() const { return head_; }
    ListNode<T>* End() const { return tail_; 
    T& Front() const;
    T& Back() const;
    bool IsEmpty() const;
    int Size() const;
    void PushBack(T value);
    void Insert(int position, const T& value);  
    void PushFront(T value);
    T PopBack();
    T PopFront();
    void Clear();
    void Print() const;
    void DeleteHead();

    ListNode<T>& operator[](int index) const;

    class BadIndex {
    private:
        int index_;

    public:
        BadIndex(int index) : index_(index) { std::cerr << "Error. Index " << index_ << " is invalid\n"; }
    };
};

template<typename T>
List<T>::List() : head_(nullptr), tail_(nullptr) {}

template<typename T>
List<T>::List(T _val) {
    head_ = new ListNode<T>(_val, nullptr);
    tail_ = head_;  
}

template<typename T>
List<T>::~List() {
    Clear();
}

template<typename T>
T& List<T>::Front() const {
    return head_->value;
}

template<typename T>
T& List<T>::Back() const {
    return tail_->value;
}

template<typename T>
bool List<T>::IsEmpty() const {
    return head_ == nullptr && tail_ == nullptr;
}

template<typename T>
int List<T>::Size() const {
    int counter = 0;
    ListNode<T>* temp = head_;
    while (temp != nullptr) {
        counter++;
        temp = temp->ptr_next;
    }
    return counter;
}

template<typename T>
void List<T>::PushBack(T value) {
    if (IsEmpty()) {  
        tail_ = new ListNode<T>(value, nullptr);
        head_ = tail_;
        return;
    }
    tail_->ptr_next = new ListNode<T>(value);
    tail_ = tail_->ptr_next;
}

template<typename T>
void List<T>::PushFront(T value) {
    if (IsEmpty()) {  
        tail_ = new ListNode<T>(value, nullptr);
        head_ = tail_;
        return;
    }
    ListNode<T>* temp = new ListNode<T>(value, head_);  
    head_ = temp;  
    temp = nullptr;
}

template<typename T>
T List<T>::PopBack() {
    ListNode<T>* temp = head_;
    while (temp->ptr_next != tail_ && temp->ptr_next != nullptr) {   
        temp = temp->ptr_next;
    }
    T ret_val = tail_->value; 
    delete tail_;       
    if (head_ == tail_) {  
        head_ = nullptr;
        tail_ = nullptr;
    }
    else {
        tail_ = temp;       
        tail_->ptr_next = nullptr;
    }
    return ret_val;
}

template<typename T>
T List<T>::PopFront() {
    ListNode<T>* temp = head_->ptr_next;  
    T ret_val = head_->value; 
    if (Size() == 1) {  
        tail_ = temp;   
    }
    delete head_;
    head_ = temp;  
    return ret_val;
}

template<typename T>
void List<T>::Insert(int position, const T& value) { 
    if (position < 0) {
        throw BadIndex(position);
    }
   
    if (position > Size() - 1) {   
        PushBack(value);  
        return;
    }
    if (position == 0 && !IsEmpty()) { 
        PushFront(value);
        return;
    }
    else if (IsEmpty()) {    
        PushBack(value);
        return;
    }
   
    ListNode<T>* ins_ptr = new ListNode<T>(value);  
    ListNode<T>* temp = head_;
    while (position > 1 && temp != tail_) {
        temp = temp->ptr_next;
        --position;
    }
    ListNode<T>* linker = temp;  
    temp = temp->ptr_next;       
    linker->ptr_next = ins_ptr;  
    ins_ptr->ptr_next = temp;    
  
    linker = nullptr;
    temp = nullptr;
    ins_ptr = nullptr;
}

template<typename T>
void List<T>::DeleteHead() {
    ListNode<T>* temp = head_;
    head_ = head_->ptr_next;
    delete temp;
    temp = nullptr;
}

template<typename T>
void List<T>::Print() const {
    ListNode<T>* printer = head_;
    std::cout << "List:\n";
    while (printer != nullptr) {
        std::cout << printer->value << '\t';
        printer = printer->ptr_next;
    }
}

template<typename T>
void List<T>::Clear() {
    while (head_ != nullptr) {
        if (head_ == tail_) { 
            tail_ = nullptr;
        }
        DeleteHead();
    }
}

template<typename T>
ListNode<T>& List<T>::operator[](int index) const {  
    if (index < 0 || index > Size() - 1) {
        throw BadIndex(index);
    }
    ListNode<T>* temp = head_;
    while (index > 0 && temp != tail_) {
        temp = temp->ptr_next;
        --index;
    }
    return *temp;   
}