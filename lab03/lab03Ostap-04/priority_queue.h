#pragma once
#include "list.h"

template<typename T>
struct Pair {
    T value;
    int priority;
    Pair() : value(), priority(0) {}
    Pair(T _val, int _prior) : value(_val), priority(_prior) {}
    Pair(const Pair<T>& other) : value(other.value), priority(other.priority) {}
    ~Pair() {}
    void Print() const;
};
template<typename T>
void Pair<T>::Print() const {
    std::cout << priority <<"  " << value;
}
template<typename T>
class PriorityQueue {
private:
    List<Pair<T>> item_;

public:
    PriorityQueue() : item_() {}
    ~PriorityQueue();
    int Size() const { return item_.GetSize(); }
    const T& Top() const;
    bool IsEmpty() const;
    void Enqueue(T val, int prior);
    T Dequeue();
    void PrintQueue() const;
};
template<typename T>
PriorityQueue<T>::~PriorityQueue() {
    item_.Clear();
}
template<typename T>
const T& PriorityQueue<T>::Top() const {
    if (IsEmpty()) {
        throw "Queue is empty";
    }
    return item_.GetHead()->value.value;
}
template<typename T>
bool PriorityQueue<T>::IsEmpty() const {
    return item_.IsEmpty();
}
template<typename T>
void PriorityQueue<T>::Enqueue(T _value, int _priority) {
    if (item_.IsEmpty()) {
        item_.PushBack(Pair<T>(_value, _priority));
    }
    else if (_priority < item_.GetHead()->value.priority) {
        item_.PushFront(Pair<T>(_value, _priority));
    }
    else if (_priority > item_.GetTail()->value.priority) {
        item_.PushBack(Pair<T>(_value, _priority));
    }
    else {
        Node<Pair<T>>* temp = item_.GetHead();
        int index = 0;
        while (temp->value.priority <= _priority && temp->next != nullptr) {
            temp = temp->next;
            index++;
        }
        item_.Insert(index, Pair<T>(_value, _priority));
        temp = nullptr;
    }
}
template<typename T>
T PriorityQueue<T>::Dequeue() {
    if (IsEmpty()) {
        throw "Queue is empty";
    }
    else {
        return item_.PopFront().value;
    }
}
template<typename T>
void PriorityQueue<T>::PrintQueue() const {
    std::cout << "Priority Queue: (priority, value)\n";
    Node<Pair<T>>* temp = item_.GetHead();
    while (temp != nullptr) {
        temp->value.Print(); std::cout << '\n';
        temp = temp->next;
    }
    std::cout << '\n';
}