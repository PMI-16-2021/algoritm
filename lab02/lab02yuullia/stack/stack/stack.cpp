#include "stack.h"
using namespace std;

Stack::Stack()  {
    stack_top = -1;
}
Stack::~Stack() {}

bool Stack::isEmpty() const {
    return stack_top == -1;
}

bool Stack::isFull() {
    return stack_top == MAX - 1;
}

int Stack::size() {
    return stack_top++;
}

void Stack::push(int value) {
    if (isFull()) {
        return;
    }
    ++stack_top;
    arr[stack_top] = value;
}

void Stack::pop() {
    int temp;
    if (isEmpty()) {
        return;
    }
    temp = arr[stack_top];
    --stack_top;
}

int Stack::top() {
    return arr[stack_top];
}
void Stack::emplace(const int& item) {
    arr[stack_top++] = item;
}

void Stack::swap(int i, int j) {
    if (i > stack_top || j > stack_top || i < 0 || j < 0) {
        return;
    }
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Stack::printStack() {
    if (isEmpty()) {
        cout << "Stack is empty.\n";
        return;
    }
    cout << "Stack: ";
    for (int i = stack_top; i >= 0; i--) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}