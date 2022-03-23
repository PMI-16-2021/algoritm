#include "tests.h"
#include "sorts.h"
#include <iostream>
#include <cassert>

int Test1_01(){
    int arr[10] = {4,43,75,35,5,43,11,57,47,77};
    InsertionSort(arr, 10);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -1;
    }
    return 1;
}
int Test1_02(){
    int arr[10] = {4,5,11,35,43,43,47,57,75,77};
    InsertionSort(arr, 10);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -1;
    }
    return 1;
}
int Test1_03(){
    int arr[10] = {77,75,57,47,43,43,35,11,5,4};
    InsertionSort(arr, 10);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -1;
    }
    return 1;
}
void InsertionSortTest(){
    assert(Test1_01() == 1);
    std::cout<<"Insertion sort (random array) test passed\n";
    assert(Test1_02() == 1);
    std::cout<<"Insertion sort (ordered array) test passed\n";
    assert(Test1_03() == 1);
    std::cout<<"Insertion sort (reversed array) test passed\n";
}
int Test2_01(){
    int arr[10] = {4,43,75,35,5,43,11,57,47,77};
    QuickSort(arr, 0,  9);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -2;
    }
    return 2;
}
int Test2_02(){
    int arr[10] = {4,5,11,35,43,43,47,57,75,77};
    QuickSort(arr, 0,  9);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -2;
    }
    return 2;
}
int Test2_03(){
    int arr[10] = {77,75,57,47,43,43,35,11,5,4};
    QuickSort(arr, 0,  9);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -2;
    }
    return 2;
}
void QuickSortTest(){
    assert(Test2_01() == 2);
    std::cout<<"Quick sort (random array) test passed\n";
    assert(Test2_02() == 2);
    std::cout<<"Quick sort (ordered array) test passed\n";
    assert(Test2_03() == 2);
    std::cout<<"Quick sort (reversed array) test passed\n";
}

int Test3_01(){
    int arr[10] = {4,43,75,35,5,43,11,57,47,77};
    CountingSort(arr, 10);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -3;
    }
    return 3;
}
int Test3_02(){
    int arr[10] = {4,5,11,35,43,43,47,57,75,77};
    CountingSort(arr, 10);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -3;
    }
    return 3;
}
int Test3_03(){
    int arr[10] = {77,75,57,47,43,43,35,11,5,4};
    CountingSort(arr, 10);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -3;
    }
    return 3;
}

void CountingSortTest(){
    assert(Test3_01() == 3);
    std::cout<<"Counting sort (random array) test passed\n";
    assert(Test3_02() == 3);
    std::cout<<"Counting sort (ordered array) test passed\n";
    assert(Test3_03() == 3);
    std::cout<<"Counting sort (reversed array) test passed\n";
}
int Test4_01(){
    int arr[10] = {4,43,75,35,5,43,11,57,47,77};
    MergeSort(arr, 0, 9);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -4;
    }
    return 4;
}
int Test4_02(){
    int arr[10] = {4,5,11,35,43,43,47,57,75,77};
    MergeSort(arr, 0, 9);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -4;
    }
    return 4;
}
int Test4_03(){
    int arr[10] = {77,75,57,47,43,43,35,11,5,4};
    MergeSort(arr, 0, 9);
    int sorted[10] =  {4,5,11,35,43,43,47,57,75,77};
    for (int i = 0; i < 10; ++i) {
        if(arr[i] != sorted[i])
            return -4;
    }
    return 4;
}
void MergeSortTest(){
    assert(Test4_01() == 4);
    std::cout<<"Merge sort (random array) test passed\n";
    assert(Test4_02() == 4);
    std::cout<<"Merge sort (ordered array) test passed\n";
    assert(Test4_03() == 4);
    std::cout<<"Merge sort (reversed array) test passed\n";
}
