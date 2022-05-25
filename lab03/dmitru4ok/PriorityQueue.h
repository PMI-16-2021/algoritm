#pragma once
#include "List.h"


template<typename T>
class PriorityQueue //template params: <Type>.             
{                   //e.g.PriorityQueue<double> A;

private:
	List<T> object; //container (default = List) 

public:

	PriorityQueue() : object(List<T>()) {}
	~PriorityQueue() {}

	void enqueue(T elem, int prior);                 //add ListNode with the element to the Queue   - may be both const and O(n)!!!
	T dequeue();                                     //remove ListNode and return value             - const
	const T& top()const;                             //check value in the top ListNode              - const
	void print()const;                               //print all values                             - O(n)!!!
	bool isEmpty()const { return object.isEmpty(); } //check if there are any nodes                 - const      
	int size()const { return object.getSize(); }     //get size of List                             - const
	void clear();                                    //remove all nodes                             - O(n)!!!
};

//add ListNode with the element to the Queue
template<typename T>
void PriorityQueue<T>::enqueue(T elem, int prior)     //prior 0 - MAX; 1,2,3,4 ...... bigger - lower
{
	if (prior < 0)                                    // prior >= only 0
	{
		throw"Invalid priority";
	}
	if (isEmpty())                                   //if Queue is empty => addFront
	{
		object.addFront(elem, prior); 
		return;
	}

	if (prior < object.top()->field.priority)        //if prior is bigger than in top of Container =>
	{
		object.addFront(elem, prior);                //add new ListNode as head
		return;
	}

	if (prior >= object.end()->field.priority)      //if prior is less than in the tail =>
	{
		object.addBack(elem, prior);                // add new ListNode as tail
		return;
	}
	else                                             //if prior is < than in top, but bigger than in tail
	{
		ListNode<T>* temp = object.top();           //temp = head of list
		while (prior >= temp->next->field.priority) //find border of priorities 
		{                                           //(find as temp ptr to ListNode)
			temp = temp->next;                      //(move while is >=)
		}
		object.addAfter(elem, prior, temp);         //add AFTER specific found ListNode
		temp = nullptr;                             //temp doestt point
		return;
	}
}

//print all values
template<typename T>
void PriorityQueue<T>::print() const             
{
	std::cout << "PRIORITY QUEUE: \n"; //message
	object.printList();                //print List
	std::cout << '\n';                 //newline
}

//remove all nodes
template<typename T>
void PriorityQueue<T>::clear()
{
	object.clear();                    //clear List
}

//remove ListNode and return value
template<typename T>
T PriorityQueue<T>::dequeue()
{
	if (isEmpty())  //nothing to dequeue => exception
	{
		throw "The Queue is empty: nothing to deQueue!\n";
	}
	T return_val = object.top()->field.value; //get value
	object.delFirst();                        //remove first node
	return return_val;                        //return
}

//check value in the top ListNode
template<typename T>
const T& PriorityQueue<T>::top() const       
{ 
	if (isEmpty())                    //nothing at top
	{
		throw "The Queue is empty: nothing to peek!\n";
	}
	return object.top()->field.value; //get value
}
