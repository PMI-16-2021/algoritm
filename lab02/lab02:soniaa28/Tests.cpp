#include "Tests.h"
#include "cassert"



bool Test_Constructor()
{
    Stack myStack(4);
    Stack Stack;
    if(!myStack.isEmpty() && Stack.isEmpty())
    {
        return true;
    }
    return false;
}
void Test_constructors()
{
    assert(Test_Constructor() ==true);
    std::cout<<"Test on constructors  in Stack is PASSED!\n";
}
bool Test_Push_Stack()
{
    Stack Mystack(4);
    Mystack.push(0);
    if(Mystack.topValue()==0)
    {
        return true;
    }
     return false;
   }

void Test_push_stack()
{
    assert(Test_Push_Stack()==true);
    std::cout<<"Test on push() in Stack is PASSED!\n";

}

bool Test_Pop_Stack()
{
    Stack Mystack(4);
    Mystack.push(98);
    if(Mystack.pop()==98) // beacause method pop() returns int
         {
            return true;
         }
    return false;
}


void Test_pop_stack()
{
    assert(Test_Pop_Stack()==true);
    std::cout<<"Test on pop() in Stack is PASSED!\n";

}

bool Test_GetTopValue()
{
    Stack Mystack(4);
    if(Mystack.topValue()==4)
    {
        return true;
    }
    return false;
}

void Test_GetTop()
{
    assert(Test_GetTopValue()==true);
    std::cout<<"Test on getTopValue() in Stack is PASSED!\n";

}

bool Test_Swap()
{
    Stack stack1(5);
    stack1.push(4);
    stack1.push(0);
    Stack stack2(1);
    stack2.swap(stack1);
    if(stack2.topValue()==0)
    {
        return true;
    }
        return false;
}

void Test_swapStacks()
{
    assert(Test_Swap()==true);
    std::cout<<"Test on swap() Stacks in Stack is PASSED!\n";
}

bool Test_IsEmpty()
{
    Stack stack(4);
    stack.pop();
    if(stack.isEmpty())
    {
        return true;
    }
    return false;
}

void Test_isEmpty()
{
    assert(Test_IsEmpty() ==true);
    std::cout<<"Test on isEmpty() in Stack is PASSED!\n";

}

bool Test_GetSize()
{
   Stack myStack(2);
   myStack.push(5);
   myStack.push(1);
   if(myStack.getSize()==3)
   {
       return true;
   }
   return false;
}

void Test_getSize()
{
    assert(Test_GetSize() ==true);
    std::cout<<"Test on getSize() in Stack is PASSED!\n";
}




