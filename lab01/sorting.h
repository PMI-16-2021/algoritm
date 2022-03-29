#pragma once
#include <iostream>
#include <fstream>

void PrintArray(int* array, int n);
void BubbleSort(int* array, int n);
void QuickSort(int* array, int begin, int end);
void Merge(int* arr, int left, int middle, int right, int size);
void MergeSort(int* arr, int left, int right, int size);
void ShellSort(int *arr, int size);