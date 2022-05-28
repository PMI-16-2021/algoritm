#pragma once
#include "list.h"

template <typename T>
struct Pair {
	T value_;
	int priority_;
	Pair();
	Pair(T value, int priority);
	~Pair();
	void print(std::ostream& out) const;
};

template <typename T>
Pair<T>::Pair() {
	value_ = 0;
	priority_ = 0;
}

template <typename T>
Pair<T>::Pair(T value, int priority) {
	value_ = value;
	priority_ = priority;
}

template <typename T>
Pair<T>::~Pair() {
}

template <typename T>
void Pair<T>::print(std::ostream& out) const {
	out << value_;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const Pair<T>& P) {
	P.print(out);
	return out;
}

template <typename T>
class PriorQueue {
private:
	List<Pair<T>> element_;
public:
	PriorQueue();
	~PriorQueue();

	int size() const;
	T top();
	void enqueue(T value, int priority);
	T dequeue();
	void print();
	void empty();
	bool isEmpty();
};

template <typename T>
PriorQueue<T>::PriorQueue() : element_() {
}

template <typename T>
PriorQueue<T>::~PriorQueue() {
}

template <typename T>
int PriorQueue<T>::size() const {
	return element_.size();
}

template <typename T>
T PriorQueue<T>::top() {
	if (isEmpty()) {
		throw "Queue is empty";
	}
	return element_.top()->value_.value_;
}

template <typename T>
void PriorQueue<T>::enqueue(T value, int priority) {
	if (element_.isEmpty()) {
		element_.addFront(Pair<T>(value, priority));
	}
	else if (priority < element_.top()->value_.priority_) {
		element_.addFront(Pair<T>(value, priority));
	}
	else if (priority > element_.last()->value_.priority_ || priority == element_.last()->value_.priority_) {
		element_.addBack(Pair<T>(value, priority));
	}
	else {
		Node<Pair<T>>* temp = element_.top();
		int count = 0;
		while (temp->next_ != nullptr && priority >= temp->value_.priority_) {
			temp = element_.move(count);
			++count;
		}
		element_.insert(Pair<T>(value, priority), temp);
		temp = nullptr;
	}
}

template<typename T>
T PriorQueue<T>::dequeue() {
	if (isEmpty()) {
		throw "Queue is empty";
	}
	else {
		return element_.clear(0)->value_.value_;
	}
}

template<typename T>
void PriorQueue<T>::print() {
	element_.print();
}

template<typename T>
void PriorQueue<T>::empty() {
	element_.emptyList();
}

template <typename T>
bool PriorQueue<T>::isEmpty() {
	return element_.isEmpty();
}