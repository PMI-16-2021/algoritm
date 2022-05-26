//
// Created by Ostap Kilbasovych on 11.03.2022.
//

#include "QuickSorting.h"
#include <iostream>

void swap(int *Ap, int *Bp) {
    int temp = *Ap;
    *Ap = *Bp;
    *Bp = temp;
}

int partition(int arr[], int start, int end) {

    int pivot = arr[start];

    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot) {
            count++;
        }
    }

    int pivotIndex = start + count;

    swap(&arr[pivotIndex], &arr[start]);


    int i = start, j = end;


    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot) {
            i++;
        }

        while (arr[j] > pivot) {
            j--;
        }

        if (i < pivotIndex && j > pivotIndex) {
            swap(&arr[i++], &arr[j--]);
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int start, int end) {

    if (start >= end) {
        return;
    }

    int p = partition(arr, start, end);

    quickSort(arr, start, p - 1);

    quickSort(arr, p + 1, end);
}


void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}


std::string arrayToString(int *arr, int size) {

    std::string str;
    for (int i = 0; i < size; ++i) {
        str = str + std::to_string(arr[i]) + " ";
    }

    return str;
}