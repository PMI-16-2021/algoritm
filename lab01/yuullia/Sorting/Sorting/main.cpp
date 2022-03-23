#include <iostream>
#include "function.h"
using namespace std;


int main() {
	const int kSize = 7;

	//Bubble Sort
	int arr1[kSize] = { 10, 13, 225, 1, 9, 30, 69 };
	BubbleS(arr1, kSize);
	cout << "Bubble Sort: ";
	PrintArr(arr1, kSize);
	
	//Quick Sort
	int arr2[kSize] = { 11, 45, 32, 99, 81, 27, 3 };
	QuickS(arr2, 0, kSize - 1);
	cout << "Quick Sort: ";
	PrintArr(arr2, kSize);
	
	//Count Sort
	int arr3[kSize] = { 2, 4, 100, 16, 17, 78, 1 };
	CountS(arr3, kSize);
	cout << "Count Sort: ";
	PrintArr(arr3, kSize);
	
	//Shell Sort
	int arr4[kSize] = { 78, 33, 91, 60, 3, 53, 40 };
	ShellS(arr4, kSize);
	cout << "Shell Sort: ";
	PrintArr(arr4, kSize);

	system("pause");
	return 0;
}