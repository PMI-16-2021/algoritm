#include "SetOfStacks.h"

SetOfStacks::SetOfStacks() : max_amount_of_stacks(10), used_stacks(0), ceil(5) {
	/*set_of_stacks = new Stack * [max_amount_of_stacks];*/
}

SetOfStacks::SetOfStacks(int s, int c) : max_amount_of_stacks(s), used_stacks(0), ceil(c) {
	/*set_of_stacks = new Stack * [max_amount_of_stacks];*/
	for (int i = 0; i < max_amount_of_stacks; ++i) {
		set_of_stacks.push_back(new Stack());
	}
}

SetOfStacks::~SetOfStacks() {
	/*for (int i = 0; i < used_stacks; ++i) {
		delete[] set_of_stacks[i];
	}
	delete[] set_of_stacks;*/
}

void SetOfStacks::push(int elem) {
	if (set_of_stacks[used_stacks]->size() < ceil) {
		set_of_stacks[used_stacks]->push(elem);
	}
	else {
		used_stacks += 1;
		if (set_of_stacks[used_stacks]->size() > ceil and used_stacks == max_amount_of_stacks) {
			throw SizeException();
		}
		set_of_stacks[used_stacks]->push(elem);
	}
}

int SetOfStacks::pop() {
	if (set_of_stacks.front()->size() == 0) {
		throw SizeException();
	}
	if (!set_of_stacks[used_stacks]->empty()) {
		return set_of_stacks[used_stacks]->pop();
	}
	else {
		used_stacks -= 1;
		return set_of_stacks[used_stacks]->pop();
	}
}

int SetOfStacks::popAt(int index) {
	if (set_of_stacks.front()->size() == 0) {
		throw SizeException();
	}
	else if (used_stacks < index) {
		throw IndexException();
	}

	if (!set_of_stacks[index]->empty()) {
		return set_of_stacks[index]->pop();
	}
	else {
		throw IndexException();
	}
}

void SetOfStacks::print() {
	std::cout << "Set of stacks: \n";
	for (int i = 0; i < set_of_stacks.size(); ++i) {
		set_of_stacks[i]->print();
	}
	std::cout << '\n';
}