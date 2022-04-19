#include "Stack.h"
#include <utility>

using std::cout;

bool Stack::empty() {
	return index == 0;
}

int Stack::size() {
	return index;
}

int Stack::top() {
	return memory[index-1];
}

void Stack::push(int x) {
	memory[index] = x;
	index += 1;
}

void Stack::emplace(int x) {
	push(x);
}

int Stack::pop() {
	index -= 1;
	int temp = memory[index];
	memory[index] = 0;
	return temp;
}

void Stack::swap(Stack& second_stack){
	if (this->size() != second_stack.size()) {
		throw SizeException();
	}
	std::swap(this->memory, second_stack.memory);
}

void Stack::print() {
	int size = this->size();
	for (int i = 0; i < size; ++i) {
		cout << this->memory[i] << '\t';
	}
	cout << '\n';
}
