#pragma once
#include <iostream>
#include <utility>

class SizeException
{
public:
    void print() const { std::cout << "ERROR: Wrong size" << '\n'; };
};

class IndexException
{
public:
    void print() const { std::cout << "ERROR: Wrong index input, element does not exist" << '\n'; };
};

template <typename T>
class Stack {
public:
    int index;
    T memory[1000];
public:
    Stack() : index(0) {};
    ~Stack() {};
    bool empty();
    int size();
    T top();
    virtual void push(T x);
    void emplace(T x);
    virtual T pop();
    void swap(Stack& second_stack);
    virtual void print();
};

using std::cout;

template <typename T>
bool Stack<T>::empty() {
	return index == 0;
}

template <typename T>
int Stack<T>::size() {
	return index;
}

template <typename T>
T Stack<T>::top() {
	return memory[index - 1];
}

template <typename T>
void Stack<T>::push(T x) {
	memory[index] = x;
	index += 1;
}

template <typename T>
void Stack<T>::emplace(T x) {
	push(x);
}

template <typename T>
T Stack<T>::pop() {
	index -= 1;
	T temp = memory[index];
	memory[index] = T();
	return temp;
}

template <typename T>
void Stack<T>::swap(Stack& second_stack) {
	if (this->size() != second_stack.size()) {
		throw SizeException();
	}
	std::swap(this->memory, second_stack.memory);
}

template <typename T>
void Stack<T>::print() {
	int size = this->size();
	for (int i = 0; i < size; ++i) {
		cout << this->memory[i] << '\t';
	}
	cout << '\n';
}
