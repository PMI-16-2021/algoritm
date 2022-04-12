#include "stack.h"

Stack::Stack() {}

Stack::~Stack() {}

bool Stack::isEmpty() {
    if (top == -1) {
        return true;
    }
    else {
        return false;
    }
}

bool Stack::isFull() {
    if (top == SIZE - 1) {
        return true;
    }
    else {
        return false;
    }
}

int Stack::size() {
    return top + 1;
}

int Stack::showTop() {
    if (isEmpty()) {
        cout << "Stack is empty\n";
    }
    return stackArray[top];
}

void Stack::push(int elem)
{
    if (isFull())
    {
        cout << "Stack is full\n";
    }
    else {
        ++top;
        stackArray[top] = elem;
    }
}

void Stack::emplace(int pos, int elem)
{
    if (isFull())
    {
        cout << "Stack is full\n";
    }
    else if (pos < 0 || pos > top) {
        cout << "Positions exist only between 0 and " << top << '\n';
    }
    else {
        stackArray[pos] = elem;
    }
}

void Stack::swap(int pos1, int pos2) {
    if (isEmpty()) {
        cout << "Stack is empty\n";
    }
    else if (pos1 > top || pos2 > top || pos1 < 0 || pos2 < 0) {
        cout << "Positions exist only between 0 and " << top << '\n';
    }
    else {
        int temp;
        temp = stackArray[pos1];
        stackArray[pos1] = stackArray[pos2];
        stackArray[pos2] = temp;
    }
}

void Stack::pop()
{
    if (isEmpty()) {
        cout << "Stack is empty";
    }
    else {
        --top;
    }
}

void Stack::printStack()
{
    if (isEmpty()) {
        return;
    }
    else {
        cout << "Stack: ";
        for (int i = 0; i <= top; ++i) {
            cout << stackArray[i] << ' ';
        }
        cout << '\n';
    }
}