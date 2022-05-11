#pragma once
#include "stack.h"

template <typename T>
class SetOfStacks
{
private:
    Stack<T>* arr_of_stacks;
    int each_size;
    int max_size;
    int counter;
public:
    SetOfStacks();
    SetOfStacks(int set_size, int set_max_size);
    ~SetOfStacks();

    void push(T value);
    T pop();
    T popAt(int index);
    void print() const;
};

template <typename T>
SetOfStacks<T>::SetOfStacks() : each_size(5), max_size(3), counter(0)
{
    arr_of_stacks = new Stack<T>[max_size];
}

template <typename T>
SetOfStacks<T>::SetOfStacks(int set_size, int set_max) : each_size(set_size), max_size(set_max), counter(0)
{
    arr_of_stacks = new Stack<T>[set_max];
}

template <typename T>
SetOfStacks<T>::~SetOfStacks()
{
    delete[] arr_of_stacks;
}

template <typename T>
void SetOfStacks<T>::push(T value)
{
    if (arr_of_stacks[counter].size() < each_size)
    {
        arr_of_stacks[counter].push(value);
        return;
    }
    else if (arr_of_stacks[counter].size() == each_size && counter < max_size)
    {
        ++counter;
        arr_of_stacks[counter].push(value);
        return;
    }
    else if (arr_of_stacks[counter].size() == each_size && counter == max_size)
    {
        return;
    }
}

template <typename T>
T SetOfStacks<T>::pop()
{
    if (counter == 0 && arr_of_stacks[counter].isEmpty())
    {
        throw "Stack is empty\n";
    }
    else if (counter > 0 && arr_of_stacks[counter].isEmpty())
    {
        while (counter > 0 && arr_of_stacks[counter].isEmpty())
            --counter;
        arr_of_stacks[counter].pop();
    }
    else
    {
        arr_of_stacks[counter].pop();
    }
}

template <typename T>
T SetOfStacks<T>::popAt(int index)
{
    if (index < 0 && index > each_size - 1)
    {
        throw "This index is not acceptable\n";
    }
    else if (arr_of_stacks[index].isEmpty())
    {
        throw "This index is empty\n";
    }
    else
    {
        arr_of_stacks[index].pop();
    }
}

template <typename T>
void SetOfStacks<T>::print() const
{
    for (int i = 0; i < counter; ++i)
    {
        arr_of_stacks[i].print();
        std::cout << "\n";
    }
}