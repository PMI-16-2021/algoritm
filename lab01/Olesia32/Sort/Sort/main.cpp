#include <iostream>
#include "sort.h"

int main()
{
	int size;
	std::cout << "Enter size of array: ";
	std::cin >> size;
	int* array = new int[size];
	ReadArray(array, size);
	std::cout << '\n';
	PrintArray(array, size);
	BubbleSort(array, size);
	//QuickSort(Array, 0, size - 1);
	// CountingSort(Array, size);
	//ShellSort(Array, size);
	std::cout << '\n';
	PrintArray(array, size);

	delete[] array;

	system("pause");
	return 0;
}


