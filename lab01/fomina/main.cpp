#include <iostream>
#include "sort.h"
using namespace std;
int main()
{
	int n = 7;
	int* arr = new int [n] { 85, -5, 4, 0, 96, 4, 7};
	PrintArr(arr, n);

	SelectionSort(arr, n);

	PrintArr(arr, n);

	const int k = 9;
	


	delete[] arr;
	system("pause");
	return 0;
}