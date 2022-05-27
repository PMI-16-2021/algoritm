#include <iostream>
#include "stackTest.h"
#include "cassert"
using namespace std;

bool BconstructorTest()
{
    Stack myStack(4);
    Stack Stack;
    if (!myStack.isEmpty() && Stack.isEmpty())
    {
        return true;
    }
    return false;
}

bool BpushTest()
{
    Stack Mystack(4);
    Mystack.push(0);
    if (Mystack.topValue() == 0)
    {
        return true;
    }
    return false;
}

bool BpopTest()
{
    Stack Mystack(4);
    Mystack.push(98);
    if (Mystack.pop() == 98)
    {
        return true;
    }
    return false;
}

bool BgetTopValueTest()
{
    Stack Mystack(4);
    if (Mystack.topValue() == 4)
    {
        return true;
    }
    return false;
}

bool BswapTest()
{
    Stack stack1(5);
    stack1.push(4);
    stack1.push(0);
    Stack stack2(1);
    stack2.swap(stack1);
    if (stack2.topValue() == 0)
    {
        return true;
    }
    return false;
}

bool BisEmptyTest()
{
    Stack stack(4);
    stack.pop();
    if (stack.isEmpty())
    {
        return true;
    }
    return false;
}

bool BgetSizeTest()
{
    Stack myStack(2);
    myStack.push(5);
    myStack.push(1);
    if (myStack.getSize() == 3)
    {
        return true;
    }
    return false;
}

void VconstructorTest()
{
    assert(BconstructorTest() == true);
    cout << "Constructor test passed\n";
}

void VpushTest()
{
    assert(BpushTest() == true);
    cout << "Push test passed\n";
}

void VpopTest()
{
    assert(BpopTest() == true);
    cout << "Pop test passed\n";
}

void VgetTopValueTest()
{
    assert(BgetTopValueTest() == true);
    cout << "Get top value test passed\n";
}

void VswapTest()
{
    assert(BswapTest() == true);
    cout << "Swap test passed\n";
}

void VisEmptyTest()
{
    assert(BisEmptyTest() == true);
    cout << "Is empty test passed\n";
}

void VgetSizeTest()
{
    assert(BgetSizeTest() == true);
    cout << "Get size test passed\n";
}