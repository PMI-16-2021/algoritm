#include "function.h"
#include <iostream>
using namespace std;


void PrintArr(int* arr, int size)
{
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << " ";
	}
	cout << "\n\n";
}

void BubbleS(int* arr, int size)
{
	for (int i = 1; i < size; i++) {
		for (int j = size - 1; j >= i; j--) {
			if (arr[j] < arr[j - 1]) {
				int temp = arr[j - 1];
				arr[j - 1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

void QuickS(int* arr, int first, int last)
{
	int middle = arr[(first + last) / 2];
	int i = first, j = last;
	while (i <= j) {
		while (arr[j] > middle) --j;
		while (arr[i] < middle) ++i;

		if (i <= j) {
			int temp = arr[i];
			arr[i] = arr[j];
			arr[j] = temp;
			++i;
			--j;
		}
	} 
	if (j > first) {
		QuickS(arr, first, j);
	}
	if (i < last) {
			QuickS(arr, i, last);
	}
}

void CountS(int* arr, int size)
{
	int* arr1 = new int[size+1];
	int* count_arr = new int[size+1];
	int max = arr[0];

	for (int i = 1; i < size; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	for (int i = 0; i <= max; ++i) {
		count_arr[i] = 0;
	}

	for (int i = 0; i < size; i++) {
		count_arr[arr[i]]++;
	}

	for (int i = 1; i <= max; i++) {
		count_arr[i] += count_arr[i - 1];
	}


	for (int i = size - 1; i >= 0; i--) {
		arr1[count_arr[arr[i]] - 1] = arr[i];
		count_arr[arr[i]]--;
	}

	for (int i = 0; i < size; i++) {
		arr[i] = arr1[i];
	}
}

void ShellS(int* arr, int size)
{
	for (int d = size / 2; d >= 1; d /= 2) {
		for (int i = d; i < size; i++) {
			for (int j = i; j >= d && arr[j - d] > arr[j]; j -= d) {
				int temp = arr[j];
				arr[j] = arr[j - d];
				arr[j - d] = temp;
			}
		}
	}
}



