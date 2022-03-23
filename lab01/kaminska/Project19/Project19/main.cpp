#include "sort.h"
#include <iostream>
using namespace std;

int main() {
	int const size = 10;
	int array[size] = {4,16,7,1,3,17,11,9,14,5};
	cout << "Array:\n";
	printArray(array, size);
	reverseArray(array, size);
	cout << "\nReversed array:\n";
	printArray(array, size);
	bubbleSort(array, size);
	cout << "\nSorted by bubble sort:\n";
	printArray(array, size);
	quickSort(array, 0, size - 1);
	cout << "\nSorted by quick sort:\n";
	printArray(array, size);
	countSort(array, size);
	cout << "\nSorted by count sort:\n";
	printArray(array, size);
	shellSort(array, size);
	cout << "\nSorted by shell sort:\n";
	printArray(array, size);
}