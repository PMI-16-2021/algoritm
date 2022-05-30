#pragma once
#include "List.h"


template<typename T>
class PriorityQueue          
{                   

private:
	List<T> object; 

public:

	PriorityQueue() : object(List<T>()) {}
	~PriorityQueue() {}

	void enqueue(T el, int prio);                 
	T dequeue();                                     
	const T& top()const;                           
	void print()const;                              
	bool isEmpty()const
	{ 
		return object.isEmpty(); 
	}      
	int size()const
	{
		return object.getSize();
	}   
	void clear();                                                   
};


template<typename T>
void PriorityQueue<T>::enqueue(T el, int prio)    
{
	if (prio< 0)                                 
	{
		throw"Incorrect priority";
	}
	if (isEmpty())                                 
	{
		object.addFront(el, prio);
		return;
	}

	if (prio < object.top()->field.priority)       
	{
		object.addFront(el, prio);              
		return;
	}

	if (prio >= object.end()->field.priority)      
	{
		object.addBack(el, prio);               
		return;
	}
	else                                            
	{
		ListNode<T>* temp = object.top();           
		while (prio >= temp->next->field.priority) 
		{                                           
			temp = temp->next;                     
		}
		object.addAfter(el, prio, temp);        
		temp = nullptr;                            
		return;
	}
}

template<typename T>
void PriorityQueue<T>::print() const
{
	std::cout << " QUEUE: \n"; 
	object.printList();                
	std::cout << '\n';                
}

template<typename T>
void PriorityQueue<T>::clear()
{
	object.clear();                   
}

template<typename T>
T PriorityQueue<T>::dequeue()
{
	if (isEmpty())  
	{
		throw " Queue's empty\n";
	}
	T return_val = object.top()->field.value; 
	object.deleteFirst();                       
	return return_val;                       
}


template<typename T>
const T& PriorityQueue<T>::top() const
{
	if (isEmpty())                   
	{
		throw "Queue's empty\n";
	}
	return object.top()->field.value;
}