#include "stack.h"

Stack::Stack() {
	top = nullptr;
	this->next = nullptr;
}
Stack::Stack(int value) {
	this->value = value;
	top = this;
	//this->next = nullptr;
}
int Stack::getValue() const {
	return value;
}
void Stack::emplace(int value) {
	if (!top) {
		top = this;
		this->value = value;
	}
	else {
		Stack* object = new Stack();
		object->next = top;
		top = object;
		top->value = value;
	}
}
void Stack::push(int value) {
	if (!top) {
		top = this;
		this->value = value;
	}
	else {
		Stack* object = new Stack();
		object->next = top;
		top = object;
		top->value = value;
	}
}
void Stack::printStack() {
	if (top == nullptr) {
		std::cout << "\nStack is empty!\n";
		return;
	}
	std::cout << "\nMy Stack: ";
	Stack* local = top;
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
	top = nullptr;
}
int Stack::size() {
	if (top == nullptr) {
		std::cout << "\nStack is empty!\n";
	}
	int counter = 0;
	Stack* local = top;
	while (local) {
		++counter;
		local = local->next;
	}
	return counter;
}
void Stack::pop() {
	top = top->next;
}
int Stack::topS() {
	return top->value;
}
void Stack::swap(Stack* object) {
	Stack* buffer = this->top;
	this->top = object->top;
	object->top = buffer;
}