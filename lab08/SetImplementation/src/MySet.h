#pragma once

#include "NotUniqueElementException.h"
#include "ElementNotFoundException.h"
#include <iostream>

template<typename T>
class MySet {
private:
    T *dynamicArrayOfT;
    size_t count;
    size_t capacity;
public:
    //constructor without parameters
    MySet() {
        count = 0;
        capacity = 20;
        dynamicArrayOfT = new T[capacity];
    }

    //constructor that takes capacity of Set as an argument
    MySet(size_t capacity) {
        count = 0;
        this->capacity = capacity;
        dynamicArrayOfT = new T[capacity];
    }

    // destructor
    ~MySet() {
    }

    //method that adds elements into a Set
    void Add(T element);

    //method that remove element from a Set
    void Remove(T element);

    //method that returns current amount of elements in a Set
    size_t Length() const;

    //method that checks whether element present in a Set
    bool Contains(T element) const;

    //method that unions current set with another
    MySet UnionSet(MySet &anotherSet) const;

    //method that creates intersection of current set and another
    MySet Intersection(MySet &anotherSet);

    //method that creates difference of current set and another
    MySet Difference(MySet &anotherSet);

    //method that creates symmetric difference of current set and another
    MySet SymmetricDifference(MySet &anotherSet);

    //method that prints Set to console output
    void Print() const;

    //get access to elements of the set by operator []
    T &operator[](size_t i);

    const T &operator[](size_t i) const;
};

template<typename T>
void MySet<T>::Add(T element) {
    if (!Contains(element)) {
        if (count == capacity) {
            capacity += 5;
            T *tempArray = new T[capacity];
            for (size_t i = 0; i < count; ++i) {
                tempArray[i] = dynamicArrayOfT[i];
            }
            delete[] dynamicArrayOfT;
            dynamicArrayOfT = tempArray;
        }

        dynamicArrayOfT[count] = element;
        ++count;
    } else {
        throw NotUniqueElementException(element);
    }
}

template<typename T>
void MySet<T>::Print() const {
    std::cout << "{ ";
    for (size_t i = 0; i < count; ++i) {
        std::cout << "{" << dynamicArrayOfT[i] << "} ";
    }
    std::cout << "}\n";
}

template<typename T>
size_t MySet<T>::Length() const {
    return count;
}

template<typename T>
bool MySet<T>::Contains(T element) const {
    for (size_t i = 0; i < count; ++i) {
        if (dynamicArrayOfT[i] == element) {
            return true;
        }
    }
    return false;
}

template<typename T>
void MySet<T>::Remove(T element) {
    if (!(Contains(element))) {
        throw ElementNotFoundException(element);
    }
    T *newDynamicArrayOfT = new T[capacity];
    //find position of this element
    size_t position = 0;
    if (count > 0) {
        for (size_t i = 0; i < count; ++i) {
            if (dynamicArrayOfT[i] == element) {
                position = i;
                break;
            }
        }
    }
    //add all elements before deleted element
    for (size_t i = 0; i < position; ++i) {
        newDynamicArrayOfT[i] = dynamicArrayOfT[i];
    }
    //add all elements after deleted element
    for (size_t k = position; k < count; ++k) {
        newDynamicArrayOfT[k] = dynamicArrayOfT[k + 1];
    }
    if (count > 0) {
        delete[] dynamicArrayOfT;
    }
    dynamicArrayOfT = newDynamicArrayOfT;
    --count;
}

template<typename T>
MySet<T> MySet<T>::UnionSet(MySet &anotherSet) const {
    MySet<T> newMySet;
    for (size_t i = 0; i < count; ++i) {
        newMySet.Add(dynamicArrayOfT[i]);
    }
    for (size_t k = 0; k < anotherSet.count; ++k) {
        try {
            newMySet.Add(anotherSet.dynamicArrayOfT[k]);
        }
        catch (NotUniqueElementException<T> &notUniqueElementException) {
            continue;
        }
    }
    return newMySet;
}

template<typename T>
T &MySet<T>::operator[](size_t i) {
    if (i > count || i < 0) {
        throw std::out_of_range("You tried to access element that doesn't exist");
    }
    return dynamicArrayOfT[i];
}

template<typename T>
const T &MySet<T>::operator[](size_t i) const {
    if (i > count || i < 0) {
        throw std::out_of_range("You tried to access element that doesn't exist");
    }
    return dynamicArrayOfT[i];
}

template<typename T>
MySet<T> MySet<T>::Intersection(MySet &anotherSet) {
    MySet<T> newMySet;
    for (size_t i = 0; i < count; ++i) {
        if (anotherSet.Contains(dynamicArrayOfT[i])) {
            newMySet.Add(dynamicArrayOfT[i]);
        }
    }
    return newMySet;
}

template<typename T>
MySet<T> MySet<T>::Difference(MySet &anotherSet) {
    MySet<T> newMySet;
    for (size_t i = 0; i < count; ++i) {
        if (!(anotherSet.Contains(dynamicArrayOfT[i]))) {
            newMySet.Add(dynamicArrayOfT[i]);
        }
    }
    return newMySet;
}

template<typename T>
MySet<T> MySet<T>::SymmetricDifference(MySet &anotherSet) {
    MySet<T> newMySet;
    MySet<T> intersectionSet = Intersection(anotherSet);
    for (size_t i = 0; i < count; ++i) {
        if (!(intersectionSet.Contains(dynamicArrayOfT[i]))) {
            newMySet.Add(dynamicArrayOfT[i]);
        }
    }
    for (size_t k = 0; k < anotherSet.count; ++k) {
        if (!(intersectionSet.Contains(anotherSet[k]))) {
            newMySet.Add(anotherSet[k]);
        }
    }
    return newMySet;
}

