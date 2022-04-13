#include <iostream>
#include "Stack.h"
#include "SetofStacks.h"
using namespace std;

int main()
{
    SetOfStacks stacks(5);
    stacks.push(10);
    stacks.push(1);
    stacks.push(110);
    stacks.push(12);
    stacks.push(13);
    stacks.push(14);
    stacks.push(12);
    stacks.push(5);
    stacks.push(6);
    stacks.pop();
    stacks.print();




	system("pause");
	return 0;
}

