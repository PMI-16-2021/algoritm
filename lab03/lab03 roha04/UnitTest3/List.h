#pragma once
#include <iostream>

template<typename T>
struct Pair
{
	T value;
	int priority;
	Pair(T val = T(), int prio = 0) : value(val), priority(prio) {}
	Pair& operator =(const Pair& other);
};


template<typename T>
Pair<T>& Pair<T>::operator=(const Pair<T>& other)
{
	this->priority = other.priority;
	this->value = other.value;
	return *this;
}


template<typename T>
struct ListNode
{
	Pair<T> field;                                       
	ListNode<T>* next;                                 

	ListNode(T data, int prio, ListNode<T>* next_ = nullptr) : next(next_)
	{
		field = Pair<T>(data, (prio >= 0) ? prio : 0);
	}                                                  
};


template<typename T> 
class List
{
private:

	ListNode<T>* head;                               
	ListNode<T>* tail;                                
	int size;                                        
public:
	List() : head(nullptr), tail(nullptr), size(0) {}
	~List() { this->clear(); }                        

	int getSize() const { return size; }                                                      
	bool isEmpty()const { return head == nullptr; }                                            
	void clear();                                                 
	void addFront(T A, int prio);                                                          
	void addBack(T A, int prio);                                                              
	void addAfter(T A, int prio, ListNode<T>* node); 
	void printList()const;                           
	ListNode<T>* top()const { return head; }         
	ListNode<T>* end()const { return tail; }         
	void deleteFirst();                                
	void deleteLast();                                                                     
};


template<typename T>
inline void List<T>::clear()
{
	while (size > 0)      
		this->deleteFirst();  
}


template<typename T>
void List<T>::addFront(T data, int prio)
{                                                             
	ListNode<T>* temp = new ListNode<T>(data, prio, head);

	if (isEmpty()) 
	{
		tail = temp; 
	}
	head = temp;     
	temp = nullptr;  
	++size;            
}


template<typename T>
void List<T>::deleteLast()
{
	if (isEmpty()) 
	{
		return;
	}
	if (size == 1) 
	{
		delFirst(); 
	}
	else
	{
		ListNode<T>* victim = tail; 
		ListNode<T>* temp = head;   
		while (temp->next != victim)
		{
			temp = temp->next;      
		}
		tail = temp;                
		tail->next = nullptr;       
		delete victim;              
	}
	--size;                      
}


template<typename T>
void List<T>::addBack(T A, int prio)
{
	ListNode<T>* temp = new ListNode<T>(A, prio); 
	if (isEmpty())                                 
	{                                              
		head = temp;                               
		tail = temp;                              
		temp = nullptr;                          
		++size;                                  
		return;
	}
	else                                          
	{
		tail->next = temp;                                         
		tail = temp;                            
		++size;                                
	}

}


template<typename T>
void List<T>::addAfter(T A, int prior, ListNode<T>* node)
{
	ListNode<T>* temp = node->next;                 
	node->next = new ListNode<T>(A, prior, temp);  
	temp = nullptr;                                 
	++size;                                        
}


template<typename T>
void List<T>::printList() const
{
	if (isEmpty())     
	{
		std::cout << "This is empty.\n";
		return;
	}

	ListNode<T>* current = head;                                              
	int counter = 1;                                                                 
	while (current != nullptr)                                               
	{
		std::cout <<  counter  << current->field.value << " \n"; 
		current = current->next;                                             
		++counter;                                                           
	}
	std::cout << '\n';
}


template<typename T>
void List<T>::deleteFirst()
{
	if (isEmpty())              
	{
		return;
	}
	ListNode<T>* victim = head; 
	head = head->next;          
	delete victim;             
	--size;                    
}



