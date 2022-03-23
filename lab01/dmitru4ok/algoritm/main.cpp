#include <iostream>
#include "algos.h"

int main()
{
	const int array_size = 10;

////////
	int arr_one_[array_size] = { 17, -35,-24, 43, 5, -74, -45, -48, -28, 96 };
	
	std::cout << "*InsertSort*\nDEFAULT ARRAY: "; //InsertSort algorithm
	printArray(arr_one_, array_size, std::cout);
    InsertSort(arr_one_, array_size);
	std::cout << "\nSORTED  ARRAY: "; 
	printArray(arr_one_, array_size, std::cout);
/////////
	
	std::cout << "\n*QuickSort*\nDEFAULT ARRAY: "; //QuickSort algorithm
	int arr_two_[array_size] = { 17, -35,-24, 43, 5, -74, -45, -48, -28, 96 };
	printArray(arr_two_, array_size, std::cout);
	QuickSort(arr_two_, 0, array_size);
	std::cout << "\nSORTED  ARRAY: "; 
	printArray(arr_two_, array_size, std::cout); std::cout << '\n';
/////////

	std::cout << "\n*ShellSorting*\nDEFAULT ARRAY: "; // ShellSorting algorithm
	int arr_three_[array_size] = { 17, -35,-24, 43, 5, -74, -45, -48, -28, 96 };
	printArray(arr_three_, array_size, std::cout);
	ShellSorting(arr_three_, array_size);
	std::cout << "\nSORTED  ARRAY: "; 
	printArray(arr_three_, array_size, std::cout); std::cout << '\n';
/////////
	std::cout << "*CountSorting*\nDEFAULT ARRAY: "; // CountSorting
	int arr_four_[array_size] = { 17, -35,-24, 43, 5, -74, -45, -48, -28, 96 };
	printArray(arr_one_, array_size, std::cout);
	CountSorting(arr_one_, array_size); 
	std::cout << "\nSORTED  ARRAY: "; 
	printArray(arr_one_, array_size, std::cout); std::cout << '\n';
























	system("pause");
	return 0;
}