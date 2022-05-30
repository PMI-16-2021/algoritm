#pragma once
#include<iostream>
using namespace std;
struct Node
{
	Node* ptr;
	int val;
	Node(int NodeVal, Node *Nodeptr);
};
class Stack 
{
private:
	Node* top = nullptr;
	int size;
public:
	Stack();
	Stack(int val);
	~Stack();
	Stack* next = nullptr;
	int push(int val);
	bool isEmpty()const;
	int Pop();
	void delTop();
	void print() const;
	int getSize();
	void swap(Stack& stack);
	int topVal();

};