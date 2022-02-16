#include <iostream>
#include "algos.h"

int main()
{
	const int array_size = 8;

	int arr[array_size] = { 7, 2, 1, 4, 6, 3, 0, 5 };
	insertSort(arr, array_size);
	printArray(arr, array_size, std::cout);

























	system("pause");
	return 0;
}