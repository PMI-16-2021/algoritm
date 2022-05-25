#include<iostream>
#include "algorithm4.h"

int main()
{
    int data[] = { 13, 11, 3, 15, 5, 6, 2, 1 };
    int size = sizeof(data) / sizeof(data[0]);
    shellSort(data, size);
    std::cout << "Sorted array: \n";
    printArray(data, size);
}