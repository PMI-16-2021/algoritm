#include "stack.h"
#include "SetOfStacks.h"


int main () {

	SetOfStacks SOS(2);

	SOS.push(2);
	SOS.push(4);
	SOS.push(1);
	SOS.push(3);
	SOS.push(7);
	SOS.push(9);
	SOS.printSetOfStacks();
	SOS.popAt(2);
	//SOS.pop();
	//SOS.pop();
	SOS.printSetOfStacks();

	
	Stack myStack;
	std::cout << "Return 1 if stack is empty, else return 0: " << myStack.isEmpty() << "\n";
	myStack.emplace(5);
	myStack.emplace(2);
	myStack.emplace(7);
	//myStack.push(myStack_2);
	myStack.printStack();
	
	std::cout << "Size of stack is " << myStack.size() << "\n\n";
	
	myStack.pop();
	std::cout << "My stack after pop():";
	myStack.printStack();
	
	std::cout << "Return 1 if stack is empty, else return 0: " << myStack.isEmpty() << "\n";
	
	myStack.empty();
	myStack.printStack();
	
	myStack.emplace(5);
	myStack.printStack();
	
	std::cout << "\nThe top: " << myStack.topS() << "\n";
	
	std::cout << "\nSize of stack is " << myStack.size() << "\n\n\n";
	//----------------------------------------------------------------------------------------//
	Stack myStack_2;
	myStack_2.emplace(3);
	myStack_2.emplace(9);
	myStack_2.emplace(1);
	
	myStack.printStack();
	myStack_2.printStack();
	
	std::cout << "\nSwap stacks:\n";
	myStack.swap(&myStack_2);
	myStack.printStack();
	myStack_2.printStack();

}