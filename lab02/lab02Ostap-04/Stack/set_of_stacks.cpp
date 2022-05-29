#include <iostream>
#include "set_of_stacks.h"
SetOfStacks::SetOfStacks() : set_size_(5), max_size_(10), full_set_counter_(0) {
	memory_ = new Stack[set_size_];
}
SetOfStacks::SetOfStacks(int _max_size, int _set_size) : max_size_(_max_size), set_size_(_set_size), full_set_counter_(0) {
	memory_ = new Stack[max_size_];
}
SetOfStacks::~SetOfStacks() {
	delete[]memory_;
}
void SetOfStacks::Push(int value) {
	if (full_set_counter_ < set_size_ && memory_[full_set_counter_].Size() < max_size_) {
		memory_[full_set_counter_].Push(value);
	}
	else if (full_set_counter_ < set_size_ && memory_[full_set_counter_].Size() == max_size_) {
		++full_set_counter_;
		memory_[full_set_counter_].Push(value);
	}
	else {
		throw "Set of Stacks is full\n";
	}
}
void SetOfStacks::Pop() {
	if (full_set_counter_ > 0 && memory_[full_set_counter_].Empty()) {
		while (full_set_counter_ > 0 && memory_[full_set_counter_].Empty()) {
			--full_set_counter_;
		}
	}
	else if (full_set_counter_ == 0 && memory_[full_set_counter_].Empty()) {
		throw "Set of Stacks is empty\n";
	}
	else {
		memory_[full_set_counter_].Pop();
	}
}
void SetOfStacks::PopAt(int index) {
	if (index < 0 && index > set_size_ - 1) {
		throw "Bad index\n";
	}
	else if (memory_[index].Empty()) {
		throw"This Stack is Empty\n";
	}
	else {
		memory_[index].Pop();
	}
}
void SetOfStacks::Print() {
	if (full_set_counter_ == 0 && memory_[full_set_counter_].Empty()) {
		std::cout << "Emty set of Stacks\n";
	}
	else {
		for (int i = 0; i <= full_set_counter_; ++i) {
			std::cout << i + 1 << ": ";
			memory_[i].PrintStack();
			std::cout << '\n';
		}
	}
}