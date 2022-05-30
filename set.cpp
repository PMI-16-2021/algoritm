#include "set.h"

MySet::MySet() : counter(0), size(5)
{
    arr = new char[size];
}

MySet::MySet(int newSize) : counter(0), size(newSize)
{
    arr = new char[newSize];
}

MySet::~MySet()
{
    delete[] arr;
}

bool MySet::in(char element) const
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == element)
            return true;
    }
    return false;
}

void MySet::add(char element)
{
    if (in(element))
        throw "This element is already in set\n";
    if (counter == size)
    {
        size += 5;
        char *temp = new char[size];
        for (int i = 0; i < counter; ++i)
        {
            temp[i] = arr[i];
        }
        delete[] arr;
        arr = temp;
    }
    arr[counter] = element;
    ++counter;
}

void MySet::remove(char element)
{
    if (!in(element))
        throw "Element is not found\n";
    int delIndex;
    for (int i = 0; i < counter; ++i)
    {
        if (arr[i] == element)
            delIndex = i;
    }
    char *temp = new char[size];
    for (int i = 0; i < delIndex; ++i)
    {
        temp[i] = arr[i];
    }
    for (int i = delIndex + 1; i < counter; ++i)
    {
        temp[i-1] = arr[i];
    }
    delete[] arr;
    arr = temp;
    --counter;
}

int MySet::len() const
{
    return counter;
}

MySet MySet::unionSet(MySet& other)
{
    MySet united;
    for (int i = 0; i < counter; ++i)
    {
        united.add(arr[i]);
    }
    for (int i = 0; i < other.counter; ++i)
    {
        united.add(other.arr[i]);
    }
    return united;
}

MySet MySet::intersection(MySet& other)
{
    MySet similar;
    for (int i = 0; i < counter; ++i)
    {
        for (int j = 0; j < other.counter; ++j)
        {
            if (arr[i] == other.arr[j])
                similar.add(arr[i]);
        }
    }
    return similar;
}

MySet MySet::difference(MySet& other)
{
    MySet different;
    for (int i = 0; i < counter; ++i)
    {
        if (!(other.in(arr[i])))
        {
            different.add(arr[i]);
        }
    }
    return different;
}

MySet MySet::symmetric_difference(MySet& other)
{
    MySet different1 = difference(other);
    MySet different2 = other.difference(*this);
    for (int i = 0; i < different2.counter; ++i)
    {
        different1.add(different2.arr[i]);
    }
    return different1;
}

void MySet::print() const
{
    for (int i = 0; i < counter; ++i)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << "\n";
}
