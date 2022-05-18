#pragma once
#include<iostream>

template<typename T>
struct Node {
	T value;
	Node<T>* next;
	Node(T value);
	Node(T value, Node<T>* next);
};

template<typename T>
Node<T>::Node(T value)
	: value(value), next(nullptr)
{}

template<typename T>
Node<T>::Node(T value, Node<T>* next)
	: value(value), next(next)
{}

template<typename T>
class List {
private:
	Node<T>* head;
	Node<T>* tail;
public:
	List();
	List(Node<T>* head, Node<T>* tail);
	~List();
	Node<T>* front();
	Node<T>* back();
	int size();
	bool isEmpty();
	void insert(T value, int position);
	void pushFront(T value);
	void pushBack(T value);
	T popBack();
	T popFront();
	void print();
	void del();
};

template<typename T>
List<T>::List()
	: head(nullptr), tail(nullptr)
{}

template<typename T>
List<T>::List(Node<T>* head, Node<T>* tail)
	: head(head), tail(tail)
{}

template<typename T>
List<T>::~List() {
	del();
}

template<typename T>
Node<T>* List<T>::front() {
	return head;
}

template<typename T>
Node<T>* List<T>::back() {
	return tail;
}

template<typename T>
int List<T>::size() {
	int counter = 0;
	Node<T>* temp = head;
	while (temp != nullptr) {
		temp = temp->next;
		++counter;
	}
	return counter;
}

template<typename T>
bool List<T>::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

template<typename T>
void List<T>::insert(T value, int position) {
	Node<T>* node = new Node<T>(value);
	Node<T>* curr = head;
	while (position > 1 && curr != tail) {
		curr = curr->next;
		--position;
	}
	if (curr == nullptr) {
		std::cout << "Position not found";
	}
	else if (curr->next == nullptr) {
		// if position is the last node, insert right after it 
		curr->next = node;
		tail = node;
	}
	else {
		// insert between position and item next to position
		Node<T>* next = curr->next;
		curr->next = node;
		node->next = next;
	}
}

template<typename T>
void List<T>::pushFront(T value) {
	Node<T>* node = new Node<T>(value);
	if (head == nullptr) {
		head = tail = node;
	}
	else {
		node->next = head;
		head = node;
		node = nullptr;
	}
}

template<typename T>
void List<T>::pushBack(T value) {
	Node<T>* node = new Node<T>(value);
	if (head == nullptr) {
		head = tail = node;
	}
	else {
		tail->next = node;
		tail = tail->next;
	}
}

template<typename T>
T List<T>::popFront() {
	if (head != nullptr) {
		T item = head->value;
		head = head->next;
		return item;
	}
}

template<typename T>
T List<T>::popBack() {
	Node<T>* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	T item = tail->value;
	delete tail;
	if (head == tail) {
		head = nullptr;
		tail = nullptr;
	}
	else {
		tail = temp;
		tail->next = nullptr;
	}
	return item;
}

template<typename T>
void List<T>::print() {
	if (head == nullptr) {
		std::cout << "List is empty";
	}
	else {
		Node<T>* node = head;
		while (node != nullptr) {
			std::cout << node->value << "\n";
			node = node->next;
		}
	}
}

template<typename T>
void List<T>::del() {
	Node<T>* node = nullptr;
	while (head != nullptr) {
		node = head;
		head = head->next;
		delete node;
	}
}
