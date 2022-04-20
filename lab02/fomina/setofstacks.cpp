#include "SetOfStacks.h"
#include <iostream>
using namespace std;

SetOfStacks::SetOfStacks() : max(5), size(1) {
	stackArr.push_back(new Stack());
}
SetOfStacks::SetOfStacks(int s) : max(s), size(1) {
	stackArr.push_back(new Stack());
}
SetOfStacks::~SetOfStacks() {}
void SetOfStacks::push(int val) {
	if (size <= max) {
		stackArr.back()->push(val);
		++size;
	}
	else {
		stackArr.push_back(new Stack(val));
		size = 2;
	}
}
void SetOfStacks::printSetOfStacks() {
	for (int i = 0; i < stackArr.size(); ++i) {
		stackArr[i]->printStack();
		cout << "\n";
	}
}
void SetOfStacks::pop() {
	if (size > 1) {
		stackArr.back()->pop();
		--size;
	}
	else {
		stackArr.pop_back();
		size = max;
	}
}
void SetOfStacks::popAt(int index) {
	stackArr.erase(stackArr.begin() + index - 1);
}