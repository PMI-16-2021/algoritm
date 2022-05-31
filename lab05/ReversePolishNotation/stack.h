#pragma once
#include <iostream>

template <typename T>
struct Node
{
	T myVal;
	Node* link;
	Node(T m_value, Node* m_link);
};

template<typename T>
Node<T>::Node(T m_value, Node* m_link) : myVal(m_value), link(m_link)
{}

template<typename T>
class Stack
{
private:
	Node<T>* m_top;
public:
	Stack<T>();
	Stack<T>(T num);
	~Stack<T>();
	bool isEmpty();
	void push(T num);
	T pop();
	int size();
	T top();
	void empty();
};

template<typename T>
Stack<T>::Stack() : m_top(nullptr)
{}

template<typename T>
Stack<T>::Stack(T num)
{
	m_top = new Node<T>(num, nullptr);
}

template<typename T>
Stack<T>::~Stack()
{
	empty();
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return m_top == nullptr;
}

template<typename T>
void Stack<T>::push(T num)
{
	Node<T>* elem = new Node<T>(num, m_top);
	m_top = elem;
}

template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		throw "Stack is empty";
	}
	else
	{
		Node<T>* temp;
		T item;
		item = m_top->myVal;
		temp = m_top;
		m_top = m_top->link;
		delete temp;
		return item;
	}
}

template<typename T>
int Stack<T>::size()
{
	if (isEmpty())
	{
		return 0;
	}
	else
	{
		Node<T>* temp = m_top;
		int size = 0;
		while (temp != nullptr)
		{
			++size;
			temp = temp->link;
		}
		delete temp;
		return size;
	}
}

template<typename T>
T Stack<T>::top()
{
	if (isEmpty())
	{
		throw "Stack is empty.";
	}
	else
	{
		return m_top->myVal;
	}
}

template<typename T>
void Stack<T>::empty()
{
	Node<T>* temp_top = m_top;
	Node<T>* temp;
	while (temp_top != nullptr)
	{
		temp = temp_top;
		temp_top = temp_top->link;
		delete temp;
	}
	m_top = nullptr;
}

bool isOperator(char m_operator);
bool isNum(char m_num);
int priority(char m_priority);
std::string infixToPostfix(std::string expression);
double action(std::string expression);