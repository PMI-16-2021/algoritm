#pragma once
#include <iostream>

template <typename T>
struct ListNode {
	T value;
	ListNode<T>* next;
	ListNode(T val, ListNode<T>* nex);
	ListNode(T val);
};

template<typename T>
ListNode<T>::ListNode(T val, ListNode<T>* nex) : value(value), next(nex) {}

template<typename T>
ListNode<T>::ListNode(T val) : value(val), next(nullptr) {}

template <typename T>
class List {
private:
	ListNode<T>* first;
	ListNode<T>* last;

public:
	List();

	~List();
	int size();
	void addBack(T);
	void addFront(T);
	void print();
	bool isEmpty();
	void clear();
	ListNode<T>* move(int ind);
	ListNode<T>* empty(int ind);
	ListNode<T>* deleteFirst();
	ListNode<T>* First();
	ListNode<T>* Last();
};

template<typename T>
List<T>::List() : first(nullptr), last(nullptr) {};

template<typename T>
List<T>::~List() {
	clear();
}

template<typename T>
int List<T>::size() {
	int count = 0;
	ListNode<T>* local = first;
	while (local != nullptr) {
		local = local->next;
		++count;
	}
	return count;
}

template<typename T>
void List<T>::addBack(T val) {
	ListNode<T>* local = new ListNode<T>(val);
	if (first == nullptr) {
		first = last = local;
	}
	last->next = local;
	last = local;
	local = nullptr;
}

template<typename T>
void List<T>::addFront(T val) {
	ListNode<T>* local = new ListNode<T>(val, first);
	if (first == nullptr) {
		last = local;
	}
	first = local;
	local = nullptr;
}

template<typename T>
void List<T>::print() {
	ListNode<T>* local = first;
	while (local != nullptr) {
		std::cout << local->value << '\t';
		local = local->next;
	}
}

template<typename T>
bool List<T>::isEmpty() {
	return first == nullptr;
}

template<typename T>
void List<T>::clear() {
	while (first != nullptr) {
		int i = 0;
		empty(i);
		++i;
	}
}

template<typename T>
ListNode<T>* List<T>::empty(int ind) {
	if (first == nullptr) {
		std::cout << "List is empty";
	}
	if ((ind < 0) || (ind >= size())) {
		std::cout <<  "Index is invalid";
	}
	if (ind == 0) {
		ListNode<T>* local = first;
		first = first->next;
		return local;
		delete local;
	}
	else {
		ListNode<T>* local = move(ind - 1);
		ListNode<T>* victim = local->next;
		local->next = victim->next;
		return victim;
		delete victim;
	}
}

template<typename T>
ListNode<T>* List<T>::move(int ind) {
	ListNode<T>* local = first;
	for (int i = 0; i < ind; ++i) {
		local = local->next;
	}
	return local;
}

template<typename T>
ListNode<T>* List<T>::deleteFirst() {
	return empty(0);
}

template<typename T>
ListNode<T>* List<T>::First() {
	return first;
}

template<typename T>
ListNode<T>* List<T>::Last() {
	return last;
}