#include <iostream>
#include "Sort.h"
using namespace std;

int main() {

	//Bubble Sort
	cout << "Bubble sort\n";
	int array[] = { 2, 45, 0, 11, 9 };
	int size = sizeof(array) / sizeof(array[0]);
	PrintArray(array, size);
	BubbleSort(array, size);
	PrintArray(array, size);
	cout << "\n";
	//Quick Sort
	cout << "Quick sort\n";
	int data[] = { 23, 45, 32, 12, 56, 44, 2 };
	int n = sizeof(data) / sizeof(data[0]);
	PrintArray(data, n);
	QuickSort(data, 0, n - 1);
	PrintArray(data, n);
	cout << "\n";
	//Count Sort
	cout << "Count sort\n";
	int range[] = { 5, 2, 4, 7, 9, 5, 7, 7 };
	int p = sizeof(range) / sizeof(range[0]);
	PrintArray(range, p);
	CountSort(range, p);
	PrintArray(range, p);
	cout << "\n";
	//Merge Sort
	cout << "Merge sort\n";
	int arr[] = { 4, 20, 54, 34, 89, 21, 100 };
	int k = sizeof(arr) / sizeof(arr[0]);
	PrintArray(arr, k);
	MergeSort(arr, 0, k - 1);
	PrintArray(arr, k);



	system("pause");
	return 0;
}

