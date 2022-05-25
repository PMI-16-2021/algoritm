#include<iostream>
#include"sort.h"
using namespace std;

void printArr(int* arr, int size){
	for (int i = 0; i < size; ++i) {
		cout << arr[i] << ' ';
	}
	cout << '\n';
}

void swap(int* first, int* second){
	int temp = *first;
	*first = *second;
	*second = temp;
}

void bublleSort(int* arr, int size){
	for (int i = 0; i < size-1; ++i) {
		for (int j = 0; j < size - i - 1; ++j) {
			if (arr[j] > arr[j + 1]) {
				swap(&arr[j], &arr[j + 1]);
			}
		}
	}
}

void quickSort(int* arr, int left, int right){
	int middle = arr[(left + right) / 2];
	int i = left;
	int j = right;
	do {
		while (arr[j] > middle) {
			--j;
		}
		while (arr[i] < middle) {
			++i;
		}
		if (i <= j) {
			swap(&arr[i], &arr[j]);
			++i;
			--j;
		}
	} while (i <= j);
	if (j>left){
		quickSort(arr, left, j);
	}
	if (i<right)
	{
		quickSort(arr, i, right);
	}
}

void shellSort(int* arr, int size){
	int gap, j, k;
		for (gap = size / 2; gap > 0; gap /= 2) {        
			for (j = gap; j < size; j++) {
				for (k = j - gap; k >= 0; k -= gap) {
					if (arr[k + gap] >= arr[k])
						break;
					else
						swap(&arr[k + gap], &arr[k]);
				}
			}
	}
}