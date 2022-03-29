#include "sorting.h"

void PrintArray(int* array, int size) {
    for(int i = 0; i < size; ++i) {
        std::cout << array[i] << ' ';
    }
}
void BubbleSort(int* array, int size) {
    for (int j = 0; j < size-1; ++j) {
        for (int i = 0; i < size-1; ++i) {
            if (array[i] > array[i+1]) {
                int temporary_variable = array[i];
                array[i] = array[i+1];
                array[i+1] = temporary_variable;
            }
        }
    }
}

void QuickSort(int* array, int begin_index, int end_index) {
    int middle = array[(begin_index + end_index) / 2];
    int begin = begin_index;
    int end = end_index;
    while (begin <= end) {
        while (array[begin] < middle) ++begin;
        while (array[end] > middle) --end;
        if (begin <= end) {
            int temporary_variable = array[begin];
            array[begin] = array[end];
            array[end] = temporary_variable;
            ++begin;
            --end;
        }
    }
    if (end > begin_index)
        QuickSort(array, begin_index, end);

    if (begin < end_index)
        QuickSort(array, begin, end_index);

}

void Merge(int* arr, int left, int middle, int right, int size)
{
    int i = left;
    int j = middle + 1;
    int k = left;
    int temp[size];
    while (i <= middle && j <= right) {
        if (arr[i] <= arr[j]) {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else {
            temp[k] = arr[j];
            j++;
            k++;
        }
    }
    while (i <= middle) {
        temp[k] = arr[i];
        i++;
        k++;
    }
    while (j <= right) {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int p = left; p <= right; p++) {
        arr[p] = temp[p];
    }
}

void MergeSort(int* arr, int left, int right, int size)
{
    if (left < right) {
        int middle = (left + right) / 2;
        MergeSort(arr, left, middle, size);
        MergeSort(arr, middle + 1, right, size);
        Merge(arr, left, middle, right, size);
    }
}

void ShellSort(int *arr, int size) {
    for (int half_size = size/2; half_size >= 1; half_size /= 2)
        for (int i = half_size; i < size; i++)
            for (int j = i; j >= half_size && arr[j-half_size] > arr[j]; j -= half_size) {
                int temp = arr[j];
                arr[j] = arr[j-half_size];
                arr[j-half_size] = temp;
            }
}
