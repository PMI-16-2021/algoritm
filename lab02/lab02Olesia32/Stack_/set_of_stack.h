#pragma once
#include "stack.h"
#include <iostream>

template<typename T>
class SetOfStack {
private:
	Stack<T>* element; // array of stacks
	int size_of_stack; // maximum size of one stack
	int max_count; // number stacks in set
	int full_count; // number full stack
public:
	SetOfStack<T>();
	SetOfStack<T>(int _max_count,int _size_of_stack);
	~SetOfStack<T>();
	void PushSet(T item);
	T PopSet();
	T PopAt(int index);
	void EmptySet();
	void PrintSet();
};

template<typename T>
SetOfStack<T>::SetOfStack() : max_count(10), size_of_stack(10), full_count(0) {
	element = new Stack<T>[max_count];
}

template<typename T>
SetOfStack<T>::SetOfStack(int _max_count, int _size_of_stack) 
	: max_count(_max_count), size_of_stack(_size_of_stack), full_count(0) {
	element = new Stack<T>[max_count];
}

template<typename T>
SetOfStack<T>::~SetOfStack() {
	delete[] element;
}

template<typename T>
void SetOfStack<T>::PushSet(T item) {
	if (element[full_count].Size() == size_of_stack && full_count < max_count) {
		++full_count;
		element[full_count].Push(item);
	}
	else if (element[full_count].Size() < size_of_stack && full_count < max_count) {
		element[full_count].Push(item);
	}
	else {
		throw "Set of stack is full";
	}
}

template<typename T>
T SetOfStack<T>::PopSet() {
	if (element[full_count].IsEmpty() && full_count == 0) {
		throw "Set of stack is empty";
	}
	else if (element[full_count].IsEmpty() && full_count > 0) {
		while (element[full_count].IsEmpty() && full_count > 0) {
			--full_count;
		}
	}
	return element[full_count].Pop();
}

template<typename T>
T SetOfStack<T>::PopAt(int index) {
	if (index < 0 || index > max_count) {
		throw "Bad index\n";
	}
	if (element[index].IsEmpty()) {
		throw "Selected stack is empty\n";
	}
	return element[full_count].Pop();
}

template<typename T>
void SetOfStack<T>::PrintSet() {
	if (element[full_count].IsEmpty() && full_count == 0) {
		std::cout << "Set of stack is empty. ";
	}
	else {
		for (int i = 0; i <= full_count; ++i) {
			std::cout << i + 1 << "# ";
			element[i].Print();
			std::cout << '\n';
		}
	}
}

template<typename T>
void SetOfStack<T>::EmptySet() {
	for (int i = 0; i <= full_count; ++i) {
		element[i].Empty();
	}
	full_count = 0;
}