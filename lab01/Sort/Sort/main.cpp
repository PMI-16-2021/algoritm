#include <iostream>
#include "sort.h"

int main() {
	const int Size = 11;
	int Arr[Size] = { 2, 8, 5, 1, 20, 6, 4, 15, 9, 7 , 3};
	PrintArrays(Arr, Size);

	//BublleSort(Arr, Size);
	//PrintArrays(Arr, Size);
	//QuickSort(Arr, 0, Size - 1);
	//PrintArrays(Arr, Size);
	//ShellSort(Arr, Size);
	//PrintArrays(Arr, Size);
	RadixSort(Arr, Size);
	//ReverseSortArray(Arr, Size);
	PrintArrays(Arr, Size);
	//std::cout << GetMax(Arr, Size);
	//delete[] Arr;
	return 0;
}
