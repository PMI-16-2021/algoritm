#include <iostream>
#include "stack.h"
#include "stackSet.h"
using namespace std;

int main() {

    SetOfStacks stackSet(3);

    stackSet.push(1);
    stackSet.push(2);
    stackSet.push(3);
    stackSet.push(4);
    stackSet.push(5);
    stackSet.push(6);
    stackSet.push(7);
    stackSet.push(8);
    stackSet.push(9);
    stackSet.push(10);

    stackSet.printSet();

    stackSet.pop();
    stackSet.pop();
    stackSet.pop();

    stackSet.printSet();

    stackSet.popAt(1);
    stackSet.printSet();

    system("pause");
    return 0;
}