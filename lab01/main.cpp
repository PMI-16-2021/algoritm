#include <iostream>
#include "sorting.h"
using namespace std;

int main() {
    int arr[10] = {4,7,6,6,1,4,9,3,5,1};
    PrintArray(arr, 10);
    BubbleSort(arr, 10);
    cout << "\nArray sorted via bubble sort: ";
    PrintArray(arr, 10);
    cout << "\n";
    int brr[10] = {6,2,6,2,1,5,8,3,4,1};
    PrintArray(brr, 10);
    QuickSort(brr, 0, 9);
    cout << "\nArray sorted via quick sort: ";
    PrintArray(brr, 10);
    cout << "\n";
    int crr[10] = {1,7,3,2,6,5,8,9,4,9};
    PrintArray(crr, 10);
    MergeSort(crr, 0, 9, 10);
    cout << "\nArray sorted via merge sort: ";
    PrintArray(crr, 10);
    cout << "\n";
    int drr[10] = {5,9,2,1,4,3,4,7,8,7};
    PrintArray(drr, 10);
    ShellSort(drr, 10);
    cout << "\nArray sorted via shell sort: ";
    PrintArray(drr, 10);
    return 0;
}
