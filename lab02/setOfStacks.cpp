#include "SetOfStacks.h"

SetOfStacks::SetOfStacks() {
	arr.push_back(new Stack());
}

SetOfStacks::SetOfStacks(int n)
	: size(n) {
	arr.push_back(new Stack());
}

SetOfStacks::~SetOfStacks() {};

void SetOfStacks::push(int a) {
	if (count < size) {
		arr.back()->push(a);
		++count;
	}
	else {
		arr.push_back(new Stack());
		arr.back()->push(a);
		count = 1;
	}
}

void SetOfStacks::pop() {
	if (count > 1) {
		arr.back()->pop();
		--count;
	}
	else if (count = 1) {
		arr.back()->pop();
		arr.pop_back();
		count = size;
	}
	else {
		arr.pop_back();
		arr.back()->pop();
		count = size - 1;
	}
}

void SetOfStacks::popAt(int pos) {
	arr.erase(arr.begin() + pos);
}

void SetOfStacks::printSetOfStacks() {
	for (int i = 0; i < arr.size(); ++i) {
		arr[i]->printStack();
	}
}