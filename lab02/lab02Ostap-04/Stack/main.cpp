#include <iostream>
#include "stack.h"
#include "set_of_stacks.h"
using namespace std;
int main() {
    SetOfStacks Set;
    Set.Push(2);
    Set.Push(245);
    Set.Push(2);
    Set.Push(6);
    Set.Push(7);
    Set.Push(-1);
    Set.Push(-29);
    Set.Push(7);
    Set.Push(45);
    Set.Push(23);

    Set.Push(-6);
    Set.Push(2);
    Set.Push(4);
    Set.Push(9);
    Set.Push(0);
    Set.Push(20);
    Set.Push(4);

    Set.PopAt(0);
    Set.PopAt(0);
    Set.PopAt(0);
    Set.Pop();
    Set.Pop();
    
    Set.Print();
    system("pause");
    return 0;
}