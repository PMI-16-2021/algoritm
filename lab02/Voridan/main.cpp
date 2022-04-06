#include <iostream>
#include "stack.h"
#include "set_of_stacks.h"
#include "stack_test.h"
int main() {
    SetOfStacks S1(0,4);
    for(int i = 1; i < 10; i++) {
        S1.Push(i*2);
    }

    std::cout << "Set has from 0 to " << S1.GetCurrentIndex() << " indexed cells\n";
    S1.PrintSet(); std::cout<<'\n';
    std::cout << "Choose from which set node you want to pop\n";
    int index; std::cin>>index;
//    S1.PopAt(index);
//    std::cout << "\nJust pop at index \n"; S1.PrintSet(); std::cout <<"\n";
    S1.PopAtPush(index);
    std::cout << "\n Pop with push: \n"; S1.PrintSet(); std::cout <<"\n";

//    ConstructorTest();
//    IsEmptyTest();
//    GetSizeTest();
//    PushTest();
//    TopTest();
//    EmplaceTest();
//    PopTest();
//    SwapTest();
    return 0;
}

