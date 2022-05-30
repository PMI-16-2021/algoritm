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

	

	void Emplace(T);
	void Push(T);
	void PrintStack();
	bool IsEmpty();
	void Empty();
	int size();
	T Pop();
	T TopS();
	void Swap(Stack*);
};

template <typename T>
NodeStack<T>::NodeStack<T>(T val, NodeStack<T>* next_) {
	value = val;
	next = next_;
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
void Stack<T>::Emplace(T value) {
	NodeStack<T>* local = new NodeStack<T>(value, top);
	top = local;
}
template <typename T>
void Stack<T>::Push(T value) {
	NodeStack<T>* local = new NodeStack<T>(value, top);
	top = local;
}

template <typename T>
void Stack<T>::PrintStack() {
	if (top == nullptr) {
		std::cout << "\nStack's empty!\n";
		return;
	}
	std::cout << "\nStack: ";
	NodeStack<T>* local = top;
	while (local) {
		std::cout << local->value << ' ';
		local = local->next;
	}
	std::cout << "\n";
}

template <typename T>
bool Stack<T>::IsEmpty() {
	if (!top) {
		return true;
	}
	else return false;
}

template <typename T>
void Stack<T>::Empty() {
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
		std::cout << "\nStack's empty!\n";
	}
	int count = 0;
	NodeStack<T>* local = top;
	while (local) {
		++count;
		local = local->next;
	}
	delete local;
	return count;
}

template <typename T>
T Stack<T>::Pop() {
	NodeStack<T>* local;
	T loc;
	loc = top->value;
	local = top;
	top = top->next;
	delete local;
	return loc;
}

template <typename T>
T Stack<T>::TopS() {
	return top->value;
}

template <typename T>
void Stack<T>::Swap(Stack<T>* object) {
	NodeStack<T>* buffer = top;
	this->top = object->top;
	object->top = buffer;
}


int Priority(char); 
std::string ToPostfix(std::string); 
bool IsDigital(char); 
int Calculate(std::string expr);
void TranslateAndCalculate();
bool IsOperator(char c);