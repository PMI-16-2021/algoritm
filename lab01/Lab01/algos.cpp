#include "algos.h"
#include <iostream>



void insertSort(int* array, int size)
{

	if (array == nullptr) throw BadPointer();
	if (size <= 0) throw BadSize(size);
	


	for (int external_index = 1; external_index < size; ++external_index)
	{

		int chosen_element = array[external_index];
		int swap_index = external_index - 1;
		while (swap_index >= 0 && array[swap_index] > chosen_element)
		{
			array[swap_index + 1] = array[swap_index];
			--swap_index;
		}
		array[swap_index + 1] = chosen_element;
	}
}

void printArray(int* array, int size, std::ostream& out)
{
	for (int i = 0; i < size; ++i)
		out << array[i] << ' ';

}

void Swap(int& first, int& second)
{
	int temp = first;
	first = second;
	second = temp;
}

void QuickSort(int* arr, int min_index, int max_index)
{
	if (arr == nullptr) throw BadPointer();
	if (min_index < 0) throw BadIndex(min_index);
	if (max_index < -1) throw BadIndex(max_index);

	if (min_index > max_index) return;

	int pivot_index = GetPivotIndex(arr, min_index, max_index);

	QuickSort(arr, min_index, pivot_index - 1);
	QuickSort(arr, pivot_index + 1, max_index);

	return;
}

int GetPivotIndex(int* arr, int start, int end)
{
	int pivot_index = start - 1;

	for (int i = start; i < end; ++i)
	{
		if (arr[i] <= arr[end])
		{
			++pivot_index;
			Swap(arr[pivot_index], arr[i]);
		}
	}

	++pivot_index;
	Swap(arr[pivot_index], arr[end]);

	return pivot_index;

}

void BadPointer::report(std::ostream& out) const
{
	out << "Array pointer is nullptr. Impossible to carry out the function.\n";
}



int BadSize::returnField() const
{
	return bad_index;
}

void BadSize::report(std::ostream& out) const
{
	out << "Invalid array size: " << bad_index << '\n';
}

void BadIndex::report(std::ostream& out) const
{ 
	out << "Invalid array index: " << bad_index << '\n';
}
