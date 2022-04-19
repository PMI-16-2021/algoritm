#pragma once
#include <iostream>

template <typename T>
struct Pair {
    T value;
    int priority;
    Pair<T>* next;

    Pair(T val, int p)
        :value(val), priority(p), next(nullptr) {}
    ~Pair() {}
};

template <typename T>
class PriorityQueue {
private:
    Pair<T>* head = nullptr;
public:
    PriorityQueue() {}
    ~PriorityQueue() {}

    int size() {
        if (head == nullptr) {
            std::cout << "Queue is empty";
            return 0;
        }
        else {
            int count = 0;
            Pair<T>* temp = head;
            while (temp != nullptr) {
                ++count;
                temp = temp->next;
            }
            delete temp;
            return count;
        }
    }

    T top() {
        return head->value;
    }

    bool isEmpty() {
        if (head == nullptr) {
            return true;
        }
        else {
            return false;
        }
    }

    void empty() {
        Pair<T>* temp = head;
        while (temp != nullptr) {
            Pair<T>* pairToDelete = temp;
            temp = temp->next;
            delete pairToDelete;
        }
        head = nullptr;
    }

    void enqueue(T val, int p) {
        Pair<T>* newPair = new Pair<T>(val, p);
        Pair<T>* temp = head;
        if (head == nullptr) {
            head = newPair;
        }
        else if (p < head->priority) {
            newPair->next = head;
            head = newPair;
        }
        else {
            while (temp->next != nullptr && temp->next->priority < p) {
                temp = temp->next;
            }
            newPair->next = temp->next;
            temp->next = newPair;
        }
    }

    void dequeue() {
        if (head == nullptr) {
            return;
        }
        else {
            Pair<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void print() const {
        if (head == nullptr) {
            std::cout << "Queue is empty";
            return;
        }
        std::cout << "Queue: ";
        Pair<T>* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << ' ';
            temp = temp->next;
        }
    }
};

