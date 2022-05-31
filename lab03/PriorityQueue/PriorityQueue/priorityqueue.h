#pragma once
#include <iostream>

template <typename T>
struct Pair {
    T value;
    int priority;
    Pair<T>* next;

    Pair(T, int);
};

template <typename T>
Pair<T>::Pair(T _value, int _priority)
    :value(_value), priority(_priority), next(nullptr) {}

template <typename T>
class PriorityQueue {
private:
    Pair<T>* head;

public:
    PriorityQueue();
    int size();//+
    T top();//+
    bool isEmpty();//+
    void enqueue(int, int);//+
    void dequeue();
    void empty();
    void print() const;//+
};

template <typename T>
PriorityQueue<T>::PriorityQueue()
    :head(nullptr) {}

template <typename T>
int PriorityQueue<T>::size() {
    if (head == nullptr) {
        std::cout << "\nQueue is empty!\n";
    }
    int counter = 0;
    Pair<T>* local = head;
    while (local) {
        ++counter;
        local = local->next;
    }
    delete local;
    return counter;
}

template <typename T>
T PriorityQueue<T>::top() {
    return head->value;
}

template <typename T>
bool PriorityQueue<T>::isEmpty() {
    if (!head) {
        return true;
    }
    else return false;
}

template <typename T>
void PriorityQueue<T>::enqueue(int _value, int _priority) {
    Pair<T>* local = new Pair<T>(_value, _priority);
    Pair<T>* temp = head;
    if (head == nullptr) {
        head = local;
        return;
    }
    if (head->priority > _priority) {
        local->next = head;
        head = local;
    }
    else {
        while (temp->next != nullptr && temp->next->priority < _priority) {
            temp = temp->next;
        }
        local->next = temp->next;
        temp->next = local;
    }

}

template <typename T>
void PriorityQueue<T>::dequeue() {
    Pair<T>* temp = head;
    head = head->next;
    delete temp;
}

template <typename T>
void PriorityQueue<T>::empty() {
    Pair<T>* local = head;
    Pair<T>* temp;
    while (local != nullptr) {
        temp = local;
        local = local->next;
        delete temp;
    }
    head = nullptr;
}

template <typename T>
void PriorityQueue<T>::print() const {
    if (head == nullptr) {
        std::cout << "\nQueue is empty!\n";
        return;
    }
    std::cout << "\nMy Queue: ";
    Pair<T>* local = head;
    while (local) {
        std::cout << local->value << ' ';
        local = local->next;
    }
    std::cout << "\n";
}