#include <iostream>
#include "Stack.h"
#include "SetOfStacks.h"
using namespace std;

int main()
{
    SetOfStacks stacks(5);
    stacks.push(9);
    stacks.push(2);
    stacks.push(90);
    stacks.push(13);
    stacks.push(16);
    stacks.push(14);
    stacks.push(10);
    stacks.push(5);
    stacks.pop();
    stacks.print();




    system("pause");
    return 0;
}