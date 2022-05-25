#include <iostream>
#include "algorithm1.h"


int main()
{
    int arr[] = { 54, 14, 85, 12, 22, 11, 67 };
    int n = sizeof(arr) / sizeof(arr[0]);
    bubbleSort(arr, n);
    std::cout << "Sorted array: \n";
    printArray(arr, n);
    return 0;
}