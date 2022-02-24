#include <iostream>
#include "algos.h"

int main()
{
	const int array_size = 10;

////////
	int arr_one_[array_size] = {7, 6, 10, 1, 4, 8, 3, 2, 5, 9};

	std::cout << "*insertSort*\nDEFAULT ARRAY: "; //quicksort algorithm
	printArray(arr_one_, array_size, std::cout);
	insertSort(arr_one_, array_size); std::cout << '\n';
	std::cout << "SORTED ARRAY: ";
	printArray(arr_one_, array_size, std::cout);
////////
	
	std::cout << "\n*QuickSort*\nDEFAULT ARRAY: "; //quicksort algorithm
	int arr_two_[array_size] = { 10, 9, 8, 7, 6, 5, 4, 3, 2, 1 };
	printArray(arr_two_, array_size, std::cout);
	QuickSort(arr_two_, 0, (array_size - 1));
	
	
	std::cout << "\nSORTED ARRAY: ";
	printArray(arr_two_, array_size, std::cout); std::cout << '\n';
/////////

	
























	system("pause");
	return 0;
}