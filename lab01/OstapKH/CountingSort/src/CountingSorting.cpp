//
// Created by Ostap Kilbasovych on 12.03.2022.
//
#include <iostream>
#include "CountingSorting.h"

void countSort(int array[], int size) {
    int output[size + 1];

    int max = array[0];

    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    int count[max + 1];

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < size; i++) {
        count[array[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }


    for (int i = size - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }

    for (int i = 0; i < size; i++) {
        array[i] = output[i];
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