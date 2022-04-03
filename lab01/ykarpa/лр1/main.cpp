#include <iostream>
#include "functions.h"
using namespace std;

int main() {
	const int size = 6;
	int array[size] = { 5, 0, 2, 8, 14, 9 };
	cout << "Array:\n";
	print(array, size);
	cout << "\nBubble sorting\n";
	bubbleSort(array, size);
	print(array, size);
	cout << "\nQuick sorting\n";
	quickSort(array, 0, size - 1);
	print(array, size);
	cout << "\nCounting sorting\n";
	countSort(array, size);
	print(array, size);
	cout << "\nShell sorting\n";
	shellSort(array, size);
	print(array, size);

	system("pause");
	return 0;
}