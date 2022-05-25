//
// Created by Ostap Kilbasovych on 22.02.2022.
//
#include <iostream>
#include "BubbleSorting.h"


void swap(int *Ap, int *Bp) {
    int temp = *Ap;
    *Ap = *Bp;
    *Bp = temp;
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        for (int j = 0; j < n - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
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
