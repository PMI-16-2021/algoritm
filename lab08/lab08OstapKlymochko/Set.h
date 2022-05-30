#pragma once

#include <vector>

using namespace std;

template<typename Type>
class Set
{
private:

    vector<Type> array;

public:

    bool find(const Type& data);
    void insert(const Type& data);
    void erase(const Type& data);
    void clear();
    size_t size();
    bool empty();
};

template<typename Type>
bool Set<Type>::find(const Type& data)
{
    for (auto& element : array)
    {
        if (data == element)
        {
            return true;
        }
    }
    return false;
}

template<typename Type>
void Set<Type>::insert(const Type& data)
{
    if (find(data))
    {
        return;
    }

    array.emplace_back(data);
}

template<typename Type>
void Set<Type>::erase(const Type& data)
{
    int i = 0;
    for (auto it = array.begin(); it <= array.end(); it++)
    {
        if (array[i] == data)
        {
            array.erase(it);
            return;
        }
        i++;
    }
    throw("The element isn't in the array");
}

template<typename Type>
void Set<Type>::clear()
{
    array.clear();
}

template<typename Type>
size_t Set<Type>::size()
{
    return array.size();
}

template<typename Type>
bool Set<Type>::empty()
{
    return array.empty();
}