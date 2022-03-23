#include <iostream>
#include "sorting.h"
using namespace std;

int main()
{
	const int size = 5;
	int data[] = { -2, 45, 0, 11, -9 };
	
	cout << "Array before sorting:\n";
	PrintArray(data, size);

	BubbleSort(data, size);
	cout << "Bubble sorting:\n";
	PrintArray(data, size);
	
	QuickSort(data, 0, size - 1);
	cout << "Quick sorting:\n";
	PrintArray(data, size);

	ShellSort(data, size);
	cout << "Shell sorting:\n";
	PrintArray(data, size);

	void RadixSort(int array[], int size);
	cout << "Radix sorting:\n";
	PrintArray(data, size);


	//delete[] data;
	return 0;
}