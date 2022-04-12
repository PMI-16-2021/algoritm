#include <iostream>
#include "Stack.h"
#include "SetOfStacks.h"
#include "Tests.h"

int main() {
    Stack S2(3);
    S2.push(1);
    S2.push(9);
    S2.push(0);
    int a=4;
    S2.emplace(a);
    S2.print();
    cout<< "\n"<< S2.topValue();

//////////////////////////////

    cout<<'\n';
    SetOfStacks Set1(0,4);
    Set1.push(2);
    Set1.push(3);
    Set1.push(1);
    Set1.push(9);
    Set1.push(20);
    Set1.push(33);
    Set1.push(91);
    Set1.popAt(1);


   Set1.printSet();

////////////////////////////

   Test_constructors();
   Test_push_stack();
   Test_pop_stack();
   Test_GetTop();
   Test_swapStacks();
   Test_isEmpty();
   Test_getSize();

    return 0;
}
