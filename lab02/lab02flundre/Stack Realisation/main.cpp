#include <iostream>
#include "Stack.h"
#include "SetOfStacks.h"
#include <utility>

using namespace std;

int main() {
	SetOfStacks my_set(3, 5);
	my_set.push(1);
	my_set.push(2);
	my_set.push(3);
	my_set.push(4);
	my_set.push(5);
	my_set.push(11);
	my_set.push(22);
	my_set.push(33);
	my_set.print();
	my_set.popAt(0);
	my_set.print();
	system("pause");
	return 0;
}