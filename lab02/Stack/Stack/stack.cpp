#include "stack.h"
NodeStack::NodeStack(int val, NodeStack* nex) {
	value = val;
	next = nex;
}
Stack::Stack() {
	top = nullptr;
	//this->next = nullptr;
}
Stack::Stack(int value) {
	top = new NodeStack(value, nullptr);
	//this->next = nullptr;
}
//int Stack::getValue() const {
//	return value;
//}
void Stack::emplace(int value) {
	NodeStack* local = new NodeStack(value, top);
	top = local;
}
void Stack::push(int value) {
	NodeStack* local = new NodeStack(value, top);
	top = local;
}
void Stack::printStack() {
	if (top == nullptr) {
		std::cout << "\nStack is empty!\n";
		return;
	}
	std::cout << "\nMy Stack: ";
	NodeStack* local = top;
	while (local) {
		std::cout << local->value << ' ';
		local = local->next;
	}
	std::cout << "\n";
}
bool Stack::isEmpty() {
	if (!top) {
		return true;
	}
	else return false;
}
void Stack::empty() {
	NodeStack* local = top;
	NodeStack* temp;
	while (local != nullptr) {
		temp = local;
		local = local->next;
		delete temp;
	}
	top = nullptr;
}
int Stack::size() {
	if (top == nullptr) {
		std::cout << "\nStack is empty!\n";
	}
	int counter = 0;
	NodeStack* local = top;
	while (local) {
		++counter;
		local = local->next;
	}
	delete local;
	return counter;
}
void Stack::pop() {
	NodeStack* local;
	int loc;
	loc = top->value;
	local = top;
	top = top->next;
	delete local;
}
int Stack::topS() {
	return top->value;
}
void Stack::swap(Stack* object) {
	NodeStack* buffer = top;
	this->top = object->top;
	object->top = buffer;
}