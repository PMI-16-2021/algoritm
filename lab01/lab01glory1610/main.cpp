#include <iostream>
#include "Sort.h"
#include <cassert>
#include <string>
using namespace std;

string ArrayToStr(int arr[], int size) {
	string res = "";
	for (int i = 0; i < size; ++i)
	{
		res += to_string(arr[i]);
		if (i != size - 1) {
			res += " ";
		}
	}
	return res;
}

void TestBubbleSort() {
	int size = 5;
	int first_array[] = { 2, 45, 0, 11, 9 };
	int second_array[] = { 1, 4, 10, 12, 15 };
	int third_array[] = { 13, 6, 5, 4, 0 };
	BubbleSort(first_array, size);
	BubbleSort(second_array, size);
	BubbleSort(third_array, size);
	assert(ArrayToStr(first_array, size) == "0 2 9 11 45");
	assert(ArrayToStr(second_array, size) == "1 4 10 12 15");
	assert(ArrayToStr(third_array, size) == "0 4 5 6 13");
	cout << "\nBubble Sort OK\n";
}

void TestQuickSort() {
	int size = 5;
	int first_array[] = { 2, 45, 0, 11, 9 };
	int second_array[] = { 1, 4, 10, 12, 15 };
	int third_array[] = { 13, 6, 5, 4, 0 };
	QuickSort(first_array, 0, size - 1);
	QuickSort(second_array, 0, size - 1);
	QuickSort(third_array, 0, size - 1);
	assert(ArrayToStr(first_array, size) == "0 2 9 11 45");
	assert(ArrayToStr(second_array, size) == "1 4 10 12 15");
	assert(ArrayToStr(third_array, size) == "0 4 5 6 13");
	cout << "\nQuick Sort OK\n";
}

void TestCountSort() {
	int size = 5;
	int first_array[] = { 2, 45, 0, 11, 9 };
	int second_array[] = { 1, 4, 10, 12, 15 };
	int third_array[] = { 13, 6, 5, 4, 0 };
	CountSort(first_array, size);
	CountSort(second_array, size);
	CountSort(third_array, size);
	assert(ArrayToStr(first_array, size) == "0 2 9 11 45");
	assert(ArrayToStr(second_array, size) == "1 4 10 12 15");
	assert(ArrayToStr(third_array, size) == "0 4 5 6 13");
	cout << "\nCount Sort OK\n";
}

void TestMergeSort() {
	int size = 5;
	int first_array[] = { 2, 45, 0, 11, 9 };
	int second_array[] = { 1, 4, 10, 12, 15 };
	int third_array[] = { 13, 6, 5, 4, 0 };
	MergeSort(first_array, 0, size - 1);
	MergeSort(second_array, 0, size - 1);
	MergeSort(third_array, 0, size - 1);
	assert(ArrayToStr(first_array, size) == "0 2 9 11 45");
	assert(ArrayToStr(second_array, size) == "1 4 10 12 15");
	assert(ArrayToStr(third_array, size) == "0 4 5 6 13");
	cout << "\nMerge Sort OK\n";
}

int main() {

	TestBubbleSort();
	TestCountSort();
	TestMergeSort();
	TestQuickSort();
	cout << "\n";

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

