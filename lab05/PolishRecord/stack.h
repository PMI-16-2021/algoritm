#pragma once
#include <iostream>
//Last in First out

template<typename T>
struct StackNode {
    T item_value;
    StackNode<T>* next_item_link;
    StackNode(T value, StackNode<T>* link = nullptr);
};

template<typename T>
class Stack {
private:
    size_t size_;
    StackNode<T>* item_;   // top element
    void DeleteTop();
public:
    Stack(); // item_ = nullptr;
    Stack(T item_value);
    ~Stack();   // clear stack

    StackNode<T>* GetTopPtr() const {return item_;}
    bool IsEmpty() const;                   // test whether stack is empty  +
    int GetSize() const {return size_;}     // return stack size +
    void CutSize(){--size_;}                // used in set_of_stacks.cpp in PopAt funcs
    void Push(T value_to_push);           // insert element +
    T Top() const;                        // Access next element +
    void Emplace(T& to_emplace);          // construct and insert element +
    T Pop();                              // return and remove top element +
    void Swap(Stack& other);                // swap stack pointers +
    void ClearStack();                      // +
    void PrintStack();                      // +

    class EmptyStack {
    public:
        EmptyStack(const char* message) { std::cerr<<message<<std::endl;}
    };
};


template<typename T>
StackNode<T>::StackNode(T value, StackNode<T>* link) : item_value(value), next_item_link(link) {}

template<typename T>
Stack<T>::Stack() {
    item_ = nullptr;
    size_ = 0;
}

template<typename T>
Stack<T>::Stack(T item_value) {
    item_ = new StackNode<T>(item_value, nullptr);
    ++size_;
}

template<typename T>
Stack<T>::~Stack() {
    ClearStack();
}

template<typename T>
void Stack<T>::PrintStack()  {
    if(IsEmpty()) {
        throw EmptyStack("You can't print EMPTY stack.");
    }
    StackNode<T>* helper = item_;
    while(helper != nullptr) {
        std::cout << helper->item_value << '\n'; //<< helper << '\t' << helper->next_item_link << '\n';
        helper = helper->next_item_link;
    }
}

template<typename T>
bool Stack<T>::IsEmpty() const {
    return (item_ == nullptr);
}

template<typename T>
void Stack<T>::Push(T value_to_push) { // also works with empty stack
    StackNode<T>* helper = new StackNode<T>(value_to_push, item_);  // helper refers to the TOP element
    item_ = helper;                 // TOP jumps
    ++size_;
}

template<typename T>
T Stack<T>::Top() const {
    if(IsEmpty()) {
        throw EmptyStack("You can't get top element from EMPTY stack.");
    }
    return item_->item_value;
}

template<typename T>
void Stack<T>::Emplace(T& to_emplace) {   // int a = 9; stack.Emplace(a);
    StackNode<T>* to_emplace_item = new StackNode<T>(to_emplace, item_);
    item_ = to_emplace_item;
    ++size_;
}

template<typename T>
T Stack<T>::Pop() {
    if(IsEmpty()) {
        throw EmptyStack("You can't pop element from EMPTY stack.");
    }
    T return_value = item_->item_value;
    DeleteTop();
    return return_value;
}

template<typename T>
void Stack<T>::Swap(Stack<T>& other) {
    StackNode<T>* helper = item_;
    item_ = other.item_;
    other.item_ = helper;
}

template<typename T>
void Stack<T>::DeleteTop() {
    if(size_ == 1) {  // precised for set_of_stacks.cpp line 111
        delete item_;
        --size_;
        item_ = nullptr;
    }
    else {
        StackNode<T>* helper = item_;
        item_ = item_->next_item_link;
        delete helper;
        --size_;
    }
}

template<typename T>
void Stack<T>::ClearStack() {
    while (!IsEmpty()) {
        DeleteTop();
    }
}
