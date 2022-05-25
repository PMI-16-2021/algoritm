#include <iostream>
#include "algorithm4.h"
using namespace std;

// Сортування Шелла
void shellSort(int array[], int n) {
    // Переставляти елементи через кожний n/2, n/4, n/8, ... інтервал
    for (int interval = n / 2; interval > 0; interval /= 2)
    {
        for (int i = interval; i < n; ++i) {
            int temp = array[i];
            int j;
            for (j = i; j >= interval && array[j - interval] > temp; j -= interval) {
                array[j] = array[j - interval];
            }
            array[j] = temp;
        }
    }
}

void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}
