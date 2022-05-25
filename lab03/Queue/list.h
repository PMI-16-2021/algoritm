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
    //Iterators
    ListNode<T>* Begin() const {return head_;}
    ListNode<T>* End() const {return tail_;}
    // List methods
    T& Front() const;
    T& Back() const;
    bool IsEmpty() const;
    int Size() const;
    void PushBack(T value);
    void Insert(int position, const T& value);  // position is from 0 to n
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
        BadIndex(int index) : index_(index) {std::cerr << "Error. Index " << index_ << " is invalid\n";}
    };
};

template<typename T>
List<T>::List() : head_(nullptr), tail_(nullptr) {}

template<typename T>
List<T>::List(T _val)  {
    head_ = new ListNode<T>(_val, nullptr);
    tail_ = head_;  // point to same elem
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
    while(temp != nullptr) {
        counter++;
        temp = temp->ptr_next;
    }
    return counter;
}

template<typename T>
void List<T>::PushBack(T value) {
    if(IsEmpty()) {  // push to the empty list
        tail_ = new ListNode<T>(value, nullptr);
        head_ = tail_;
        return;
    }
    tail_->ptr_next = new ListNode<T>(value);
    tail_ = tail_->ptr_next;
}

template<typename T>
void List<T>::PushFront(T value) {
    if(IsEmpty()) {  // push to the empty list
        tail_ = new ListNode<T>(value, nullptr);
        head_ = tail_;
        return;
    }
    ListNode<T>* temp = new ListNode<T>(value, head_);  // new head points to old
    head_ = temp;   // head jumps at the beginning of list
    temp = nullptr;
}

template<typename T>
T List<T>::PopBack() {
    ListNode<T>* temp = head_;
    while(temp->ptr_next != tail_ && temp->ptr_next != nullptr) {   // stop before end of list
        temp = temp->ptr_next;
    }
    T ret_val = tail_->value; //store value
    delete tail_;       // delete tail node
    if(head_ == tail_){  // if poping last element
        head_ = nullptr;
        tail_ = nullptr;
    }
    else{
        tail_ = temp;       // jump to previous node
        tail_->ptr_next = nullptr;
    }
    return ret_val;
}

template<typename T>
T List<T>::PopFront() {
    ListNode<T>* temp = head_->ptr_next;  // anchor for head pointer , if size == 1 => temp == nullptr
    T ret_val = head_->value; //store value
    if(Size() == 1) {   // => head == tail
        tail_ = temp;   // early nulling the tail_, to avoid hanging pointer after <delete head_>
    }
    delete head_;
    head_ = temp;  // head = nullptr
    return ret_val;
}

template<typename T>
void List<T>::Insert(int position, const T& value) { // ~ O(n), indexing from 0 to n
    if (position < 0) {
        throw BadIndex(position);
    }
    // special cases
    if(position > Size()-1) {   // if position value bigger than already used — pushing back, Size() ~ O(n)
        PushBack(value);  // O(1)
        return;
    }
    if(position == 0 && !IsEmpty()) {  // pushing at head place
        PushFront(value);
        return;
    }
    else if(IsEmpty()) {    // if empty — position doesn't matter
        PushBack(value);
        return;
    }
    // general case:
    ListNode<T>* ins_ptr = new ListNode<T>(value);  // construct insert node, ptr_next = nullptr
    ListNode<T>* temp = head_;
    while(position > 1 && temp != tail_) { // stop before inserting position
        temp = temp->ptr_next;
        --position;
    }
    ListNode<T>* linker = temp;  // linker points to element that lying before inserting position, it goes to the next element
    temp = temp->ptr_next;       // temp points to insert position
    linker->ptr_next = ins_ptr;  // linked at front
    ins_ptr->ptr_next = temp;    // binding insert value's position
    // nulling sidehelp pointers
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
    std::cout<< "List:\n";
    while (printer != nullptr) {
        std::cout<< printer->value << '\t';
        printer = printer->ptr_next;
    }
}

template<typename T>
void List<T>::Clear() {
    while(head_ != nullptr) {
        if(head_ == tail_) { //if deleting last element
            tail_ = nullptr;
        }
        DeleteHead();
    }
}

template<typename T>
ListNode<T>& List<T>::operator[](int index) const {   // don't check if empty, O(n) the worst complexity
    if(index < 0 || index > Size()-1) {
        throw BadIndex(index);
    }
    ListNode<T>* temp = head_;
    while(index > 0 && temp != tail_) {
        temp = temp->ptr_next;
        --index;
    }
    return *temp;   // returning exactly node, not a pointer
}


