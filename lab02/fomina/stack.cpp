#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack():top(nullptr),max(5){};
Stack::Stack(int stackTop): top(new StackNode(stackTop)), max(5) {};
void Stack::push(int val)
{
	if (this->isFull() == true) {
		cout << "stack is full\n";
		return;
	}
	if (top == nullptr){
		top = new StackNode(val);
		return;
	}
	StackNode* lastNode = top;
	while (lastNode->nextNode != nullptr){
		lastNode = lastNode->nextNode;
	}
	lastNode->nextNode = new StackNode(val);
}
void Stack::printStack()
{
	if (top == nullptr) {
		cout << "empty\n";
		return;
	}
	StackNode* currNode = top;
	while (currNode->nextNode != nullptr){
		cout << currNode->stackEl << " ";
		currNode = currNode->nextNode;
	}
	cout << currNode->stackEl << " ";
	cout << endl;
}
bool Stack::isFull()
{
	if (top == nullptr) {
		return false;
	}
	StackNode* currNode = top;
	size_t m = 1;
	while (currNode->nextNode != nullptr) {
		m++;
		if (m == max) {
			return true;
		}
		//++m;
		currNode = currNode->nextNode;
	}
	return false;
}
void Stack::pop()
{
	if (this->isEmpty() == true) {
		cout << "stack is empty\n";
		return ;
	}
	StackNode* currNode = top;
	while (currNode->nextNode->nextNode != nullptr) {
		currNode = currNode->nextNode;
	}
	StackNode* popNode = currNode->nextNode;
	
	currNode->nextNode = nullptr;
	delete popNode;
}
bool Stack::isEmpty()
{
	return top == nullptr;
}
void Stack::swap(Stack* s)
{
	StackNode* curr = top;
	this->top = s->top;
	s->top = curr;
}
int Stack::sTop()
{
	return top->stackEl;
}
int Stack::sLast()
{
	StackNode* lastNode = top;
	while (lastNode->nextNode != nullptr) {
		lastNode = lastNode->nextNode;
	}
	return lastNode->stackEl;
}
int Stack::size()
{
	if (this->isEmpty()) {
		return 0;
	}
	StackNode* currNode = top;
	size_t m = 1;
	while (currNode->nextNode != nullptr) {
		m++;
		if (m == max) {
			break;
		}
		//++m;
		currNode = currNode->nextNode;

	}
	return m;
}
void Stack::emplace(int value,int plase) 
{
	if (this->isFull() == true) {
		cout << "stack is full";
		return;
	}
	if (plase <= 0) {
		return;
	}
	if (plase == 1) {
		StackNode* local = new StackNode(value, top);
		top = local;
		return;
	}
	if (plase > 5) {
		return;
	}
	int m = 1;
	StackNode* currNode = top;
	while (currNode->nextNode != nullptr) {
		++m;
		if (m == plase) {
			break;
		}
		currNode = currNode->nextNode;
	}
	StackNode* local = new StackNode(value, currNode->nextNode);
	currNode->nextNode = local;
}
void Stack::empty() {
	StackNode* currNode = top;
	StackNode* temp;
	while (currNode != nullptr) {
		temp = currNode;
		currNode = currNode->nextNode;
		delete temp;
	}
	top = nullptr;
}