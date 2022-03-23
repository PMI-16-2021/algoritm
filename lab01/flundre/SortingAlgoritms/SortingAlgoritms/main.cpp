#include <iostream>
#include "sorts.h"

using namespace std;

int main() {
	const int kArraySize = 10;
	int first_array[kArraySize] = { 5, 6, 8, 1, 2, 4, 3, 7, 0, 9 };
	BubbleSort(first_array, kArraySize);
	PrintArray(first_array, kArraySize);
	int second_array[kArraySize] = { 7, 1, 4, 9, 31, 4, 3, 44, 0, 9 };
	QuickSort(second_array, 0, kArraySize - 1);
	PrintArray(second_array, kArraySize);
	int third_array[kArraySize] = { 6, 6, 1, 3, 5, 5, 3, 1, 7, 7, };
	CountingSort(third_array, kArraySize);
	PrintArray(third_array, kArraySize);
	int fourth_array[kArraySize] = { 5,16,1,32,44,3,16,7 };
	ShellSort(fourth_array, kArraySize);
	PrintArray(fourth_array, kArraySize);

	system("pause");
	return 0;
}