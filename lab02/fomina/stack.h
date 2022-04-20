#pragma once
#include <iostream>

struct StackNode {
	int stackEl;
	StackNode* nextNode;
	StackNode():stackEl(0),nextNode(nullptr){}
	StackNode(int value) :stackEl(value), nextNode(nullptr) {}
	StackNode(int value, StackNode* next) :stackEl(value), nextNode(next) {}
};
class Stack /*: public StackNode*/{
private:
	StackNode* top;
	size_t max;
public:
	Stack();
	Stack(int stackTop);
	void push(int val);
	void printStack();
	bool isFull();
	void pop();
	bool isEmpty();
	void swap(Stack* s);
	int sTop();
	int sLast();
	int size();
	void emplace(int value,int plase);
	void empty();
	
};
