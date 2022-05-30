#include "set.h"
Set::Set():count(0),size(10)
{
    arr = new char [size];
}

Set::Set(size_t capacity) :count(0)
{
    this->size = capacity;
    arr = new char[capacity];
}
void Set::add(char item)
{
    if (!inSet(item)) //check if set already contains this value
    {
        if (count == size)
        {
            size += 10;
            char *temp = new char[size]; // create new array with bigger size
            for (int i = 0; i < count; ++i)
            {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[count] = item;
        ++count;
    }
}

void Set::print() const
{
    std::cout << "{ ";
    for (int i = 0; i < count-1; ++i)
    {
        std::cout  << arr[i] << ", ";
    }
    for (int i = count-1; i < count; ++i) // for good printing
    {
        std::cout  << arr[i] ;
    }
    std::cout << "}\n";
}

size_t Set::len() const
{
    return count;
}

bool Set::inSet(char item) const
{
    for (int i = 0; i < count; ++i)
    {
        if (arr[i] == item)
        {
            return true;
        }
    }
    return false;
}

void Set::del(char item)
{
    if (!(inSet(item)))
    {
        throw "not found";
    }
    char *newArray = new char[size];
    size_t pos = 0;
    if (count > 0)
    {
        for (int i = 0; i < count; ++i)
        {
            if (arr[i] == item)
            {
                pos = i;
                break;
            }
        }
    }
    for (int i = 0; i < pos; ++i)
    {
        newArray[i] = arr[i];
    }
    for (int i = pos; i < count; ++i)
    {
        newArray[i] = arr[i + 1];
    }
    if (count > 0)
    {
        delete[] arr;
    }
    arr = newArray;
    --count;
}

Set Set::unionSet(Set &S) const
{
    Set newSet;
    for (int i = 0; i < count; ++i)
    {
        newSet.add(arr[i]); //add elements from first set
    }
    for (int i = 0; i < S.count; ++i)
    {
        newSet.add(S.arr[i]);//add elements from second set
    }
    return newSet;
}

Set Set::intersection(Set &S)
{
    Set newSet;
    for (int i = 0; i < count; ++i)
    {
        if (S.inSet(arr[i]))
        {
            newSet.add(arr[i]);
        }
    }
    return newSet;
}

Set Set::difference(Set &S)
{
    Set newSet;
    for (int i = 0; i < count; ++i)
    {
        if (!(S.inSet(arr[i])))
        {
            newSet.add(arr[i]);
        }
    }
    return newSet;
}

Set Set::symmetricDifference(Set &S)
{
    Set newSet;
    Set intrsecSet = intersection(S);
    for (int i = 0; i < count; ++i)
    {
        if (!(intrsecSet.inSet(arr[i])))
        {
            newSet.add(arr[i]);
        }
    }
    for (int i = 0; i < S.count; ++i)
    {
        if (!(intrsecSet.inSet(S[i])))
        {
            newSet.add(S[i]);
        }
    }
    return newSet;
}

char &Set::operator[](int i)
{
    if (i > count || i < 0)
    {
        throw "there is no such element";
    }
    return arr[i];
}




