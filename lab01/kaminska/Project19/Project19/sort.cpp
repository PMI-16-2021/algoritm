#include "sort.h"
#include <iostream>
using namespace std;

void printArray(int* arr, int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << '\n';
}

void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int* arr, int n) {
    int j = n - 1;
    for (int i = 0; i < n / 2; ++i) {
        swap(&arr[i], &arr[j]);
        --j;
    }
}

void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

void quickSort(int* arr, int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            swap(&arr[i], &arr[j]);
            i++;
            j--;
        }
    };
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int getMax(int* arr, int n) {
    int max = arr[1];
    for (int i = 2; i <= n; i++) {
        if (arr[i] > max)
            max = arr[i];
    }
    return max; 
}

void countSort(int* arr, int n) {
    int* output = new int[n + 1];
    int max = getMax(arr, n);
    int* count = new int[max + 1]; 
    for (int i = 0; i <= max; i++)
        count[i] = 0; 
    for (int i = 0; i < n; i++)
        count[arr[i]]++; 
    for (int i = 1; i <= max; i++)
        count[i] += count[i - 1]; 
    for (int i = n - 1; i >= 0; i--) {
        output[count[arr[i]] - 1] = arr[i];
        count[arr[i]]--; 
    }
    for (int i = 0; i < n; i++) {
        arr[i] = output[i]; 
    }
    delete[]output;
    delete[]count;
}

void shellSort(int* arr, int n)
{
    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; ++i)
        {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
                arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}