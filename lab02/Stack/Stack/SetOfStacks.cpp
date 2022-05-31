#include "SetOfStacks.h"

SetOfStacks::SetOfStacks(int size) {
	max = size;
	arr.push_back(new Stack());
	this->size = 1;
}
SetOfStacks::~SetOfStacks() {
	
}

void SetOfStacks::push(int value) {
	if (size <= max) {
		arr.back()->push(value);  //acces the last element and after that push it
		++size;
	}
	else {
		arr.push_back(new Stack(value)); // add stack to arr
		size = 2;
	}
}
void SetOfStacks::pop() {
	if (size > 1) {
		arr.back()->pop(); //acces to the last stack and delete the last element
		--size;
	}
	else {
		arr.pop_back(); // delete last stack
		size = max;
	}
}
void SetOfStacks::popAt(int index) {
	arr.erase(arr.begin() + index - 1);  //remove stack from arr
}
void SetOfStacks::printSetOfStacks() {
	for (int i = 0; i < arr.size(); ++i) {
		std::cout << "#" << i + 1 << ": ";
		arr[i]->printStack();
		std::cout << "\n";
	}
}