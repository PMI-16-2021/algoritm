#include "queue.h"
using namespace std;

Pair::Pair(int v, int pr): value(v), priority(pr), next(nullptr) {}

PriorityQ::PriorityQ() {
    head = nullptr;
}
PriorityQ::~PriorityQ() {}
Pair::~Pair() {}

void PriorityQ::enqueue(int v, int pr) {
    Pair* newVal = new Pair(v, pr);
    Pair* temp = head;
    if (head == nullptr) {
        head = newVal;
    }
    else if (pr < head->priority) {
        newVal->next = head;
        head = newVal;
    }
    else {
        while (temp->next != nullptr && temp->next->priority < pr) {
            temp = temp->next;
        }
        newVal->next = temp->next;
        temp->next = newVal;
    }
}

void PriorityQ::dequeue() {
    if (head == nullptr) {
        return;
    }
    else {
        Pair* t = head;
        head = head->next;
        delete t;
    }
}

bool PriorityQ::isEmpty() {
    return head == nullptr;
}

int PriorityQ::size() {
    int size_count = 0;
    Pair* ptr;
    ptr = head;
    while (ptr != nullptr) {
        ++size_count;
        ptr = ptr->next;
    }
    return size_count;
}

int PriorityQ::top() {
    return head->value;
}

void PriorityQ::printQ() {
    if (head == nullptr) {
        cout << "Queue is empty\n";
        return;
    }
    else {
        cout << "Queue:\n";
        Pair* ptr;
        ptr = head;
        while (ptr != nullptr)
        {
            cout << "Priority: " << ptr->priority << ". Value: " << ptr->value << endl;
            ptr = ptr->next;
        }
    }
    cout << "\n";
}