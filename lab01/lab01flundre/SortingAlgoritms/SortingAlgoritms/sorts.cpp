#include <iostream>
#include "sorts.h"


void BubbleSort(int* arr, int n) {
    int temp;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void QuickSort(int* arr, int first, int last) {
    int middle = arr[(first + last) / 2];
    int i = first;
    int j = last;
    while (i <= j) {
        while (arr[i] < middle) {
            i++;
        }
        while (arr[j] > middle) {
            j--;
        }
        if (i <= j) {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            ++i;
            --j;
        }
    }

    if (i < last) {
        QuickSort(arr, i, last);
    }

    if (j > first) {
        QuickSort(arr, first, j);
    }
    

}

void ShellSort(int* arr, int n){
    
    for (int d = n / 2; d >= 1; d /= 2) {
        for (int i = d; i < n; i++) {
            for (int j = i; j >= d && arr[j - d] > arr[j]; j -= d) {
                int temp = arr[j];
                arr[j] = arr[j - d];
                arr[j - d] = temp;
            }
        }
    }

    
}

void CountingSort(int* arr, int n) {
    int* sorted_arr = new int[n];
    int* count = new int[n];
    int max = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }

    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
    }

    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--) {
        sorted_arr[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }
}



void PrintArray(int *arr, int n)
{
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << '\n';
}