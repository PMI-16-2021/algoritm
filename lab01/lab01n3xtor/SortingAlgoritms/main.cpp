#include <iostream>
#include "sorts.h"
#include "sortsTest.h"
using namespace std;

int main()
{
	int arr[] = {2, 84, 32, 12, 0, 99, 43, 17, };
	const size_t arrSize = sizeof(arr) / sizeof(arr[0]);

	cout << "Unsorted array:\n";
	printArray(arr, arrSize);
	
	bubbleSort(arr, arrSize);
	cout << "Bubble sorted array:\n";
	printArray(arr, arrSize);

	quickSort(arr, arrSize);
	cout << "Quick sorted array:\n";
	printArray(arr, arrSize);

    countingSort(arr, arrSize);
    cout << "Counting sorted array:\n";
    printArray(arr, arrSize);

	shellSort(arr, arrSize);
	cout << "Shell sorted array:\n";
	printArray(arr, arrSize);

	bubbleSortTest();
	quickSortTest();
	countingSortTest();
	shellSortTest();

	system("pause>>void");
	return 0;
}
