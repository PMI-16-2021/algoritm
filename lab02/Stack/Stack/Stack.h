#pragma once
#include <iostream>

struct NodeStack{
	int value;
	NodeStack* next;
	NodeStack(int val, NodeStack* nex);
};

class Stack {
private:
	NodeStack* top;
	
public:
	//static Stack* top;

	Stack();
	Stack(int);

	//int getValue() const;

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
