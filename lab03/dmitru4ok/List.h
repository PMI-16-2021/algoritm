#pragma once
#include <iostream>
template<typename T>
struct Pair
{
	T value;
	int priority; //0 - MAX; 1,2,3,4 ...... bigger - lower
<<<<<<< Updated upstream
	Pair(T val = T(), int prior = 0): value(val), priority(prior){}
=======
	Pair(T val = T(), int prior = 0) : value(val), priority(prior) {}
	Pair& operator =(const Pair& other)
	{
		this->priority = other.priority;
		this->value = other.value;
		return *this;
	}
>>>>>>> Stashed changes
};

template<typename T>
struct ListNode
{
<<<<<<< Updated upstream
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
=======
	Pair<T> field; //here - holds Pair structures (must have priority and value fields)
	ListNode<T>* next;
	ListNode(T data, int prior,  ListNode<T>* _next = nullptr): next(_next)
	{
		field = Pair<T>(data, (prior > 0) ? prior : 0);
	}
};


template<typename T>//List<Pair,int> A;
class List
{
private:

	ListNode<T>* head;
	ListNode<T>* tail;
public:
	List() : head(nullptr), tail(nullptr) { /*std::cout << "LIST OF LIST NODES OF PAIRS OF INT.\n"; */ }

	~List() // uses clear method
	{
		this->clear();
>>>>>>> Stashed changes
	}

	bool isEmpty()const { return head == nullptr; }//check if empty

<<<<<<< Updated upstream
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
		
=======
	void clear(); //while head not empty delete ListNodes
	

	void addFront(T A, int prior) //add as first node
	{
		ListNode<T>* tmporary = new ListNode<T>(A, prior, head);

>>>>>>> Stashed changes
		if (isEmpty())
		{
			tail = tmporary;
		}
		head = tmporary;
		tmporary = nullptr;
	}

<<<<<<< Updated upstream
	void addBack(Holder<T> A) //add as last node
	{
		ListNode<Holder<T>>* temp = new ListNode<Holder<T>>(A);
=======
	void addBack(T A, int prior) //add as last node
	{
		ListNode<T>* temp = new ListNode<T>(A, prior);
>>>>>>> Stashed changes
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

<<<<<<< Updated upstream
	void add(Holder<T> A, ListNode<Holder<T>>* node) //add AFTER specific node (mainly used in Prior Queue class)
	{
		ListNode<Holder<T>>* temp = node->next;
		node->next = new ListNode<Holder<T>>(A, temp);
=======
	void add(T A, int prior, ListNode<T>* node) //add AFTER specific node (mainly used in Prior Queue class)
	{
		
		ListNode<T>* temp = node->next;
		node->next = new ListNode<T>(A, prior, temp);
>>>>>>> Stashed changes
		temp = nullptr;
	}

	int size()const //return number of elements
	{
		if (isEmpty())
		{
			return 0;
		}
		int return_size = 1;
<<<<<<< Updated upstream
		ListNode<Holder<T>>* temp = head;
=======
		ListNode<T>* temp = head;
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
		
		ListNode<Holder<T>>* current = head; //temp pointer
		int counter = 1;  //for numeration         
		while (current != nullptr)    
		{
			std::cout << '#' << counter << ": " << current->field.value << " \n"; //print inem
			current = current->next;  
			++counter; 
=======

		ListNode<T>* current = head; //temp pointer
		int counter = 1;  //for numeration         
		while (current != nullptr)
		{
			std::cout << '#' << counter << ": " << current->field.value << " \n"; //print inem
			current = current->next;
			++counter;
>>>>>>> Stashed changes
		}
		std::cout << '\n';
	}

<<<<<<< Updated upstream
	ListNode<Holder<T>>* top()const //return head
=======
	ListNode<T>* top()const //return head
>>>>>>> Stashed changes
	{
		return head;
	}

<<<<<<< Updated upstream
	ListNode<Holder<T>>* end()const //return last node
	{
		return tail;
	}
	
=======
	ListNode<T>* end()const //return last node
	{
		return tail;
	}

>>>>>>> Stashed changes
	void delFirst() //delete first node
	{
		if (isEmpty()) //nothing to delete
		{
			return;
		}
<<<<<<< Updated upstream
		ListNode<Holder<T>>* victim = head;  //set victim
=======
		ListNode<T>* victim = head;  //set victim
>>>>>>> Stashed changes
		head = head->next;                   // move head pointer to the next
		delete victim;
	}

	void delLast() //delete last Node
	{
		if (isEmpty())
		{
			return;
		}
<<<<<<< Updated upstream
		ListNode<Holder<T>>* victim = tail;
		ListNode<Holder<T>>* temp = head;
=======
		ListNode<Pair<T>>* victim = tail;
		ListNode<Pair<T>>* temp = head;
>>>>>>> Stashed changes
		while (temp->next != victim)
		{
			temp = temp->next;
		}
		tail = temp;
		tail->next = nullptr;
		delete victim;
	}
};

<<<<<<< Updated upstream






=======
template<typename T>
inline void List<T>::clear()
{
	while (!isEmpty())
	{
		this->delFirst();
	}
}
>>>>>>> Stashed changes
