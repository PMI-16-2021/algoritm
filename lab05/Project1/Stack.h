#pragma once
#include <iostream>

template<typename T>
struct StackNode //Node for List
{
	T item;
	StackNode* next;
	StackNode(T _item, StackNode* _next = nullptr);
};

template <typename T>
StackNode<T>::StackNode(T _item, StackNode* _next)
{
	item = _item; //value
	next = _next; //pointer to next one
}

template<typename T>
class Stack
{
private:
	StackNode<T>* Top;          //main pointer
	void delFirst();            //private method to delete first StackNode 
public:
	~Stack();                   // uses empty() method
	Stack<T>();                 //default(empty)
	Stack<T>(T item_to_create); //parameter

	void push(T);               //add new node with parameter value
	void clear();               //clear all nodes
	T pop();                    // return item and remove first node
	bool empty() const;         // check if is empty
	int size() const;           //count number of list structures
	void printStack() const;    //print all elements
	T top() const;              //watch top element 
	void emplace(T&);           //== push, but adds the object, not a copy of it
	void swap(Stack<T>&);       //swap Top pointers of stacks => swap Memory
};

template <typename T>
Stack<T>::~Stack()
{
	this->clear();             //delete all StackNodes
}

template<typename T>
Stack<T>::Stack(T item_to_create)
{
	Top = new StackNode<T>(item_to_create, nullptr); //creating first StackNode with param
}

template<typename T>
void Stack<T>::delFirst()
{
	if (empty()) return;         //nothing to delete
	StackNode<T>* victim = Top;  //set victim
	Top = Top->next;             // move Top pointer tto the next
	delete victim;               //delete victim (previous for Top)
}

template<typename T>
T Stack<T>::pop()
{
	if (empty()) throw "Stack is empty.\n";//exception if empty
	T return_value = Top->item;            //save value to variable
	delFirst();                            //delete its StackNode
	return return_value;                   //return
}

template <typename T>
Stack<T>::Stack()            //default empty stack 
{
	Top = nullptr;
}
template<typename T>
bool Stack<T>::empty() const //if Top == nullptr then empty
{
	return (Top == nullptr);
}

template <typename T>
void Stack<T>::clear()
{
	while (!empty())
	{
		this->delFirst();  //while Top != nullptr delete StackNode
	}
}

template <typename T>
int Stack<T>::size() const
{
	if (empty()) return 0;  //if empty size == 0;
	size_t counter = 1;     //Top already points at Node if not empty, so that = 1;
	StackNode<T>* current = Top; //temporary poiter
	while (current->next != nullptr) //while StackNode's field next != null ptr
	{
		current = current->next;     // move forward
		++counter;                   // and count nodes
	}
	return counter;
}

template <typename T>
void Stack<T>::printStack() const
{
	if (empty())         //nothing to print
	{
		std::cout << "This Stack is empty.\n";
		return;
	}
	std::cout << "My Stack: \n";
	StackNode<T>* current = Top;  //temporary pointer
	while (current != nullptr)    // while there is no nodes
	{
		std::cout << current->item << ' '; //print inem
		current = current->next;           //move forward
	}
}

template <typename T>
T Stack<T>::top() const
{
	if (empty()) throw "Stack is empty.\n";//nothing to access
	return Top->item;                      //return first val wi NO DELETING NODE
}

template <typename T>
void Stack<T>::push(T _new_item)
{                                                             //creating new StackNode that points to Top 
	StackNode<T>* tmporary = new StackNode<T>(_new_item, Top);//and has item of copy of parameter
	Top = tmporary;
}

template<typename T>
inline void Stack<T>::emplace(T& add_elem)
{                                                         //creating new StackNode that points to Top
	StackNode<T>* temp = new StackNode<T>(add_elem, Top); //and has item of parameter ITSELF &!!!
	Top = temp;                                           //now Top points at this node
}

template<typename T>
inline void Stack<T>::swap(Stack<T>& second_stack)       //swap to Stacks
{
	StackNode<T>* temporary = this->Top;                 //temporary pointer to memory of first
	this->Top = second_stack.Top;                        //first = second
	second_stack.Top = temporary;                        //second = temporary(first)
}
