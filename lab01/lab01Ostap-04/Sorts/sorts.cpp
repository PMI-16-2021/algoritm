#include <iostream>
#include "sorts.h"

void PrintArray(int* array, size_t size_of_array) {
	std::cout << '[';
	for (int i = 0; i < size_of_array; ++i) {
		std::cout << ' ' << array[i];
	}
	std::cout << ']' << "\n\n";
}

void SwapElements(int* one, int* two) {
	int temp = *one;
	*one = *two;
	*two = temp;
}

void BubbleSort(int* array, size_t size_of_array) {
	for (int i = 0; i < size_of_array; ++i) {
		bool swap = false;
		for (int j = 0; j < size_of_array - i - 1; ++j) {
			if (array[j] > array[j + 1]) {
				SwapElements(&array[j], &array[j + 1]);
				swap = true;
			}
		}
		if (swap == false) break;
	}
}

int Partition(int* array, int begin, int end, int pivot) {
	int counter = 0;
	for (int i = begin + 1; i <= end; i++) {
		if (array[i] <= pivot) {
			counter++;
		}
	}

	int pivot_index = begin + counter;
	SwapElements(&array[pivot_index], &array[begin]);
	int i = begin;
	int j = end;
	while (i<pivot_index && j>pivot_index) {
		while (array[i] <= pivot) {
			i++;
		}
		while (array[j] >= pivot) {
			j--;
		}
		if (i<pivot_index && j>pivot_index) {
			SwapElements(&array[i++], &array[j--]);
		}
	}
	return pivot_index;
}

void QuickSort(int* array, int begin, int end) {
	if (begin < end) {
		int pivot = array[begin];
		int position = Partition(array, begin, end, pivot);

		QuickSort(array, begin, position - 1);
		QuickSort(array, position + 1, end);
	}
}


int FindMaxElement(int* array, size_t size_of_array) {
	if (size_of_array > 0) {
		int max = array[0];
		for (int i = 1; i < size_of_array; ++i) {
			if (array[i] > max) {
				max = array[i];
			}
		}
		return max;
	}
	return 0;
}

int FindMinElement(int* array, size_t size_of_array) {
	if (size_of_array > 0) {
		int min = array[0];
		for (int i = 1; i < size_of_array; ++i) {
			if (array[i] < min) {
				min = array[i];
			}
		}
		return min;
	}
	return 0;
}

void CountSort(int* array, size_t size_of_array) {
	int min_element = FindMinElement(array, size_of_array);
	int max_element = FindMaxElement(array, size_of_array);
	int size_of_counters = max_element - min_element + 1;
	int* counters_array = new int[size_of_counters];

	for (int i = 0; i < size_of_counters; i++) {
		counters_array[i] = 0;
	}
	for (int i = 0; i < size_of_array; i++) {
		counters_array[array[i] - min_element]++;
	}
	int temp = 0;
	for (int i = 0; i < size_of_counters; ++i) {
		if (counters_array[i] != 0) {
			for (int j = 0; j < counters_array[i]; ++j) array[temp++] = min_element + i;
		}
	}
	delete[]counters_array;
}

void ShellSort(int* array, size_t size_of_array) {
	int part, i, j;
	part = size_of_array / 2;
	while (part > 0) {
		for (i = 0; i < size_of_array - part; ++i) {
			j = i;
			while (j >= 0 && array[j] > array[j + part]) {
				SwapElements(&array[j], &array[j + part]);
				--j;
			}
		}
		part /= 2;
	}
}