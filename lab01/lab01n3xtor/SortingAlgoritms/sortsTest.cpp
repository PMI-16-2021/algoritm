#include "sortsTest.h"
#include "sorts.h"
#include <iostream>
#include <cassert>
using namespace std;

int Test1_1()
{
    int arr[8] = { 6,7,15,16,45,45,76,88 };
    bubbleSort(arr, 8);
    int arrSorted[8] = { 6,7,15,16,45,45,76,88 };
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -1;
        }
    }
    return 1;
}

int Test1_2()
{
    int arr[8] = { 88,76,45,45,16,15,7,6 };
    bubbleSort(arr, 8);
    int arrSorted[8] = { 6,7,15,16,45,45,76,88 };
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -1;
        }
    }
    return 1;
}

int Test1_3()
{
    int arr[8] = { 45,76,16,15,6,45,7,88 };
    bubbleSort(arr, 8);
    int arrSorted[8] = { 6,7,15,16,45,45,76,88 };
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -1;
        }
    }
    return 1;
}

void bubbleSortTest()
{
    assert(Test1_1() == 1);
    cout << "Bubble sort (ordered array) test passed\n";
    assert(Test1_2() == 1);
    cout << "Bubble sort (reversed array) test passed\n";
    assert(Test1_3() == 1);
    cout << "Bubble sort (random array) test passed\n\n";
}

int Test2_1()
{
    int arr[8] = { 6,7,15,16,45,45,76,88 };
    quickSort(arr, 8);
    int arrSorted[8] = { 6,7,15,16,45,45,76,88 };
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -2;
        }
    }
    return 2;
}

int Test2_2()
{
    int arr[8] = { 88,76,45,45,16,15,7,6 };
    quickSort(arr, 8);
    int arrSorted[8] = { 6,7,15,16,45,45,76,88 };
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -2;
        }
    }
    return 2;
}

int Test2_3()
{
    int arr[8] = { 45,76,16,15,6,45,7,88 };
    quickSort(arr, 8);
    int arrSorted[8] = { 6,7,15,16,45,45,76,88 };
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -2;
        }
    }
    return 2;
}

void quickSortTest()
{
    assert(Test2_1() == 2);
    cout << "Quick sort (ordered array) test passed\n";
    assert(Test2_2() == 2);
    cout << "Quick sort (reversed array) test passed\n";
    assert(Test2_3() == 2);
    cout << "Quick sort (random array) test passed\n\n";
}

int Test3_1()
{
    int arr[8] = {6,7,15,16,45,45,76,88};
    countingSort(arr, 8);
    int arrSorted[8] = { 6,7,15,16,45,45,76,88 };
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -3;
        }
    }
    return 3;
}

int Test3_2()
{
    int arr[8] = {88,76,45,45,16,15,7,6};
    countingSort(arr, 8);
    int arrSorted[8] = {6,7,15,16,45,45,76,88};
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -3;
        }
    }
    return 3;
}

int Test3_3()
{
    int arr[8] = { 45,76,16,15,6,45,7,88};
    countingSort(arr, 8);
    int arrSorted[8] = {6,7,15,16,45,45,76,88};
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -3;
        }
    }
    return 3;
}

void countingSortTest()
{
    assert(Test3_1() == 3);
    cout << "Counting sort (ordered array) test passed\n";
    assert(Test3_2() == 3);
    cout << "Counting sort (reversed array) test passed\n";
    assert(Test3_3() == 3);
    cout << "Counting sort (random array) test passed\n\n";
}

int Test4_1()
{
    int arr[8] = { 6,7,15,16,45,45,76,88 };
    shellSort(arr, 8);
    int arrSorted[8] = { 6,7,15,16,45,45,76,88 };
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -4;
        }
    }
    return 4;
}

int Test4_2()
{
    int arr[8] = { 88,76,45,45,16,15,7,6 };
    shellSort(arr, 8);
    int arrSorted[8] = { 6,7,15,16,45,45,76,88 };
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -4;
        }
    }
    return 4;
}

int Test4_3()
{
    int arr[8] = { 45,76,16,15,6,45,7,88 };
    shellSort(arr, 8);
    int arrSorted[8] = { 6,7,15,16,45,45,76,88 };
    for (size_t i = 0; i < 8; ++i)
    {
        if (arr[i] != arrSorted[i])
        {
            return -4;
        }
    }
    return 4;
}

void shellSortTest()
{
    assert(Test4_1() == 4);
    cout << "Shell sort (ordered array) test passed\n";
    assert(Test4_2() == 4);
    cout << "Shell sort (reversed array) test passed\n";
    assert(Test4_3() == 4);
    cout << "Shell sort (random array) test passed";
}
