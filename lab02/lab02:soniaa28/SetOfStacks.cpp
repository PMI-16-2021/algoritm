
#include "SetOfStacks.h"

SetOfStacks::SetOfStacks(Stack *ptr, int max): maxSize(max)
{
 pointer=ptr; // pointer to head

}

SetOfStacks::SetOfStacks() :maxSize(0)
{
 pointer= nullptr;
}

SetOfStacks::SetOfStacks(int value, int max) :maxSize(max)
{

  pointer = new Stack(value);

}

void SetOfStacks::push(int value)
{
  if(pointer!= nullptr && pointer->getSize() < maxSize)
  {
      pointer->push(value);
  }
  else{
      Stack* newStack = new Stack(value);
      newStack->next= pointer;
      pointer = newStack;

  }
    ++sizeOfSet;
}

void SetOfStacks::pop()
{
    Stack* temp=pointer;
    if(temp->isEmpty())
    {
     throw  " Stack is empty";
    }
    else if(pointer->isEmpty())
    {
     pointer=pointer->next;
    }
    else
    {
     pointer->pop();
    }

}

void SetOfStacks::popAt(int index)
{
    if (index <= 0 || index > getSize())
    {
       throw "\n This stack does not exist\n";
    } else {
        Stack *temp = pointer;
        for (int i = 0; i < index - 1; ++i)
        {
            temp = temp->next;
        }
        temp->pop();
    }
}


void SetOfStacks::printSet()
{
    int sizeSet = getSize();
    Stack* temp = pointer;

    if (temp == nullptr)
    {
        throw "\n Set of stacks is empty\n";

    }
    else
    {
        for (int i = 0; i < sizeSet; ++i)
        {
            std::cout << "Stack № " << i + 1 << "\n";
            temp->print();
            temp = temp->next;
        }
    }
}
int SetOfStacks::getSize() const
{
    int _size = 0;
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
            ++_size;
            temp = temp->next;
        }
    }
    return _size;
}