//
// Created by Ostap Kilbasovych on 11.03.2022.
//

#include <iostream>
#include "ShellSorting.h"

void shellSort(int arr[], int size) {
    for (int gap = size / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < size; ++i) {

            int temp = arr[i];

            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
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