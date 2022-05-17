#include <iostream>
#include"functions.h"
using namespace std;
#include "string"
#include "TESTS.h"

int main()
{
    string exp1;
    cin>>exp1;
    string example = "28+9*(44-2)-6^2"; //370
    cout <<"Your expression in reverse polish notation " << toPostfix(exp1) << '\n';
    cout <<"Your result : " << CountExpression(toPostfix(exp1))<<"\n";

     test1();
     test2();
     test3();
     test4();
     test5();
     test6();
     test7();

    return 0;
}