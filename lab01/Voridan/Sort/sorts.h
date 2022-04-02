#pragma once
#include <iostream>

void StartSorting(int* arr, int lenght);

void PrintArr(const int* arr, int lenght);
void InsertionSort(int* arr, int lenght);

void SwapElements(int* a, int*b);
int Partition(int* arr, int bottom, int top);
void QuickSort(int* arr, int bottom, int top);

int FindMax(int* arr, int lenght);
void CountingSort(int* arr, int lenght);

void MergeSort(int* arr, int start, int end);
void Merge(int* arr, int start,  int middle, int end);