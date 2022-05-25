#include "sort.h"
#include <iostream>
using namespace std;

void SelectionSort(int* arr, int n)
{
	int min_index = 0; 
	for (int i = 0; i < n; ++i) {
		min_index = i;
		for (int j = i + 1; j < n; ++j) {
			if (arr[j] < arr[min_index]) {
				min_index = j; 
			}
		}
		if (i != min_index) {
			int replace = arr[i]; 
			arr[i] = arr[min_index];
			arr[min_index] = replace; 
		}
	}
}

void PrintArr(int* arr, int n) 
{
	for (int i = 0; i < n; ++i){
		cout << arr[i] << ' ';
	}
	cout << "\n";
}


void QuickSort(int* arr, const int n)
{
	int pivot_index = 0;
	int begin_of_unsorted = 1;
	while (begin_of_unsorted < n) {
		if (arr[pivot_index] > arr[begin_of_unsorted]) {
			int to_transfer = arr[begin_of_unsorted];
			for (int i = begin_of_unsorted - 1; i >= pivot_index; --i) {
				arr[i + 1] = arr[i];
			}
			arr[pivot_index] = to_transfer;
			++pivot_index;
		}
		++begin_of_unsorted;
	}
	if (pivot_index > 1) QuickSort(arr, pivot_index);
	if (n - pivot_index > 1) QuickSort(arr + pivot_index + 1, n - pivot_index - 1);

}

void CountSort(int* arr, int n)
{
	int* output = new int[n + 1];
	int* count = new int[n + 1];
	int max = arr[0];
	
	for (int i = 1; i < n; ++i) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}

	for (int i = 0; i <= max; i++) {
		count[i] = 0;
	}

	for (int i = 0; i < n; ++i) {
		count[arr[i]]++;
	}

	for (int i = 1; i <= max; i++) {
		count[i] += count[i - 1];
	}

	for (int i = n - 1; i >= 0; i--) {
		output[count[arr[i]] - 1] = arr[i];
		count[arr[i]]--;
	}

	for (int i = 0; i < n; ++i) {
		arr[i] = output[i];
	}
}

void ShellSort(int* arr, int n)
{
	int i, j, step, tmp;
	for (step = n / 2; step > 0; step /= 2) {
		for (i = step; i < n; ++i) {
			tmp = arr[i];
			for (j = i; j >= step; j -= step) {
				if (tmp < arr[j - step]) {
					arr[j] = arr[j - step];
				}
				else {
					break;
				}
			}
			arr[j] = tmp;
		}
	}
}
