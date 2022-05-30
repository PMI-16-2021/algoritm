#pragma once
#include <iostream>
#include <string>
using namespace std;

template <typename T>
struct Element
{
	T value;
	Element<T>* next;
	Element(T val, Element<T>* nxt);
	Element(T val);
};

template <typename T>
Element<T>::Element(T val, Element<T>* nxt) : value(val), next(nxt)
{

}

template <typename T>
Element<T>::Element(T val) : value(val), next(nullptr)
{

}

template <typename T>
class List
{
private:
	Element<T>* head;
	Element<T>* tail;
	
public:
	List();
	~List();
	void clear();
	Element<T>* remove(int);
	Element<T>* move(int);
	void addBack(T);
	void addFront(T);
	bool pop();
	int getSize();
	void printList();
	bool isEmpty();
	Element<T>* getHead();
	Element<T>* getTail();
	Element<T>* deleteHead();
};

template<typename T>
List<T>::List() : head(nullptr), tail(nullptr) 
{
}

template<typename T>
List<T>::~List() 
{
	clear();
}

template<typename T>
void List<T>::clear()
{
	while (head != nullptr)
	{
		int i = 0;
		remove(i);
		++i;
	}
}

template<typename T>
int List<T>::getSize()
{
	int num = 0;
	Element<T>* temp = head;
	while (temp != nullptr)
	{
		temp = temp->next;
		++num;
	}
	return num;
}

template<typename T>
Element<T>* List<T>::remove(int count)
{
	if (head == nullptr)
	{
		cout << "List is empty";
	}
	if ((count < 0) || (count >= getSize()))
	{
		cout << "Index is invalid";
	}
	if (count == 0)
	{
		Element<T>* temp = head;
		head = head->next;
		return temp;
		delete temp;
	}
	else
	{
		Element<T>* temp = move(count - 1);
		Element<T>* victim = temp->next;
		temp->next = victim->next;
		return victim;
		delete victim;
	}
}

template<typename T>
Element<T>* List<T>::move(int count)
{
	Element<T>* temp = head;
	for (int i = 0; i < count; ++i)
	{
		temp = temp->next;
	}
	return temp;
}

template<typename T>
void List<T>::addBack(T value)
{
	Element<T>* temp = new Element<T>(value);
	if (head == nullptr)
	{
		head = tail = temp;
	}
	tail->next = temp;
	tail = temp;
	temp = nullptr;
}

template<typename T>
void List<T>::addFront(T value)
{
	Element<T>* temp = new Element(value, head);
	if (head == nullptr)
	{
		tail = temp;
	}
	head = temp;
	temp = nullptr;
}

template<typename T>
void List<T>::printList()
{
	Element<T>* temp = head;
	while (temp != nullptr) 
	{
		cout << temp->value << "\n";
		temp = temp->next;
	}
}

template<typename T>
bool List<T>::isEmpty()
{
	return head == nullptr;
}

template<typename T>
Element<T>* List<T>::getHead()
{
	return head;
}

template<typename T>
Element<T>* List<T>::getTail()
{
	return tail;
}

template<typename T>
Element<T>* List<T>::deleteHead()
{
	return remove(0);
}
