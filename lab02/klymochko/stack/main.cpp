#include<iostream>
#include "stack.h"
#include "SetOfStacks.h"


int main() {
	
	Stack myS;
	myS.emplace(5);
	myS.emplace(2);
	myS.emplace(7);
	myS.printStack();

	std::cout << "Size: " << myS.size() << '\n';

	myS.pop();
	myS.printStack();
	std::cout << "Top: " << myS.topS() << '\n';
	std::cout << "Size: " << myS.size() << "\n\n";
	myS.empty();
	myS.printStack();

	Stack myS_2;
	myS_2.emplace(3);
	myS_2.emplace(9);
	myS_2.emplace(1);

	myS.printStack();
	myS_2.printStack();

	std::cout << "Swap stacks:\n";
	myS.swap(&myS_2);
	myS.printStack();
	myS_2.printStack();


	SetOfStacks setOfStacks(2);
	setOfStacks.push(2);
	setOfStacks.push(4);
	setOfStacks.push(1);
	setOfStacks.push(3);
	setOfStacks.push(7);
	setOfStacks.push(9);
	setOfStacks.printSetOfStacks();
	setOfStacks.popAt(2);
	setOfStacks.printSetOfStacks();
	system("pause");
	return 0;
}