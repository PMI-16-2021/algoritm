#include "stack.h"

Node::Node(int NodeValue, Node* NodeNext) : value(NodeValue), next(NodeNext) {}

Stack::Stack() : top(nullptr) {}

Stack::Stack(int value) {
    top = new Node(value, nullptr);
}

Stack::~Stack() {
    Node* temp_top = top;
    Node* temp;
    while (temp_top != nullptr) {
        temp = temp_top;
        temp_top = temp_top->next;
        delete temp;
    }
    top = nullptr;
}

bool Stack::isEmpty() {
    return top == nullptr;
}

int Stack::size() {
    if (isEmpty()) {
        return 0;
    }
    else {
        Node* temp = top;
        int counter = 0;
        while (temp != nullptr) {
            ++counter;
            temp = temp->next;
        }
        delete temp;
        return counter;
    }
}

int Stack::showTop() {
    if (isEmpty()) {
        throw "Stack is empty.";
    }
    else {
        return top->value;
    }
}

void Stack::push(int elem)
{
    Node* local = new Node(elem, top);
    top = local;
}

void Stack::emplace(int& elem) {
    Node* local = new Node(elem, top);
    top = local;
}

void Stack::swap(Stack& stack) {
    Node* temp = top;
    top = stack.top;
    stack.top = temp;
}

void Stack::pop()
{
    if (isEmpty()) {
        throw "Stack is empty";
    }
    else {
        Node* temp;
        int elem;
        elem = top->value;
        temp = top;
        top = top->next;
        delete temp;
    }
}

void Stack::printStack() {
    if (isEmpty()) {
        std::cout << "Stack is empty";
    }
    else {
        Node* temp = top;
        std::cout << "Stack: ";
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << "\n\n";
    }
}