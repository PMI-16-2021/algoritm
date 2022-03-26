#include "Stack.h"


Stack::~Stack()
{
	this->clear();
}

void Stack::push(int _new_item)
{
	StackNode* tmporary = new StackNode(_new_item, Top);
	Top = tmporary;
}

void Stack::delFirst()
{
	StackNode* victim = Top;
	Top = Top->next;
	delete victim;
}

int Stack::pop()
{
	//StackNode* temp = top;
	//int return_value = temp->item;
	//top = top->next;
	//delete temp;
	//return return_value;
	if (empty()) throw "Stack is empty.\n";
	int return_value = Top->item;
	delFirst();
	return return_value;
	
}

void Stack::clear()
{
	while (!empty())
	{
		this->delFirst();
	}
}


size_t Stack::size()
{
	if (empty()) return 0;
	size_t counter = 1;
	StackNode* current = Top;
	while (current->next != nullptr )
	{
		current = current->next;
		++counter;
	}
	return counter;
}

void Stack::printStack()
{
	StackNode* current = Top;
	while (current != nullptr)
	{
		std::cout << current->item << '\n';
		current = current->next;
	}
}

int Stack::top()
{
	return Top->item;
}

bool Stack::empty()
{
	return (Top == nullptr);
}
