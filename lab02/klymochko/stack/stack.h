#pragma once
#include <iostream>

struct Node
{
	int value;
	Node* next;
	Node(int val, Node* nex);
};

class Stack
{
private:
	Node* top;

public:
	Stack();
	Stack(int value);
	
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
