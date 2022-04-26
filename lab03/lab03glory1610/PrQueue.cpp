#include<iostream>
#include "PrQueue.h"
using namespace std;

PriorityQueue::PriorityQueue()
	: head(nullptr) 
{}

PriorityQueue::~PriorityQueue()
{}

int PriorityQueue::size() {
	int counter = 0;
	if (head == nullptr) {
		cout << "Queue is empty\n";
		return 0;
	}
	else {
		Pair* temp = head;
		while (temp != nullptr) {
			++counter;
			temp = temp->next;
		}
	}
	return counter;
}

int PriorityQueue::top() {
	if (head == nullptr) {
		cout << "Queue is empty\n";
		return 0;
	}
	else {
		return head->value;
	}
}

bool PriorityQueue::isEmpty() {
	if (head == nullptr) {
		return true;
	}
	else {
		return false;
	}
}

void PriorityQueue::enqueue(int val, int prior) {
	Pair* temp = new Pair(val, prior);
	if (head == nullptr || prior < head->priority) {
		temp->next = head;
		head = temp;
	}
	else {
		Pair* start = head;
		while (start->next != NULL && start->next->priority < prior) {
			start = start->next;
		}
		temp->next = start->next;
		start->next = temp;
	}
}

int PriorityQueue::dequeue() {
	if (head == nullptr) {
		cout << "Queue is empty\n";
		return 0;
	}
	else {
		int high_elem = head->value;
		head = head->next;
		return high_elem;
	}
}

void PriorityQueue::print() {
	if (head == nullptr) {
		cout << "Queue is empty\n";
		return;
	}
	else {
		Pair* temp = head;
		while (temp != nullptr) {
			cout << temp->value << "\n";
			temp = temp->next;
		}
	}
}