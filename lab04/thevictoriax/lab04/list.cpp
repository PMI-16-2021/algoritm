#include <iostream>
#include "list.h"
using namespace std;

List::List()
{
	head = new Element;
	head->next = nullptr;
	size = 0;
}

List::~List()
{
	Element* a = head;
	Element* b = head;
	while (b)
	{
		a = b;
		b = a->next;
		if (a)
		{
			delete b;
		}
	}
}

void List::add(Element* newElem)
{
	if (!head->next)
	{
		head->next = newElem;
		++size;
		return;
	}
	Element* a = head;
	Element* b = head;
	while (b)
	{
		a = b;
		b = a->next;
	}
	a->next = newElem;
	newElem->next = nullptr;
	++size;
}

Element* List::getElem(std::string elemKey)
{
	Element* a = head;
	Element* b = head;
	while (b)
	{
		a = b;
		if ((a != head) && (a->key == elemKey))
		{
			return a;
			b = a->next;
		}
	}
	return nullptr;
}

bool List::pop(std::string elemKey)
{
	if (!head->next)
	{
		return false;
	}
	Element* a = head;
	Element* b = head;
	while (b)
	{
		if (b->key == elemKey)
		{
			a->next = b->next;
			delete b;
			--size;
			return true;
		}
		a = b;
		b = a->next;
	}
	return false;
}

int List::getSize()
{
	return size;
}

void List::printList()
{
	if (size == 0)
	{
		cout << "Empty list\n";
	}
	Element* a = head;
	Element* b = head;
	while(b)
	{
		a = b;
		if (a != head)
		{
			cout << a->value << ", " << a->key << "\n";
			if (a->next)
			{
				cout << ", \n";
			}
			else
			{
				cout << " \n";
			}
		}
		b = a->next;
	}
	cout << "\n\n";
}