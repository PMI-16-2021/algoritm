#include<iostream>
#include "Sort.h"
void Switch(int& a, int& b)
{
	int z = a;
	a = b;
	b = z;
}

void reverseArray(int* arr, int SIZE)
{
	int j = SIZE - 1;
	for (int i = 0; i < SIZE / 2; ++i)
	{
		Switch(arr[i], arr[j]);
		--j;
	}
}
void print(int* arr, int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}


void RandArray(int* arr, int SIZE)
{
	for (int i = 0; i < SIZE; ++i)
	{
		arr[i] = rand() % 10;
	}
}

void BubbleSort(int* arr, int SIZE)
{
	for (int i = 1; i < SIZE; ++i)
	{
		for (int j = 0; j < SIZE; ++j)
		{
			if (arr[j] > arr[i])
			{
				Switch(arr[i], arr[j]);
			}
		}
	}
}

void ShellSort(int* arr, int SIZE)
{
	int gap, i, j;
	for (gap = SIZE / 2; gap > 0; gap = gap / 2)
	{
		for (i = gap; i < SIZE; i++)
		{
			for (j = i - gap; j >= 0; j -= gap)
			{
				if (arr[j + gap] >= arr[j])
					break;
				else
					Switch(arr[j + gap], arr[j]);
			}
		}
	}
}

void QuickSort(int* arr, int low, int high)
{
	int pivot = arr[(low + high) / 2];
	int temp;

	while (low <= high)
	{
		while (arr[low] < pivot)
			low++;
		while (arr[high] > pivot)
			high--;
		if (low <= high)
		{
			temp = arr[low];
		arr[low] = arr[high];
		arr[high] = temp;
			low++;
			high--;
		}
	}
	if (high > low)
		QuickSort(arr, low, high);
	if (low < high)
		QuickSort(arr, low, high);
}
int GetMax(int* arr, int SIZE) {
	int MaxValue = arr[0];
	for (int i = 1; i < SIZE; ++i) {
		if (arr[i] > MaxValue) {
			MaxValue = arr[i];
		}
	}
	return MaxValue;
}

void CountingSort(int* arr, int SIZE, int place) {
	int Output[1000];
	int Count[10] = { 0 };

	for (int i = 0; i < SIZE; ++i) {
		Count[(arr[i] / place) % 10]++;
	}
	for (int i = 1; i < 10; ++i) {
		Count[i] += Count[i - 1];
	}
	for (int i = SIZE - 1; i >= 0; --i) {
		Output[Count[(arr[i] / place) % 10] - 1] = arr[i];
		Count[(arr[i] / place) % 10]--;
	}
	for (int i = 0; i < SIZE; ++i) {
		arr[i] = Output[i];
	}
}
void RadixSort(int* arr, int SIZE) {
	int MaxValue = GetMax(arr, SIZE);

	for (int place = 1; MaxValue / place > 0; place *= 10) {
		CountingSort(arr, SIZE, place);
	}
}