#pragma once

#include <iostream>

template<typename T>
class MySet
{
private:
    T* mySetArray;
    size_t mySetCount;
    size_t mySetCapacity;
public:
    MySet() 
    {
        mySetCount = 0;
        mySetCapacity = 30;
        mySetArray = new T[mySetCapacity];
    }
    MySet(size_t mySetCapacity) 
    {
        mySetCount = 0;
        this->mySetCapacity = mySetCapacity;
        mySetArray = new T[mySetCapacity];
    }

    ~MySet() 
    {
    }

    void add(T value);
    void remove(T value);
    int length() const;
    bool contains(T value);
    MySet unionSet(MySet& anotherSet);
    MySet intersection(MySet& anotherSet);
    MySet difference(MySet& anotherSet);
    MySet symmetricDifference(MySet& anotherSet);
    void print() const;
    T& operator[](size_t i);
    const T& operator[](size_t i) const;

};

template<typename T>
void MySet<T>::add(T value) 
{
    if (!contains(value))
    {
        if (mySetCount == mySetCapacity)
        {
            mySetCapacity += 5;
            T* tempArray = new T[mySetCapacity];
            for (size_t i = 0; i < mySetCount; ++i)
            {
                tempArray[i] = mySetArray[i];
                
            }
            delete[] mySetArray;
            mySetArray = tempArray;
            tempArray = nullptr;
        }

        mySetArray[mySetCount] = value;
        ++mySetCount;
    }
    else
    {
        throw std::out_of_range("YOU CAN NOT ADD THIS value");
    }
}

template<typename T>
void MySet<T>::remove(T value)
{
    if (!(contains(value)))
    {
        throw std::out_of_range("You tried to delete value that doesn't exist");
    }
    T* newMySetArray = new T[mySetCapacity];
    size_t position = 0;
    if (mySetCount > 0)
    {
        for (size_t i = 0; i < mySetCount; ++i)
        {
            if (mySetArray[i] == value)
            {
                position = i;
                break;
            }
        }
    }
    for (size_t i = 0; i < position; ++i)
    {
        newMySetArray[i] = mySetArray[i];
    }
    for (size_t k = position; k < mySetCount; ++k)
    {
        newMySetArray[k] = mySetArray[k + 1];
    }
    if (mySetCount > 0)
    {
        delete[] mySetArray;
    }
    mySetArray = newMySetArray;
    --mySetCount;
}


template<typename T>
void MySet<T>::print() const
{
    std::cout << "{ ";
    for (size_t i = 0; i < mySetCount; ++i)
    {
        std::cout << "(" << mySetArray[i] << ") ";
    }
    std::cout << "}\n";
}

template<typename T>
int MySet<T>::length() const
{
    return mySetCount;
}

template<typename T>
bool MySet<T>::contains(T value) 
{
    for (size_t i = 0; i < mySetCount; ++i)
    {
        if (mySetArray[i] == value)
        {
            return true;
        }
    }
    return false;
}

template<typename T>
MySet<T> MySet<T>::unionSet(MySet& anotherSet)
{
    MySet<T> newMySet;
    for (size_t i = 0; i < length(); ++i) 
    {
        newMySet.add(mySetArray[i]);
    }
    for (size_t k = 0; k < anotherSet.length(); ++k) 
    {
        try
        {
            newMySet.add(anotherSet.mySetArray[k]);
        }
        catch (std::out_of_range& exception)
        {
            continue;
        }
    }
    return newMySet;
}

template<typename T>
T& MySet<T>::operator[](size_t i)
{
    if (i > mySetCount || i < 0)
    {
        throw std::out_of_range("You tried to access value that doesn't exist");
    }
    return mySetArray[i];
}

template<typename T>
const T& MySet<T>::operator[](size_t i) const
{
    if (i > mySetCount || i < 0) 
    {
        throw std::out_of_range("You tried to access value that doesn't exist");
    }
    return mySetArray[i];
}

template<typename T>
MySet<T> MySet<T>::intersection(MySet& anotherSet) 
{
    MySet<T> newMySet;
    for (size_t i = 0; i < length(); ++i) 
    {
        if (anotherSet.contains(mySetArray[i])) 
        {
            newMySet.add(mySetArray[i]);
        }
    }
    return newMySet;
}

template<typename T>
MySet<T> MySet<T>::difference(MySet& anotherSet) 
{
    MySet<T> newMySet;
    for (size_t i = 0; i < mySetCount; ++i) 
    {
        if (!(anotherSet.contains(mySetArray[i])))
        {
            newMySet.add(mySetArray[i]);
        }
    }
    return newMySet;
}

template<typename T>
MySet<T> MySet<T>::symmetricDifference(MySet& anotherSet) 
{
    MySet<T> newMySet;
    MySet<T> intersectionSet = intersection(anotherSet);
    for (size_t i = 0; i < mySetCount; ++i) 
    {
        if (!(intersectionSet.contains(mySetArray[i]))) 
        {
            newMySet.add(mySetArray[i]);
        }
    }
    for (size_t k = 0; k < anotherSet.mySetCount; ++k) 
    {
        if (!(intersectionSet.contains(anotherSet[k]))) 
        {
            newMySet.add(anotherSet[k]);
        }
    }
    return newMySet;
}

