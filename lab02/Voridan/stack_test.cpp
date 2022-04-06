#include "stack_test.h"

void IsEmptyTest() {
    Stack empty;
    if(empty.IsEmpty()) {
        std::cout << "IsEmptyTest passed\n";
    }
    else {
        std::cerr << "IsEmptyTest failed\n";
    }
}

void ConstructorTest() {
    Stack empty;
    Stack not_empty(2);
    if(empty.IsEmpty() && !not_empty.IsEmpty()) {
        std::cout << "ConstructorTest passed\n";
    }
    else {
        std::cerr <<"ConstructorTest failed\n";
    }
}

void PushTest() {
    const size_t n = 4;
    int expected[n] = {9,2,65,7};
    Stack stack;
    for(size_t i = 0; i < n; ++i){
        stack.Push(expected[i]);
    }
    bool result;
    size_t i = n;
    do{
        --i;
        if (expected[i] == stack.Pop()) {
            result = true;
        } else {
            result = false;
        }
    }while(i > 0);
    if (result) {
        std::cout << "PushTest passed\n";
    }
    else {
        std::cerr << "PushTest failed\n";
    }
}

void GetSizeTest() {
    Stack stack;
    for(size_t i = 0; i < 4; ++i) {
        stack.Push(i*2);
    }
    if(stack.GetSize() == 4) {
        std::cout << "GetSizeTest passed\n";
    }
    else {
        std::cerr << "GetSizeTest failed\n";
    }
}

void TopTest() {
    Stack stack;
    stack.Push(3);
    stack.Push(7);
    stack.Push(4);
    if(stack.Top() == 4) {
        std::cout<<"TopTest passed\n";
    }
    else {
        std::cerr<<"TopTest failed\n";
    }
}

void PopTest() {
    Stack stack;
    try {
        stack.Pop();
    } catch(Stack::EmptyStack) {
        std::cout<<"EmptyStack exception passed\n";
    }
    stack.Push(34);
    stack.Push(12);
    stack.Push(67);
    stack.Push(25);
    if(stack.Pop() == 25 && stack.Top() == 67) {
        std::cout << "PopTest passed\n";
    }
    else {
        std::cerr << "PopTest failed\n";
    }
}

void EmplaceTest() {
    Stack stack;
    int a = 9;
    stack.Emplace(a);
    if(stack.Top() == 9){
        std::cout << "EmplaceTest passed\n";
    }
    else {
        std::cerr << "EmplaceTest failed\n";
    }
}

void SwapTest() {
    Stack stack_1;
    Stack stack_2;
    stack_1.Push(9);
    stack_1.Push(2);
    stack_1.Push(3);
    int check_1 =stack_1.Top();
    stack_2.Push(4);
    stack_2.Push(6);
    stack_2.Push(7);
    int check_2 =stack_2.Top();
    stack_1.Swap(stack_2);
    if(stack_1.Top() == check_2 && stack_2.Top() == check_1) {
        std::cout << "SwapTest passed\n";
    }
    else {
        std::cerr << "SwapTest failed\n";
    }
}

