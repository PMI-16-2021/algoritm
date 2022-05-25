#include<iostream>
#include "sort.h"

using namespace std;

int main() {

	const int size = 5;
	int arr[size] = { 21, 4, 13, 8, 2 };
	cout << "Default array: \n";
	printArr(arr, size);
	cout << '\n';
	cout << "Sorted array: \n";

	//////////////////////
	bublleSort(arr, size);

	//////////////////////
	quickSort(arr, 0, size-1);

	//////////////////////
	shellSort(arr,size);

	printArr(arr, size);

	system("pause");
	return 0;
}