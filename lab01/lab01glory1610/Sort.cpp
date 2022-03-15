#include "Sort.h"
using namespace std;

void PrintArray(int arr[], int size) {
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}
	cout << "\n";
}

void BubbleSort(int arr[], int size) {
	for (int element = 0; element < size; ++element) {
		for (int i = 0; i < size - element - 1; ++i) {
			if (arr[i] > arr[i + 1]) {
				int temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
			}
		}
	}
}

void SwapElements(int* a, int* b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

int Partition(int arr[], int low, int high) {
	int pivot = arr[high];
	int greater_element = low - 1;
	for (int element = low; element < high; ++element) {
		if (arr[element] <= pivot) {
			++greater_element;
			SwapElements(&arr[greater_element], &arr[element]);
		}
	}
	SwapElements(&arr[greater_element + 1], &arr[high]);
	return (greater_element + 1);
}

void QuickSort(int arr[], int low, int high) {
	if (low < high) {
		int pi = Partition(arr, low, high);
		QuickSort(arr, low, pi - 1);
		QuickSort(arr, pi + 1, high);
	}
}

void CountSort(int arr[], int size) {
	const int n = 100;
	int output[n];
	int count[n];
	int max = arr[0];
	for (int element = 1; element < size; ++element) {
		if (arr[element] > max)
			max = arr[element];
	}
	for (int element = 0; element <= max; ++element) {
		count[element] = 0;
	}
	for (int element = 0; element < size; ++element) {
		++count[arr[element]];
	}
	for (int element = 1; element <= max; ++element) {
		count[element] += count[element - 1];
	}
	for (int element = size - 1; element >= 0; --element) {
		output[count[arr[element]] - 1] = arr[element];
		--count[arr[element]];
	}
	for (int element = 0; element < size; ++element) {
		arr[element] = output[element];
	}
}

void Merge(int arr[], int start, int center, int end) {
	int size_1 = center - start + 1;
	int size_2 = end - center;
	const int n = 100;
	int subarray_1[n], subarray_2[n];
	for (int i = 0; i < size_1; ++i) {
		subarray_1[i] = arr[start + i];
	}
	for (int j = 0; j < size_2; ++j) {
		subarray_2[j] = arr[center + 1 + j];
	}
	int index_subarray_1, index_subarray_2, index_array;
	index_subarray_1 = 0;
	index_subarray_2 = 0;
	index_array = start;
	while (index_subarray_1 < size_1 && index_subarray_2 < size_2) {
		if (subarray_1[index_subarray_1] <= subarray_2[index_subarray_2]) {
			arr[index_array] = subarray_1[index_subarray_1];
			++index_subarray_1;
		}
		else {
			arr[index_array] = subarray_2[index_subarray_2];
			++index_subarray_2;
		}
		++index_array;
	}
	while (index_subarray_1 < size_1) {
		arr[index_array] = subarray_1[index_subarray_1];
		++index_subarray_1;
		++index_array;
	}

	while (index_subarray_2 < size_2) {
		arr[index_array] = subarray_2[index_subarray_2];
		++index_subarray_2;
		++index_array;
	}
}

void MergeSort(int arr[], int top, int bottom) {
	if (top < bottom) {
		int middle = top + (bottom - top) / 2;
		MergeSort(arr, top, middle);
		MergeSort(arr, middle + 1, bottom);
		Merge(arr, top, middle, bottom);
	}
}

