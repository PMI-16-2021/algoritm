#include<iostream>
#include"sort.h"


int main() {
	const int size = 4;
	int* arr = new int[size];
	//value(arr, size);
	//print(arr, size);
	////sortBubl(arr, size);
	////sort_shell(arr, size);
	////sort_insert(arr, size);
	////quickSort(arr,0,size-1);
	//sortShell(arr,size);
	//print(arr, size);

	int invertedArr[size] = { 4,3,2,1 };
	for (int i = 0; i < size; ++i)
	{
		std::cout << invertedArr[i];
		std::cout << "  ";
	}
	std::cout << "\n";
	countSort(invertedArr, size, size + 1);

	for (int i = 0; i < size; ++i)
	{

		std::cout << invertedArr[i];
		std::cout << "  ";
	}


	return 0;
}