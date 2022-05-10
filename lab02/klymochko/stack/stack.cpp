#include "stack.h"
Node::Node(int val, Node* nex)
	:value(val), next(nex)
{

}

Stack::Stack()
	:top(nullptr)
{

}

Stack::Stack(int value)
{
	top = new Node(value, nullptr);
}

void Stack::emplace(int value)
{
	Node* newNode = new Node(value, top);
	top = newNode;
}
void Stack::push(int value)
{
	Node* newNode = new Node(value, top);
	top = newNode;
}
void Stack::printStack()
{
	if (top == nullptr)
	{
		std::cout << "\nStack is empty!\n";
		return;
	}
	std::cout << "\nStack: ";
	Node* object = top;
	while (object)
	{
		std::cout << object->value << ' ';
		object = object->next;
	}
	std::cout << "\n";
}
bool Stack::isEmpty()
{
	if (!top)
	{
		return true;
	}
	
	return false;
}
void Stack::empty()
{
	Node* object = top;
	Node* temp;
	while (object != nullptr)
	{
		temp = object;
		object = object->next;
		delete temp;
	}
	top = nullptr;
}
int Stack::size()
{
	if (top == nullptr)
	{
		std::cout << "\nStack is empty!\n";
	}
	size_t counter = 0;
	Node* object = top;
	while (object)
	{
		++counter;
		object = object->next;
	}
	delete object;
	return counter;
}
void Stack::pop()
{
	Node* object;
	int obj;
	obj = top->value;
	object = top;
	top = top->next;
	delete object;
}
int Stack::topS()
{
	return top->value;
}
void Stack::swap(Stack* object)
{
	Node* temp = top;
	this->top = object->top;
	object->top = temp;
}