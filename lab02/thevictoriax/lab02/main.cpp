#include <iostream>
#include "stack.h"
#include "setOfStacks.h"
using namespace std; 
int main()
{
    SetOfStacks stack(3);
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    stack.push(6);
    stack.push(7);
    stack.push(8);
    stack.push(9);
    stack.printSetElements();
    
    cout << "----------------------\n";

    stack.pop();
    stack.printSetElements();

    cout << "----------------------\n";

    stack.popAt(1);
    stack.printSetElements();

    return 0;
    system("pause");
}