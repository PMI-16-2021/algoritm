#include"SetOfStacks.h"

SetOfStacks::SetOfStacks()
	:max_Size(0),sizeOfSet(0)
{
	pointer = nullptr;
}

SetOfStacks::SetOfStacks(Stack* ptr, int max)
	:max_Size(max),sizeOfSet(0)
{
	
	pointer = ptr;
}

SetOfStacks::SetOfStacks(int val, int max)
	:max_Size(0),sizeOfSet(0)
{
	pointer = new Stack(val);
}

void SetOfStacks::push(int val)
{
	if (pointer != nullptr && pointer->getSize() < max_Size)
	{
		pointer->push(val);
	}
	else
	{
		Stack* newStack = new Stack(val);
		newStack->next = pointer;
		pointer = newStack;
	}
	++sizeOfSet;
}

void SetOfStacks::pop()
{
	Stack* temp = pointer;
	if (temp->isEmpty())
	{
		throw "\nEmpty Stack";
	}
	
	else
	{
		pointer = pointer->next;
		pointer->Pop();
	}
}

void SetOfStacks::popAt(int index)
{
	if (index <= 0 || index > getSize())
	{
		throw "\nThis stack does not exist\n";
	}
	else
	{
		Stack* temp = pointer;
		for (int i = 0; i < index - 1; ++i)
		{
			temp = temp->next;
		}
		temp->Pop();
	}
}

void SetOfStacks::printSet()
{
	int sizeSet = getSize();
	Stack* temp = pointer;
	if (temp == nullptr)
	{
		throw"\nSet of stacks is empty\n";
	}
	else
	{
		for (int i = 0; i < sizeSet;++i)
		{
			std::cout << "Stack ? " << i + 1 << endl;
			temp->print();
			temp = temp->next;
		}
	}
}

int SetOfStacks::getSize() const
{
	int size_ = 0;
	Stack* temp;
	if (pointer == nullptr)
	{
		return 0;
	}
	else
	{
		temp = pointer;
		while (temp != nullptr)
		{
			++size_;
			temp = temp->next;
		}
	}
	return size_;
}


