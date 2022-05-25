#include <iostream>
#include "stack.h"
#include "SetOfStacks.h"
using namespace std;
int main()
{
	Stack s(7);
	s.push(3);
	s.push(5);
	s.printStack();
	s.push(6);
	s.printStack();
	s.push(6);
	s.printStack();
	s.push(6);

	Stack s1;
	if (s1.isEmpty() == true) {
		cout << "is empty\n";
	}
	s1.push(4); s1.push(7);
	if (s1.isEmpty() == true) {
		cout << "is empty\n";
	}
	s1.printStack();
	s1.push(7); s1.push(9); s1.push(2);
	cout << "s1: ";
	s1.printStack();
	cout << "s: ";
	s.printStack();
	s1.swap(&s);
	s1.printStack();
	cout << s1.sTop() << endl;
	cout << s1.sLast() << endl;
	s1.pop();
	s1.printStack();
	cout << "size: " << s1.size() << endl;
	s1.emplace(4, 2);
	s1.printStack();
	s1.empty();
	if (s1.isEmpty())
		cout << "s1 is empty" << endl;
	cout << "-----------------------------------------------------------------------------------------------------\n" << "Set of Stacks :\n";
	SetOfStacks set;
	set.push(4);
	set.push(5);
	set.push(6);
	set.push(7); 
	set.push(8);
	set.push(9);
	set.push(2);
	set.printSetOfStacks();
	cout << "-------------------------------------------------\n";
	set.pop();
	set.printSetOfStacks();
	cout << "-------------------------------------------------\n";
	set.popAt(1); 
	set.printSetOfStacks();

	system("pause");
	return 0;
}