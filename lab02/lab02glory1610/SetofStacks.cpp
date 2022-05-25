#include<iostream>
#include "SetofStacks.h"
using namespace std;

SetOfStacks::SetOfStacks(int size) {
	this->size = size;
	MassNodes = new Stack[amount];
}

void SetOfStacks::push(int value) {
    for (int i = amount - 1; i >= 0; --i) {
        if (MassNodes[i].size() > size) {
            continue;
        }
        else {
            MassNodes[i].push(value);
            return;
        }
    }
}

void SetOfStacks::pop() {
    for (int i = 0; i < amount; ++i) {
        if (MassNodes[i].empty()) {
            continue;
        }
        else {
            MassNodes[i].pop();
            return;
        }
    }
}

void SetOfStacks::popAt(int index) {
    int k = 0;
    for (int i = amount - 1; i >= 0; --i) {
        if (MassNodes[i].empty()) {
            continue;
        }
        else {
            if (k == index) {
                MassNodes[i].pop();
                return;
            }
            ++k;
        }
    }
}

void SetOfStacks::print() {
    for (int i = 0; i < amount; i++) {
        MassNodes[i].print();
    }
}