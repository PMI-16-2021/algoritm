#include "set_of_stacks.h"

SetNode::SetNode(int value, SetNode* next_stack) : next_stack(next_stack) {
    stack.Push(value);
}

SetOfStacks::SetOfStacks() : stack_ceiling_(0), current_stack_(nullptr), node_index_(0) {}

SetOfStacks::SetOfStacks(int value, int ceiling) : stack_ceiling_(ceiling), node_index_(0){
    current_stack_ = new SetNode(value, nullptr);
}

SetOfStacks::~SetOfStacks(){
    ClearSet();
}

bool SetOfStacks::IsEmpty() const {
    return (current_stack_ == nullptr);
}

void SetOfStacks::Push(int value_to_push) {
    if(IsEmpty()) {   // push to the SET made by DEFAULT constructor
        std::cout<<"Set is empty and max size of stack in set is uninitialised. Enter the size of stack in set:\n";
        std::cin>> stack_ceiling_;
        current_stack_ = new SetNode(value_to_push, nullptr);
//        std::cout<<node_index_<<" - index. index val: "<<current_stack_->stack.Top()<<'\n';
    }
    int size_checker = current_stack_->stack.GetSize();
    if(size_checker < stack_ceiling_) {   // if there is free space do:
//        std::cout<<"is space block running\n";
        current_stack_->stack.Push(value_to_push);
//        std::cout<<node_index_<<" - index. index val: "<<current_stack_->stack.Top()<<'\n';
    }
    else if (size_checker >= stack_ceiling_){  // if there isn't free space do:
//        std::cout<<"No space block running\n";
        SetNode* set_helper = new SetNode(value_to_push, current_stack_);
        current_stack_ = set_helper;   // refers to new stack
        ++node_index_;
//        std::cout<<node_index_<<" - index. index val: "<<current_stack_->stack.Top()<<'\n';
    }
}

int SetOfStacks::Pop() {
    if(IsEmpty()) {  // check is SET is empty
        throw EmptySet("You can't pop from EMPTY set");
    }
    bool stack_check = current_stack_->stack.IsEmpty();
    if(stack_check){ // check if STACK empty
        std::cout<<"STACK empty. Do:\n";
        --node_index_;
        current_stack_ = current_stack_->next_stack;  // go to the next stack in set
        std::cout<<node_index_<<" - index. Poped val: "<<current_stack_->stack.Top()<<'\n';
        return current_stack_->stack.Pop();
    }
    else {  // not empty — do pop
        std::cout<<"not empty — do pop:\n";
        std::cout<<node_index_<<" - index. Poped val: "<<current_stack_->stack.Top()<<'\n';
        return current_stack_->stack.Pop();
    }
}

int SetOfStacks::PopAt(int pop_index){
    if(pop_index > node_index_ || pop_index < 0) {
        throw BadIndex(pop_index, node_index_);
    }
    SetNode* poper = current_stack_;
    for(size_t i = node_index_; i > pop_index; --i) {
        poper = poper->next_stack;
    }
    return poper->stack.Pop();
}

int SetOfStacks::PopAtPush(int pop_index) {
    // Stacks that are located after pop_index stack in Set behave as Stacks with push (з проштовхуванням)
    int return_value = 0;
    if(pop_index > node_index_ || pop_index < 0) {
        throw BadIndex(pop_index, node_index_);
    }
    else if(pop_index == node_index_) {
        if(current_stack_->stack.GetSize() == 1) {
            return_value = current_stack_->stack.Pop();
            current_stack_ = current_stack_->next_stack;
            --node_index_;
        }
        else {
            return_value = current_stack_->stack.Pop();
        }
    }
    else if(pop_index < node_index_) {
        SetNode* poper = current_stack_;  // pointer that response for POP at Index
        for(size_t i = node_index_; i > pop_index; --i) {  // go through Set to the required stack
            poper = poper->next_stack;
        }
        return_value = poper->stack.Pop();  // pop at indexed stack
        SetNode* anchor = current_stack_; // anchor for current_stack_
        StackNode* nuller = nullptr;    // will be nulling the bottom stack nodes
        if(current_stack_->stack.GetSize() > 1) {  // if so, then no need of --node_index_
            StackNode* replacer; // replaces stack nodes in freed place at next stack
            for(size_t i = node_index_; i > pop_index; --i) {  // shifting stack nodes in SET NODES:
                replacer = anchor->stack.GetTopPtr();
                if (current_stack_->stack.GetTopPtr() == replacer) { // first iteration check, compare by address not value
                    while (replacer->next_item_link->next_item_link != nullptr) {  // stops at pre-last stack node
                        replacer = replacer->next_item_link;
                    }
                    nuller = replacer;
                    replacer = replacer->next_item_link; // go to stack node which must be replaced
                    nuller->next_item_link = nullptr; // bottom of stack
                    current_stack_ = current_stack_->next_stack;
                    current_stack_->stack.Push(replacer->item_value);
                    anchor->stack.CutSize(); // --size_ after replacing bottom element
                    delete replacer;
                }
                else {
                    replacer = current_stack_->stack.GetTopPtr();  // replacer  = address of the next stack top element
                    while (replacer->next_item_link->next_item_link != nullptr) { //stops at pre-last stack node
                        replacer = replacer->next_item_link;
                    }
                    nuller = replacer;
                    replacer = replacer->next_item_link;
                    nuller->next_item_link = nullptr;
                    current_stack_ = current_stack_->next_stack;
                    current_stack_->stack.Push(replacer->item_value);
                    delete replacer;
                }
            }
            current_stack_ = anchor;
        }
        else if (current_stack_->stack.GetSize() == 1) {  // if last stack consists only one element
            StackNode* replacer = anchor->stack.GetTopPtr();
            if(pop_index == node_index_-1) {             // and we're poping from neighbor stack
                // bottom element in current_stack_ jumps on top of current_stack_->next_stack
                anchor = anchor->next_stack;
                anchor->stack.Push(replacer->item_value);
                current_stack_->stack.ClearStack();
                current_stack_ = current_stack_->next_stack;
                --node_index_;
            }
            else {
                // bottom element in current_stack_ jumps on top of current_stack_->next_stack
                anchor = anchor->next_stack;
                anchor->stack.Push(replacer->item_value);
                current_stack_->stack.ClearStack();
                current_stack_ = current_stack_->next_stack;
                --node_index_;
                for(size_t i = node_index_; i > pop_index; --i) { // shifting next stack elements
                    replacer = current_stack_->stack.GetTopPtr();
                    while (replacer->next_item_link->next_item_link != nullptr) {
                        replacer = replacer->next_item_link;
                    }
                    nuller = replacer;
                    replacer = replacer->next_item_link;
                    nuller->next_item_link = nullptr;
                    current_stack_ = current_stack_->next_stack;
                    current_stack_->stack.Push(replacer->item_value);
                    delete replacer;
                }
                current_stack_ = anchor;
            }
        }
        }
    return return_value;
}

void SetOfStacks::PrintSet() const {
    if(IsEmpty()){
        throw EmptySet("You can't print from EMPTY set");
    }
    SetNode* printer = current_stack_;
    int counter = node_index_;
    while (printer != nullptr) {
        std::cout<<counter<<" index: \n";
        printer->stack.PrintStack();
        std::cout<<'\t';
        printer = printer->next_stack;
        --counter;
    }
}

void SetOfStacks::ClearSet() {
    while (!IsEmpty()){
        current_stack_->stack.ClearStack();
        current_stack_ = current_stack_->next_stack;
        --node_index_;
    }
    current_stack_ = nullptr;
}