#include <iostream>
#include "sort.h"


void PrintArrays(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		std::cout << arr[i] << ' ';
	}
	std::cout << "\n\n";
}

void Swap(int* fir, int* sec) {
	int temp = *fir;
	*fir = *sec;
	*sec = temp;
}

void ReverseSortArray(int* arr, int n) {
	int j = n - 1;
	for (int i = 0; i < n/2; ++i) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			--j;
	}
}

void BublleSort(int* arr, int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = n - 1; j > i; --j) {
			if (arr[j] < arr[j - 1]) {
				Swap(&arr[j], &arr[j - 1]);
			}
		}
	}
}

void QuickSort(int* arr, int FirstIndex, int LastIndex) {
	int MiddleValue = arr[(FirstIndex + LastIndex) / 2];
	int i = FirstIndex;
	int j = LastIndex;
	do {
		while (arr[j] > MiddleValue) {
			--j;
		}
		while (arr[i] < MiddleValue) {
			++i;
		}
		if (i <= j) {
			Swap(&arr[i], &arr[j]);
			++i;
			--j;
		}
	} while (i <= j);
	if (j > FirstIndex) {
		QuickSort(arr, FirstIndex, j);
	}
	if (i < LastIndex) {
		QuickSort(arr, i, LastIndex);
	}
}

void ShellSort(int* arr, int n) {
	int Group, i, j, count;
	Group = n;
	Group = Group / 2;
	while (Group > 0) {
		for (i = 0; i < n - Group; ++i) {
			j = i;
			while (j >= 0 && arr[j] > arr[j + Group]) {
				Swap(&arr[j], &arr[j + Group]);
				--j;
			}
		}
		Group = Group / 2;
	}
}
int GetMax(int* arr, int n) {
	int MaxValue = arr[0];
	for (int i = 1; i < n; ++i) {
		if (arr[i] > MaxValue) {
			MaxValue = arr[i];
		}
	} 
	return MaxValue;
}

void CountingSort(int* arr, int size, int place) {
	int Output[1000];
	int Count[10] = { 0 };

	for (int i = 0; i < size; ++i) {
		Count[(arr[i] / place) % 10]++;
	}
	for (int i = 1; i < 10; ++i) {
		Count[i] += Count[i - 1];
	}
	for (int i = size - 1; i >= 0; --i) {
		Output[Count[(arr[i] / place) % 10] - 1] = arr[i];
		Count[(arr[i] / place) % 10]--;
	}
	for (int i = 0; i < size; ++i) {
		arr[i] = Output[i];
	}
}
void RadixSort(int* arr, int size) {
	int MaxValue = GetMax(arr, size);

	for (int place = 1; MaxValue / place > 0; place *= 10) {
		CountingSort(arr, size, place);
	}
}