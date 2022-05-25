#pragma once
#include "list.h"

template<typename T>
struct Pair {
	T val;
	int priority;
	Pair();
	Pair(T val, int priority);
	~Pair();
	void writeTo(std::ostream& out) const;
};

template<typename T>
Pair<T>::Pair()
	: val(), priority(0)
{}

template<typename T>
Pair<T>::Pair(T val, int priority)
	: val(val), priority(priority)
{}

template<typename T>
Pair<T>::~Pair()
{}

template<typename T>
void Pair<T>::writeTo(std::ostream& out) const {
	out << val;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Pair<T>& P) {
	P.writeTo(out);
	return out;
}

template<typename T>
class PriorQueue {
private:
	List<Pair<T>> elem;
public:
	PriorQueue();
	~PriorQueue();
	int size();
	T top();
	bool isEmpty();
	void enqueue(T val, int prior);
	T dequeue();
	void print();
};

template<typename T>
PriorQueue<T>::PriorQueue()
{}

template<typename T>
PriorQueue<T>::~PriorQueue() {
	elem.del();
}

template<typename T>
int PriorQueue<T>::size() {
	return elem.size();
}

template<typename T>
T PriorQueue<T>::top() {
	return elem.front()->value.val;
}

template<typename T>
bool PriorQueue<T>::isEmpty() {
	return elem.isEmpty();
}

template<typename T>
void PriorQueue<T>::enqueue(T val, int prior) {
	if (elem.isEmpty()) {
		elem.pushBack(Pair<T>(val, prior));
	}
	else if (prior < elem.front()->value.priority) {
		elem.pushFront(Pair<T>(val, prior));
	}
	else if (prior > elem.back()->value.priority) {
		elem.pushBack(Pair<T>(val, prior));
	}
	else {
		Node<Pair<T>>* temp = elem.front();
		int pos = 0;
		while (temp->next != nullptr && temp->value.priority <= prior) {
			temp = temp->next;
			++pos;
		}
		elem.insert(Pair<T>(val, prior), pos);
		temp = nullptr;
	}
}

template<typename T>
T PriorQueue<T>::dequeue() {
	return elem.popFront().val;
}

template<typename T>
void PriorQueue<T>::print() {
	return elem.print();
}