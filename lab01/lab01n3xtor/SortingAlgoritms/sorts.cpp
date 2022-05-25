#include "sorts.h"
#include <iostream>
using namespace std;

void printArray(int arr[], size_t arrSize)
{
    for (size_t i = 0; i < arrSize; ++i)
    {
        cout << "  " << arr[i];
    }
    cout << "\n\n";
}

void bubbleSort(int arr[], size_t arrSize)
{
    int tmp = 0;
    for (size_t i = 0; i < arrSize; i++) {
        for (size_t j = (arrSize - 1); j >= (i + 1); j--) {
            if (arr[j] < arr[j - 1]) {
                tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void quickSort(int* arr, size_t const arrSize)
{
    int const lenD = arrSize;
    int pivot = 0;
    int ind = lenD / 2;
    int i, j = 0, k = 0;
    if (lenD > 1) {
        int* L = new int[lenD];
        int* R = new int[lenD];
        pivot = arr[ind];
        for (i = 0; i < lenD; i++) {
            if (i != ind) {
                if (arr[i] < pivot) {
                    L[j] = arr[i];
                    j++;
                }
                else {
                    R[k] = arr[i];
                    k++;
                }
            }
        }
        quickSort(L, j);
        quickSort(R, k);
        for (size_t cnt = 0; cnt < lenD; cnt++) {
            if (cnt < j) {
                arr[cnt] = L[cnt];;
            }
            else if (cnt == j) {
                arr[cnt] = pivot;
            }
            else {
                arr[cnt] = R[cnt - (j + 1)];
            }
        }
    }
}

void ñountingSort(int arr[], size_t arrSize)
{
    int max = INT_MIN, min = INT_MAX;
    for (size_t i = 0; i < arrSize; i++)
    {
        if (arr[i] > max)
            max = arr[i];
        if (arr[i] < min)
            min = arr[i];
    }
    int* c = new int[max + 1 - min];
    for (size_t i = 0; i < max + 1 - min; i++)
    {
        c[i] = 0;
    }
    for (size_t i = 0; i < arrSize; i++)
    {
        c[arr[i] - min] = c[arr[i] - min] + 1;
    }
    int i = 0;
    for (size_t j = min; j < max + 1; j++)
    {
        while (c[j - min] != 0)
        {
            arr[i] = j;
            c[j - min]--;
            i++;
        }
    }
}

void shellSort(int arr[], size_t arrSize)
{
    int i, j, step;
    int tmp;
    for (step = arrSize / 2; step > 0; step /= 2)
        for (i = step; i < arrSize; i++)
        {
            tmp = arr[i];
            for (j = i; j >= step; j -= step)
            {
                if (tmp < arr[j - step])
                    arr[j] = arr[j - step];
                else
                    break;
            }
            arr[j] = tmp;
        }
}
