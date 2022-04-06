#pragma once
#include "stack.h"

struct SetNode {   // Set as a "one direction" list
    Stack stack;   // list item
    SetNode* next_stack;  // list item pointer
    SetNode(int value, SetNode* next_stack = nullptr);
};

class SetOfStacks {
private:
    int stack_ceiling_;   // max size(height) of Stack in Set
    size_t node_index_;
    SetNode* current_stack_;  // pointer to current Stack in Set
public:
    SetOfStacks();   // current_stack_ = nullptr
    SetOfStacks(int value, int ceiling);  // create Set of stacks and push value to the first stack
    ~SetOfStacks();  // to do: clear method

    size_t GetCurrentIndex() const { return node_index_;}
    bool IsEmpty() const;           // +
    void Push(int value_to_push);   // push to the set like to the simple stack +
    int Pop();                      // pop from the set like from the simple stack+
    int PopAtPush(int pop_index);  // pop from given stack index (stacks with push)+
    int PopAt(int pop_index);  // default +
    void PrintSet() const;   //+
    void ClearSet(); //+

    class EmptySet {
    public:
        EmptySet(const char* message) { std::cerr<<message<<std::endl;}
    };

    class BadIndex {
    public:
        BadIndex(int index, int max_index) {std::cerr<<"Index: "<<index<<" is invalid. "<<"Max index is "<<max_index<<std::endl;}
    };
};