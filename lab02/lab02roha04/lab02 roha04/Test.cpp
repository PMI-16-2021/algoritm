#include"test.h"
#include"Stack.h"
#include<cassert>

bool Test_Constructor()
{
	Stack myStack(5);
	Stack Stack;
	if (!myStack.isEmpty() && Stack.isEmpty())
	{
		return true;
	}
	return false;
}

bool Test_Push()
{
	Stack mystack(5);
	mystack.push(2);
	if (mystack.topVal() == 2)
	{
		return true;
	}
	return false;
}

bool Test_Pop()
{
	Stack mystack(5);
	mystack.push(12);
	if (mystack.Pop() == 12)
	{
		return true;
	}
	return false;
}

bool Test_TopVal()
{
	Stack mystack(5);
	if (mystack.topVal() == 5)
	{
		return true;
	}
	return false;
}

bool Test_Swap()
{
	Stack stack_1(5);
	stack_1.push(6);
	stack_1.push(1);
	Stack stack_2(stack_1);
	if (stack_2.topVal() == 1)
	{
		return true;
	}
	return false;
}

bool Test_IsEmpty()
{
	Stack stack(5);
	stack.Pop();
	if (stack.isEmpty())
	{
		return true;
	}
	return false;
}

bool Test_GetSize()
{
	Stack mystack(5);
	mystack.push(3);
	mystack.push(6);
	mystack.push(8);
	if (mystack.getSize() == 4)
	{
		return true;
	}
	return false;
}

bool Test_Emplace()
{
	
	Stack mystack(4);
	while (!mystack.isEmpty()) {
		mystack.topVal() ;
		mystack.Pop();
		return true;
	}
	return false;
}

void Test_Constructors()
{
	assert(Test_Constructor() == true);
		std::cout << "Constructors IS Passed" << endl;
}

void Test_push()
{
	assert(Test_Push() == true);
	std::cout << "Push IS Passed" << endl;
}

void Test_pop()
{
	assert(Test_Pop() == true);
		std::cout << "Pop IS Passed" << endl;
}

void Test_topVal()
{
	assert(Test_TopVal() == true);
	std::cout << "TopVal IS Passed" << endl;
}

void Test_swap()
{
	assert(Test_Swap() == true);
	std::cout << "Swap IS Passed"<<endl;
}

void Test_isEmpty()
{
	assert(Test_IsEmpty() == true);
	std::cout << "Empty IS Passed" << endl;
	
}

void Test_getSize()
{
	assert(Test_GetSize() == true);
	std::cout << "GetSize IS Passed" << endl;
}

void Test_emplace()
{
	assert(Test_Emplace() == true);
	std::cout << "Emplace IS Passed" << endl;
}
