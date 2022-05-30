#include "set_of_stacks.h"

SetOfStacks::SetOfStacks(): s_max(0) {
    s_arr = nullptr;
}

SetOfStacks::SetOfStacks(Stack* pNext, int max) : s_max(max) {
    s_arr = pNext;
}

SetOfStacks::SetOfStacks(int val, int max) : s_max(max) {
    s_arr = new Stack(val);
}

void SetOfStacks::push(int val) {
    if (s_arr != nullptr && s_arr->size() < s_max)
    {
        s_arr->push(val);
    }
    else {
        Stack* newStack = new Stack(val);
        newStack->next = s_arr;
        s_arr = newStack;

    }
    ++s_size;
}

void SetOfStacks::pop(){
	Stack* temp = s_arr;
	if (temp->empty()) {
		throw "stack is empty";
	}
	else if(s_arr->empty()){
		s_arr = s_arr->next;
	}
	else {
		s_arr->pop();
	}
}

void SetOfStacks::popAt(int index){
	if (index <= 0 || index > getSize()) {
		throw "not exist";
	}
	else {
		Stack* temp = s_arr;
		for (int i = 0; i < index - 1; ++i){
			temp = temp->next;
		}
		temp->pop();
	}
}

void SetOfStacks::printSet(){
    int sizeSet = getSize();
    Stack* temp = s_arr;

    if (temp == nullptr)
    {
        throw "\n Set of stacks is empty\n";

    }
    else
    {
        for (int i = 0; i < sizeSet; ++i)
        {
            std::cout << "Stack #" << i + 1 << "\n";
            temp->print();
            temp = temp->next;
        }
    }
}

int SetOfStacks::getSize() const{
    int _size = 0;
    Stack* temp;
    if (s_arr == nullptr)
    {
        return 0;
    }
    else
    {
        temp = s_arr;
        while (temp != nullptr)
        {
            ++_size;
            temp = temp->next;
        }
    }
    return _size;
}