#include"functions.h"
using namespace std;
#include "TESTS.h"

int main()
{
    string example1;
    cin>>example1;
    std::string example = "28+9*(44-2)-6^2";
    std::cout <<"Your expression in reverse polish notation " << toPostfix(example1) << '\n';
    std::cout <<"Your result : " << CountExpression(toPostfix(example1))<<"\n";

     test1();
     test2();
     test3();
     test4();
     test5();
     test6();
     test7();

    return 0;
}