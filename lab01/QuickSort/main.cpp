#include <iostream>
#include "algorithm2.h"

int main()
{
    int arr[] = { 12,23,3,43,51,35,19,45 };
    int n = sizeof(arr) / sizeof(arr[0]);
    std::cout << "Input array" << '\n';
    displayArray(arr, n);
    std::cout << '\n';
    quickSort(arr, 0, n - 1);
    std::cout << "Array sorted with quick sort" << '\n';
    displayArray(arr, n);
    return 0;
}