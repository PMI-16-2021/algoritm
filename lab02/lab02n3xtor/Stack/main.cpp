#include <iostream>
#include "stack.h"
#include "setOfStacks.h"
#include "stackTest.h"
using namespace std;

int main()
{
    Stack S1(3);
    S1.push(5);
    S1.push(3);
    S1.push(2);
    int emp = 5;
    S1.emplace(emp);
    S1.print();
    cout << "\nTop value: " << S1.topValue() << endl;

    SetOfStacks Set1(0, 4);
    Set1.push(1);
    Set1.push(5);
    Set1.push(3);
    Set1.push(6);
    Set1.push(16);
    Set1.push(27);
    Set1.push(87);
    Set1.popAt(1);
    Set1.printSet();
    cout << "\n\n";

    VconstructorTest();
    VpushTest();
    VpopTest();
    VgetTopValueTest();
    VswapTest();
    VisEmptyTest();
    VgetSizeTest();

    system("pause>>void");
    return 0;
}