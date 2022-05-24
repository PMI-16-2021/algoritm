#include "stackSet.h"
using namespace std;


SetOfStacks::SetOfStacks(int size) : element_max(size) {
	setArr.push_back(new Stack());
	stack_size = 1;
}
SetOfStacks::~SetOfStacks() {}

void SetOfStacks::popAt(int index) {
	setArr.erase(setArr.begin() + index - 1);
}

void SetOfStacks::pop() {
	if (stack_size > 1) {
		setArr.back()->pop();
		--stack_size;
	}
	else {
		setArr.pop_back();
		stack_size = element_max;
	}
}

void SetOfStacks::push(int value) {
	if (stack_size <= element_max) {
		setArr.back()->push(value);
		++stack_size;
	}
	else {
		setArr.push_back(new Stack);
		setArr.back()->push(value);
		stack_size = 2;
	}
}

void SetOfStacks::printSet() {
	std::cout << "Set of stacks: \n";
	for (int i = 0; i < setArr.size(); ++i) {
		std::cout << i + 1 << ". ";
		setArr[i]->printStack();
	}
	std::cout << "\n\n";
}