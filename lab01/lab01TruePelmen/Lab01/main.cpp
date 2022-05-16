#include<iostream>
#include "sortalg.h"
using namespace std;

int main()
{
	const int size = 10;
	int arr[size] = {21, 12, 343, 2, 12, 534, 576, 34, 234, 465 };
	
	ShowArray(arr, size);
	//BubbleSort(arr, size);
	//QuickSort(arr, 0, size - 1);
	//ShellSort(arr, size);
	CountSort(arr, size);
	ShowArray(arr, size);
	
	system("pause");
	return 0;
}

