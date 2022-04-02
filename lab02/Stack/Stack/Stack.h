#pragma once
#include <iostream>

class Stack {
private:
	int value;
	Stack* next;
	Stack* top;
	
public:
	//static Stack* top;

	Stack();
	Stack(int);

	int getValue() const;

	void emplace(int);
	void push(int);
	void printStack();
	bool isEmpty();
	void empty();
	int size();
	void pop();
	int topS();
	void swap(Stack*);
};
