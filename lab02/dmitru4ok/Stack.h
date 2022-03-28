#pragma once
#include <iostream>

template<typename T>
struct StackNode
{
	T item;
	StackNode* next;
	StackNode(T _item, StackNode* _next = nullptr);

};

template<typename T>
class Stack
{
private:
	StackNode<T>* Top;
	void delFirst();
public:
	~Stack(); // uses empty
	Stack<T>();
	Stack<T>(T item_to_create);

	void push(T); //add new node with paraeter value
	void clear(); //clear all nodes
	T pop(); // return item and remove first node
	bool empty() const; // check if is empty
	size_t size() const; //count number of list structures
	void printStack() const;//print all elements
	T top() const; //watch top element 
	void emplace(T&); //== push, but adds the object, not a copy of it
	void swap(Stack<T>&);//swap Top pointers of stacks => swap Memory 
};


template <typename T>
Stack<T>::~Stack()
{
	this->clear();
}

template<typename T>
Stack<T>::Stack(T item_to_create)
{
	Top = new StackNode<T>(item_to_create, nullptr);
}


template<typename T>
void Stack<T>::delFirst()
{
	if (empty()) return;
	StackNode<T>* victim = Top;
	Top = Top->next;
	delete victim;
}
template<typename T>
T Stack<T>::pop()
{
	if (empty()) throw "Stack is empty.\n";
	T return_value = Top->item;
	delFirst();
	return return_value;
}

template <typename T>
StackNode<T>::StackNode(T _item, StackNode* _next)
{
	item = _item;
	next = _next;
}

template <typename T>
Stack<T>::Stack()
{
	Top = nullptr;
}
template<typename T>
bool Stack<T>::empty() const
{
	return (Top == nullptr);
}


template <typename T>
void Stack<T>::clear()
{
	while (!empty())
	{
		this->delFirst();
	}
}

template <typename T>
size_t Stack<T>::size() const
{
	if (empty()) return 0;
	size_t counter = 1;
	StackNode<T>* current = Top;
	while (current->next != nullptr)
	{
		current = current->next;
		++counter;
	}
	return counter;
}


template <typename T>
void Stack<T>::printStack() const
{
	if (empty())
	{
		std::cout << "This Stack is empty.\n";
		return;
	}
	std::cout << "My Stack: \n";
	StackNode<T>* current = Top;
	while (current != nullptr)
	{
		std::cout << current->item << ' ';
		current = current->next;
	}
}

template <typename T>
T Stack<T>::top() const
{
	if (empty()) throw "Stack is empty.\n";
	return Top->item;
}

template <typename T>
void Stack<T>::push(T _new_item)
{
	StackNode<T>* tmporary = new StackNode<T>(_new_item, Top);
	Top = tmporary;
}

template<typename T>
inline void Stack<T>::emplace(T& add_elem)
{
	StackNode<T>* temp = new StackNode<T>(add_elem, Top);
	Top = temp;
}

template<typename T>
inline void Stack<T>::swap(Stack<T>& second_stack)
{
	StackNode<T>* temporary = this->Top;
	this->Top = second_stack.Top;
	second_stack.Top = temporary;
	temporary = nullptr;
}

