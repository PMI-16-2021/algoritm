#pragma once
#include <iostream>
template<typename T>
struct Pair
{
	T value;
	int priority; //0 - MAX; 1,2,3,4 ...... bigger - lower
	Pair(T val = T(), int prior = 0): value(val), priority(prior){}
};

template<typename T>
struct ListNode
{
	T field; //here - holds Pair structures (must have priority and value fields)
	ListNode<T>* next;
	ListNode(T _field,  ListNode<T>* _next = nullptr) : field(_field), next(_next) { /*std::cout << "LIST NODE OF PAIRS OF INT.\n"; */ }
};


template<template<typename T> class Holder, typename T>
class List
{
private:
	
	ListNode<Holder<T>>* head;
	ListNode<Holder<T>>* tail;
public:
	List(): head(nullptr), tail(nullptr){ /*std::cout << "LIST OF LIST NODES OF PAIRS OF INT.\n"; */ }
	
	~List() // uses clear method
	{
		this->clear(); 
	}

	bool isEmpty()const { return head == nullptr; }//check if empty

	void clear() //while head not empty delete ListNodes
	{
		while (!isEmpty())
		{
			this->delFirst();  
		}
	}

	void addFront(Holder<T> A) //add as first node
	{
		ListNode<Holder<T>>* tmporary = new ListNode<Holder<T>>(A, head);
		
		if (isEmpty())
		{
			tail = tmporary;
		}
		head = tmporary;
		tmporary = nullptr;
	}

	void addBack(Holder<T> A) //add as last node
	{
		ListNode<Holder<T>>* temp = new ListNode<Holder<T>>(A);
		if (isEmpty())
		{
			head = temp;
			tail = temp;
			temp = nullptr;
			return;
		}
		tail->next = temp;
		tail = temp;
	}

	void add(Holder<T> A, ListNode<Holder<T>>* node) //add AFTER specific node (mainly used in Prior Queue class)
	{
		ListNode<Holder<T>>* temp = node->next;
		node->next = new ListNode<Holder<T>>(A, temp);
		temp = nullptr;
	}

	int size()const //return number of elements
	{
		if (isEmpty())
		{
			return 0;
		}
		int return_size = 1;
		ListNode<Holder<T>>* temp = head;
		while (temp != tail)
		{
			temp = temp->next;
			++return_size;
		}
		return return_size;
	}

	void printList()const //prints value field from all Holders ListNodes
	{
		if (isEmpty()) //nothing to print        
		{
			std::cout << "This is empty.\n";
			return;
		}
		
		ListNode<Holder<T>>* current = head; //temp pointer
		int counter = 1;  //for numeration         
		while (current != nullptr)    
		{
			std::cout << '#' << counter << ": " << current->field.value << " \n"; //print inem
			current = current->next;  
			++counter; 
		}
		std::cout << '\n';
	}

	ListNode<Holder<T>>* top()const //return head
	{
		return head;
	}

	ListNode<Holder<T>>* end()const //return last node
	{
		return tail;
	}
	
	void delFirst() //delete first node
	{
		if (isEmpty()) //nothing to delete
		{
			return;
		}
		ListNode<Holder<T>>* victim = head;  //set victim
		head = head->next;                   // move head pointer to the next
		delete victim;
	}

	void delLast() //delete last Node
	{
		if (isEmpty())
		{
			return;
		}
		ListNode<Holder<T>>* victim = tail;
		ListNode<Holder<T>>* temp = head;
		while (temp->next != victim)
		{
			temp = temp->next;
		}
		tail = temp;
		tail->next = nullptr;
		delete victim;
	}
};







