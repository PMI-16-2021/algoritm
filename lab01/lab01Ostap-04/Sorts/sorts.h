#pragma once

void PrintArray(int* array, size_t size_of_array);

void SwapElements(int* one, int* two);
void BubbleSort(int* array, size_t size_of_array);

int Partition(int* array, int begin, int end, int pivot);
void QuickSort(int* array, int begin, int end);

int FindMinElement(int* array, size_t size_of_array);
int FindMaxElement(int* array, size_t size_of_array);
void CountSort(int* array, size_t size_of_array);

void ShellSort(int* array, size_t size_of_array);