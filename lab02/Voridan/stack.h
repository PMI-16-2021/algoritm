#pragma once
#include <iostream>
//Last in First out

struct StackNode {
    int item_value;
    StackNode* next_item_link;
    StackNode(int value, StackNode* link = nullptr);
};

class Stack {
private:
    size_t size_;
    StackNode* item_;   // top element
    void DeleteTop();
public:
    Stack(); // item_ = nullptr;
    Stack(int item_value);
    ~Stack();   // clear stack

    StackNode* GetTopPtr() const {return item_;}
    bool IsEmpty() const;                   // test whether stack is empty  +
    int GetSize() const {return size_;}     // return stack size +
    void CutSize(){--size_;}                // used in set_of_stacks.cpp in PopAt funcs
    void Push(int value_to_push);           // insert element +
    int Top() const;                        // Access next element +
    void Emplace(int& to_emplace);           // construct and insert element +
    int Pop();                              // return and remove top element +
    void Swap(Stack& other);                // swap stack pointers +
    void ClearStack();                      // +
    void PrintStack();                      // +

    class EmptyStack {
    public:
        EmptyStack(const char* message) { std::cerr<<message<<std::endl;}
    };
};

