#include<iostream>
#include"funcs.h"
using namespace std;

int main()
{
	unsigned n = 9;
	int* arr = new int[n] {0, 8, -5, 3, 1, 9, 6, 4, -1};
	print(arr, n);
	shellSort(arr, n);
	print(arr, n);
	reverseArray(arr, n);
	print(arr, n);


	delete[] arr;
	cin.get();
	return 0;
}