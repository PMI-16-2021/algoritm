#include "stack.h"

StackNode::StackNode(int value, StackNode* link) : item_value(value), next_item_link(link) {}

Stack::Stack() {
    item_ = nullptr;
    size_ = 0;
}

Stack::Stack(int item_value) {
    item_ = new StackNode(item_value, nullptr);
    ++size_;
}

Stack::~Stack() {
    ClearStack();
}

void Stack::PrintStack()  {
    if(IsEmpty()) {
        throw EmptyStack("You can't print EMPTY stack.");
    }
    StackNode* helper = item_;
    while(helper != nullptr) {
        std::cout << helper->item_value << '\n'; //<< helper << '\t' << helper->next_item_link << '\n';
        helper = helper->next_item_link;
    }
}

bool Stack::IsEmpty() const {
    return (item_ == nullptr);
}

void Stack::Push(int value_to_push) { // also works with empty stack
    StackNode* helper = new StackNode(value_to_push, item_);  // helper refers to the TOP element
    item_ = helper;                 // TOP jumps
    ++size_;
}

int Stack::Top() const {
    if(IsEmpty()) {
        throw EmptyStack("You can't get top element from EMPTY stack.");
    }
    return item_->item_value;
}

void Stack::Emplace(int& to_emplace) {   // int a = 9; stack.Emplace(a);
    StackNode* to_emplace_item = new StackNode(to_emplace, item_);
    item_ = to_emplace_item;
    ++size_;
}

int Stack::Pop() {
    if(IsEmpty()) {
        throw EmptyStack("You can't pop element from EMPTY stack.");
    }
    int return_value = item_->item_value;
    DeleteTop();
    return return_value;
}
void Stack::Swap(Stack& other) {
    StackNode* helper = item_;
    item_ = other.item_;
    other.item_ = helper;
}

void Stack::DeleteTop() {
    if(size_ == 1) {  // precised for set_of_stacks.cpp line 111
        delete item_;
        --size_;
        item_ = nullptr;
    }
    else {
        StackNode* helper = item_;
        item_ = item_->next_item_link;
        delete helper;
        --size_;
    }
};

void Stack::ClearStack() {
    while (!IsEmpty()) {
        DeleteTop();
    }
}
