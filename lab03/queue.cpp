#include "queue.h"
#include <iostream>
using namespace std;

PriorityQueue::PriorityQueue() : tail(nullptr) {}
PriorityQueue::PriorityQueue(int value, int prior) : tail(new Pair(value, prior)) {}
void PriorityQueue::enqueue(int v, int p) {
   /* Pair* pair = new Pair(v, p);
    if (this->isEmpty()) {
        tail = pair;
    }
    Pair* temp = tail;

    while (temp->priority < p && temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = pair;*/
  
        Pair* newVal = new Pair(v, p);
        Pair* temp = tail;
        if (tail == nullptr) {
            tail = newVal;
        }
        else if (p > tail->priority) {
            newVal->next = tail;
            tail = newVal;
        }
        else {
            while (temp->next != nullptr && temp->next->priority > p) {
                temp = temp->next;
            }
            newVal->next = temp->next;
            temp->next = newVal;
        }
    

}
bool PriorityQueue::isEmpty() {
    return tail == nullptr;
}
void PriorityQueue::printPriorityQueue() {
    if (tail == nullptr) {
        cout << "empty\n";
        return;
    }
    Pair* currNode;
    currNode = tail;
    while (currNode != nullptr) {
        cout << currNode->value << " priority: " << currNode->priority << endl;
        currNode = currNode->next;
    }
}

int PriorityQueue::size() {
    int size = 0;
    if (tail == nullptr) {
        return size;
    }
    Pair* currNode;
    currNode = tail;
    while (currNode != nullptr) {
        ++size;
        currNode = currNode->next;
    }
    return size;
}
void PriorityQueue::dequeue()
{
    if (tail == nullptr) {
        cout << "queue is empty!\n";
        return ;
    }
    Pair* currNode;
    currNode = tail;
    while (currNode->next->next != nullptr) {
        currNode = currNode->next;
    }
    Pair* delNode = currNode->next;
    currNode->next = nullptr;
    delete delNode;
}
int PriorityQueue::taill() {
    if (tail == nullptr) {
        cout << "queue is empty!\n";
        return 0;
    }
    return tail->value;
}
int  PriorityQueue::head() {
    if (tail == nullptr) {
        cout << "queue is empty!\n";
        return 0;
    }
    Pair* currNode;
    currNode = tail;
    while (currNode->next != nullptr) {
        currNode = currNode->next;
    }
    return currNode->value;
}