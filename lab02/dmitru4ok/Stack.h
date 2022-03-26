#pragma once
#include <iostream>
class Stack
{
public:
	struct StackNode
	{
		int item;
		StackNode* next;
		StackNode(int _item, StackNode* _next = nullptr) : item(_item), next(_next) {}

	};
private:
	StackNode* Top;
	void delFirst();
public:
	Stack(): Top(nullptr){}
	Stack(int _first_item): Top(new StackNode(_first_item, nullptr)){}
	~Stack(); // uses empty

	void push(int); //add new node with paraeter value
	void clear(); //clear all nodes
	int pop(); // return item and remove first node
	bool empty(); // check if is empty
	size_t size();
	void printStack();
	int top();
};

