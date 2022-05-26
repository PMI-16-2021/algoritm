#pragma once
#include <iostream>

template <typename T>
struct NodeStack {
	T value;
	NodeStack<T>* next;
	NodeStack<T>(T val, NodeStack* nex);
};

template <typename T>
class Stack {
private:
	NodeStack<T>* top;

public:
	Stack<T>();
	Stack<T>(T);

	//int getValue() const;

	void emplace(T);
	void push(T);
	void printStack();
	bool isEmpty();
	void empty();
	int size();
	T pop();
	T topS();
	void swap(Stack*);
};

template <typename T>
NodeStack<T>::NodeStack<T>(T val, NodeStack<T>* nex) {
	value = val;
	next = nex;
}

template <typename T>
Stack<T>::Stack() {
	top = nullptr;
}

template <typename T>
Stack<T>::Stack(T value) {
	top = new NodeStack<T>(value, nullptr);
}

template <typename T>
void Stack<T>::emplace(T value) {
	NodeStack<T>* local = new NodeStack<T>(value, top);
	top = local;
}
template <typename T>
void Stack<T>::push(T value) {
	NodeStack<T>* local = new NodeStack<T>(value, top);
	top = local;
}

template <typename T>
void Stack<T>::printStack() {
	if (top == nullptr) {
		std::cout << "\nStack is empty!\n";
		return;
	}
	std::cout << "\nMy Stack: ";
	NodeStack<T>* local = top;
	while (local) {
		std::cout << local->value << ' ';
		local = local->next;
	}
	std::cout << "\n";
}

template <typename T>
bool Stack<T>::isEmpty() {
	if (!top) {
		return true;
	}
	else return false;
}

template <typename T>
void Stack<T>::empty() {
	NodeStack<T>* local = top;
	NodeStack<T>* temp;
	while (local != nullptr) {
		temp = local;
		local = local->next;
		delete temp;
	}
	top = nullptr;
}

template <typename T>
int Stack<T>::size() {
	if (top == nullptr) {
		std::cout << "\nStack is empty!\n";
	}
	int counter = 0;
	NodeStack<T>* local = top;
	while (local) {
		++counter;
		local = local->next;
	}
	delete local;
	return counter;
}

template <typename T>
T Stack<T>::pop() {
	NodeStack<T>* local;
	T loc;
	loc = top->value;
	local = top;
	top = top->next;
	delete local;
	return loc;
}

template <typename T>
T Stack<T>::topS() {
	return top->value;
}

template <typename T>
void Stack<T>::swap(Stack<T>* object) {
	NodeStack<T>* buffer = top;
	this->top = object->top;
	object->top = buffer;
}


int Priority(char); // обчислення пріоритету операцій
std::string ToPostfix(std::string); // Перетворює арифметичні вирази з дужками
bool IsDigital(char); // перевіряє, чи належить символ до запису числа
int Calculate(std::string expr);
void TranslateAndCalculate();
bool IsOperator(char c);