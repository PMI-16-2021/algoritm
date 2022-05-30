#pragma once
struct StackNode {
    int value;
    StackNode* next;
    StackNode(int _value, StackNode* _next);
};

class Stack {
private:
    StackNode* top_;
    void DeleteTop();
public:
    Stack();
    Stack(int value);
    ~Stack();
    bool Empty() const;
    int Size() const;
    int Top() const;
    void Push(int value);
    void Emplace(int& item);
    void Pop();
    void Swap(Stack& other);
    void PrintStack();
};

class EmptyStackExeption {
public:
    EmptyStackExeption(const char* msg);
};
