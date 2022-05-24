#include <iostream>
#include "stack.h"
#include "setOfStacks.h"
using namespace std;

int main() {

	SetOfStacks Set(3);
	Set.push(4);
	Set.push(2);
	Set.push(6);
	Set.push(5);
	Set.push(9);
	Set.push(7);
	Set.push(8);
	Set.push(3);
	Set.push(5);
	Set.push(2);
	cout << "Set of stacks:\n";
	Set.printSetOfStacks();
	Set.popAt(1);
	cout << "Set of stacks after popAt(1):\n";
	Set.printSetOfStacks();
	Set.pop();
	Set.pop();
	cout << "Set of stacks after 2 pop():\n";
	Set.printSetOfStacks();

	//Stack S;
	//cout << "Stack is empty(1), if not(0): " << S.isEmpty() << "\n\n";
	//S.push(4);
	//S.push(6);
	//cout << "Stack after 2 push():\n";
	//S.printStack();
	//cout << "Size of stack: " << S.size() << "\n\n";
	//S.push(1);
	//S.push(8);
	//S.push(9);
	//cout << "Stack after 3 push():\n";
	//S.printStack();
	//S.pop();
	//cout << "Stack after pop():\n";
	//S.printStack();
	//cout << "Stack's top: " << S.showTop() << "\n";
	//cout << "Stack is empty(1), if not(0): " << S.isEmpty() << "\n\n";
	//int a = 13;
	//S.emplace(a);
	//cout << "Stack after emplace():\n";
	//S.printStack();
	//Stack S2;
	//S2.push(3);
	//S2.swap(S);
	//cout << "\nStack after swap():\n";
	//S.printStack();

	return 0;
}