#include "sort.h"
#include <iostream>

void ReadArray(int* array, int size) {
    for (int index = 0; index < size; ++index) {
        std::cin >> array[index];
    }

}
void PrintArray(int* array, int size) {
    std::cout << "Array: ";
    for (int index = 0; index < size; ++index) {
        std::cout << array[index] << ' ';
    }
}

void Swap(int& first, int& second) {
    int to_swap = first;
    first = second;
    second = to_swap;

}

void BubbleSort(int* array, int size) {
    for (int last_unsorted = 0; last_unsorted < size - 1; ++last_unsorted) {
        for (int index = 0; index < size - last_unsorted - 1; ++index) {
            if (array[index] > array[index + 1]) {
                Swap(array[index], array[index + 1]);
            }
        }
    }
}

void QuickSort(int* array, int left, int right) {
    int pivot_element = array[(left + right) / 2];
    int i = left;
    int j = right;
    while (i <= j) {
        while (array[i] < pivot_element) {
            ++i;
        }
        while (array[j] > pivot_element) {
            --j;
        }
        if (i <= j) {
            Swap(array[i], array[j]);
            ++i;
            --j;
        }
    }
    if (j > left) {
        QuickSort(array, left, j);
    }
    if (i < right) {
        QuickSort(array, i, right);
    }

}

void CountingSort(int* array, int size) {
    int max_element = 0;
    for (int i = 0; i < size; ++i) {
        if (max_element < array[i]) {
            max_element = array[i];
        }
    }
    int* freq_array = new int[max_element + 1];
    for (int i = 0; i < max_element + 1; ++i) {
        freq_array[i] = 0;
    }
    for (int i = 0; i < size; ++i) {
        ++freq_array[array[i]];
    }

    for (int i = 0, j = 0; i <= max_element; ++i) {
        while (freq_array[i] > 0) {
            array[j] = i;
            ++j;
            --freq_array[i];
        }
    }

    delete[] freq_array;
}

void ShellSort(int* array, int size) {
    for (int interval = size / 2; interval >= 1; interval /= 2) {
        for (int i = interval; i < size; ++i) {
            for (int j = i; j >= interval && array[j - interval] > array[j]; j -= interval) {
                Swap(array[j], array[j - interval]);
            }
        }
    }
}

