#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct Node
{
	T value;
	Node* reference;
	Node(T value, Node* reference);
};

template<typename T>
Node<T>::Node(T value, Node* reference) :
	value(value), reference(reference) {}
template<typename T>
class Stack 
{
private:
	Node<T>* top;
public:
	Stack<T>();
	Stack<T>(T item);
	~Stack<T>();
	bool IsEmpty();
	void Push(T _new_item);
	T Pop();
	int Size();
	T Top();
	void Swap(Stack<T>& _stack);
	void emplace(T& add_elem);
	void Empty();
	void Print();
};

template<typename T>
Stack<T>::Stack()
{
	top = nullptr;
}

template<typename T>
Stack<T>::Stack(T item) 
{
	top = new Node<T>(item, nullptr);
}

template<typename T>
Stack<T>::~Stack() 
{
	Empty();
}

template<typename T>
bool Stack<T>::IsEmpty()
{
	return top == nullptr;
}

template<typename T>
void Stack<T>::Push(T _new_item)
{                                                          
	Node<T>* element = new Node<T>(_new_item, top);
	top = element;
}

template<typename T>
T Stack<T>::Pop()
{
	if (IsEmpty())
	{
		throw "Stack is empty";
	}
	else 
	{
		Node<T>* temp;
		T item;
		item = top->value;
		temp = top;
		top = top->reference;
		delete temp;
		return item;
	}
}

template<typename T>
int Stack<T>::Size()
{
	if (IsEmpty()) 
	{
		return 0;
	}
	else 
	{
		Node<T>* temp = top;
		int size = 0;
		while (temp != nullptr) 
		{
			++size;
			temp = temp->reference;
		}
		delete temp;
		return size;
	}
}

template<typename T>
void Stack<T>::emplace(T& add_elem)
{                                                        
	Node<T>* temp = new Node<T>(add_elem, Top); 
	Top = temp;                                         
}

template<typename T>
T Stack<T>::Top()
{
	if (IsEmpty()) throw "Stack is empty.";
	return top->value;
}

template<typename T>
void Stack<T>::Swap(Stack<T>& _stack)
{
	Node<T>* temp = top;
	top = _stack.top;
	_stack.top = temp;
}

template<typename T>
void Stack<T>::Print() 
{
	if (IsEmpty()) 
	{
		cout << "Stack is empty.";
	}
	else
	{
		Node<T>* temp = top;
		while (temp != nullptr) 
		{
			cout << temp->value << "; ";
			temp = temp->reference;
		}
	}
}

template<typename T>
void Stack<T>::Empty()
{
	Node<T>* temp_top = top;
	Node<T>* temp;
	while (temp_top != nullptr)
	{
		temp = temp_top;
		temp_top = temp_top->reference;
		delete temp;
	}
	top = nullptr;
}


