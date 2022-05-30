#include"Stack.h"

Node::Node(int NodeVal,Node *Nodeptr)
	:val(NodeVal),ptr(Nodeptr)
{}
Stack::Stack()
	:top(nullptr)
{}
Stack::Stack(int val)
{
	top = new Node(val, nullptr);
	++size;
	next = nullptr;
}
Stack::~Stack()
{}
int Stack::push(int val)
{
	Node* next = new Node(val, top);
	top = next;
	++size;
	return val;
}
bool Stack::isEmpty()const
{
	return(top == nullptr);
}
void Stack::delTop()
{
	if (isEmpty())
		return;
	Node* temp = top;
	top=top->ptr;
	delete temp;
	--size;
}
void Stack::print()const
{
	Node* temp;
	if (top == nullptr)
	{
		throw"\nEmpty Stack" ;
	}
	else
	{
		temp = top;
		while (temp != nullptr)
		{
			std::cout << temp->val << endl;
			temp = temp->ptr;
		}
	}
}
int Stack::Pop()
{
	
	if (isEmpty())
	{
		throw"\nEmpty Stack";
	}
	int retVal = top->val;
	delTop();
	return retVal;
}
int Stack::getSize()
{
	 int size = 0;
	Node* temp = top;
	if (temp->ptr == nullptr)
	{
		return 0;
	}
	else
	{
		while (temp != nullptr)
		{
			++size;
			temp = temp->ptr;
		}
	}
	return size;
}

void Stack::swap(Stack& stack)
{
	
	Node* temp = this->top;
	this->top = stack.top;
	stack.top = temp;
}

int Stack::topVal()
{
	if (isEmpty())
	{
		throw"Empty Stack\n";
    }
	return top->val;
}
