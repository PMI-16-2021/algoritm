#pragma once
#include <iostream>

template <typename T>
struct NodeStack {
	T value;
	NodeStack* link;
	NodeStack(T _value, NodeStack* _link);
};

template<typename T>
NodeStack<T>::NodeStack(T _value, NodeStack* _link) : value(_value), link(_link) {
}

template<typename T>
class Stack {
private:
	NodeStack<T>* top;
public:
	Stack<T>();
	Stack<T>(T item);
	~Stack<T>();
	bool IsEmpty();
	void Push(T item);
	T Pop();
	int Size();
	T Top();
	void Swap(Stack<T>& other_stack);
	void Emplace(T& item);
	void Empty();
	void Print();
};

template<typename T>
Stack<T>::Stack() : top(nullptr) {
}

template<typename T>
Stack<T>::Stack(T item) {
	top = new NodeStack<T>(item, nullptr);
}

template<typename T>
Stack<T>::~Stack() {
	Empty();
}

template<typename T>
bool Stack<T>::IsEmpty() {
	return top == nullptr;
}

template<typename T>
void Stack<T>::Push(T item) {
	NodeStack<T>* element = new NodeStack<T>(item, top) ;
	top = element;
}

template<typename T>
T Stack<T>::Pop() {
	if (IsEmpty()) {
		throw "Stack is empty";
	}
	else {
		NodeStack<T>* temp;
		T item;
		item = top->value;
		temp = top;
		top = top->link;
		delete temp;
		return item;
	}
}

template<typename T>
int Stack<T>::Size() {
	if (IsEmpty()) {
		return 0;
	}
	else {
		NodeStack<T>* temp = top;
		int size = 0;
		while (temp != nullptr) {
			++size;
			temp = temp->link;
		}
		delete temp;
		return size;
	}
}

template<typename T>
T Stack<T>::Top() {
	if (IsEmpty()) {
		throw "Stack is empty.";
	}
	else {
		return top->value;
	}
}

template<typename T>
void Stack<T>::Swap(Stack<T>& other_stack) {
	NodeStack<T>* temp = top;
	top = other_stack.top;
	other_stack.top = temp;
}

template<typename T>
void Stack<T>::Emplace(T& item) {
	NodeStack<T>* element = new NodeStack<T>(item, top);
	top = element;
}

template<typename T>
void Stack<T>::Empty() {
	NodeStack<T>* temp_top = top; 
	NodeStack<T>* temp;
	while (temp_top != nullptr) {
		temp = temp_top; 
		temp_top = temp_top->link;
		delete temp; 
	}
	top = nullptr;
}

template<typename T>
void Stack<T>::Print() {
	if (IsEmpty()) {
		std::cout << "Stack is empty.";
	}
	else {
		NodeStack<T>* temp = top; 
		while (temp != nullptr) {
			std::cout << temp->value << "; ";
			temp = temp->link;
		}
	}
}
