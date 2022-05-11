#pragma once
#include "stack.h"

template <typename T>
bool testEmpty()
{
    Stack<T> S;
    S.empty();
    if (S.size() == 0)
        return true;
    return false;
}

template <typename T>
void resultEmpty()
{
    assert(testEmpty<T>() == true);
    std::cout << "TestEmpty is passed\n";
}

template <typename T>
bool testPush()
{
    Stack<T> S;
    S.push(1);
    if (S.size() == 1)
        return true;
    return false;
}

template <typename T>
void resultPush()
{
    assert(testPush<T>() == true);
    std::cout << "TestPush is passed\n";
}

template <typename T>
bool testPop()
{
    Stack<T> S;
    S.push(1);
    S.pop();
    if (S.size() == 0)
        return true;
    return false;
}

template <typename T>
void resultPop()
{
    assert(testPop<T>() == true);
    std::cout << "TestPop is passed\n";
}

template <typename T>
bool testSize()
{
    Stack<T> S;
    S.push(1);
    S.push(10);
    if (S.size() == 2)
        return true;
    return false;
}

template <typename T>
void resultSize()
{
    assert(testSize<T>() == true);
    std::cout << "TestSize is passed\n";
}

template <typename T>
bool testTop()
{
    Stack<T> S;
    S.push(1);
    if (S.Top() == 1)
        return true;
    return false;
}

template <typename T>
void resultTop()
{
    assert(testTop<T>() == true);
    std::cout << "TestTop is passed\n";
}

template <typename T>
bool testEmplace()
{
    Stack<T> S;
    S.emplace(1);
    if (S.Top() == 1)
        return true;
    return false;
}

template <typename T>
void resultEmplace()
{
    assert(testEmplace<T>() == true);
    std::cout << "TestEmplace is passed\n";
}

template <typename T>
bool testSwap()
{
    Stack<T> S1;
    Stack<T> S2;
    S1.push(1);
    S1.push(2);
    S2.push(3);
    S2.push(4);
    S1.swap(S2);
    if (S1.Top() == 4)
        return true;
    return false;
}

template <typename T>
void resultSwap()
{
    assert(testSwap<T>() == true);
    std::cout << "TestSwap is passed\n";
}

template <typename T>
bool testIsEmpty()
{
    Stack<T> S;
    S.push(1);
    S.pop();
    if (S.isEmpty() == true)
        return true;
    return false;
}

template <typename T>
void resultIsEmpty()
{
    assert(testIsEmpty<T>() == true);
    std::cout << "TestIsEmpty is passed\n";
}

