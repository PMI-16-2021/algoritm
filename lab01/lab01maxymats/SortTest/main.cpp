#include <iostream>
#include "Sort.h"
using namespace std;

int main()
{
	const int SIZE = 11;
	int* arr = new int[SIZE] { 2, 8, 5, 1, 20, 6, 4, 15, 9, 7 , 3 };

	cout << "Array before sorting:\n";
	print(arr, SIZE);

	BubbleSort(arr, SIZE);
	cout << "Bubble sort:\n";
	print(arr, SIZE);

	ShellSort(arr, SIZE);
	cout << "Shell sort:\n";
	print(arr, SIZE);

	QuickSort(arr, 0, SIZE);
	cout << "Quick sort:\n";
	print(arr, SIZE);

	RadixSort(arr, SIZE);
	cout << "Radix sort:\n";
	print(arr, SIZE);


	delete[] arr;

	return 0;
	system("Pause");
}