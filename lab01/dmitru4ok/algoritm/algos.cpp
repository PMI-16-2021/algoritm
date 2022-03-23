#include "algos.h"
#include <iostream>



void InsertSort(int* array, int size)
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

	static int counter = 0;
	if (counter == 0) --max_index;

	if (min_index > max_index)
	{
		return;
		--counter;
	}
	++counter;
	int pivot_index = GetPivotIndex(arr, min_index, max_index);

	QuickSort(arr, min_index, pivot_index - 1);
	QuickSort(arr, pivot_index + 1, max_index);

	--counter;
	return; 
}

int GetPivotIndex(int* arr, int start, int end) //get index of the pivot
{
	int pivot_index = start - 1;

	for (int i = start; i < end; ++i)
	{
		if (arr[i] <= arr[end])
		{
			++pivot_index;
			Swap(arr[pivot_index], arr[i]); //swap values
		}
	}

	++pivot_index;
	Swap(arr[pivot_index], arr[end]); //swap value with the last in array

	return pivot_index;

}

void ShellSorting(int* arr, int size)
{
	if (arr == nullptr) throw BadPointer();
	if (size <= 0) throw BadSize(size);

	int step = size / 2; //find step 10-> 5-> 2-> 1 
	while (step > 0) // (1 / 2) = 0 => break
	{
		for (int i = 0; i < size - step; ++i)
		{
			int j = i;
			while (j >= 0 && arr[j] > arr[j + step]) //similar to nsertSort
			{
				int temp = arr[j];
				arr[j] = arr[j + step];
				arr[j + step] = temp;
				--j;
			}
		}
		step = step / 2;
	}
}

int GetMin(int* arr, int size)
{
	int return_val = arr[0];
	for (size_t i = 1; i < size; ++i)
	{
		if (arr[i] < return_val) return_val = arr[i];
	}

	return return_val;
}

int GetMax(int* arr, int size)
{
	int return_val = arr[0];
	for (size_t i = 1; i < size; ++i)
	{
		if (arr[i] > return_val) return_val = arr[i];
	}
	return return_val;
}

void CountSorting(int* arr, int size)
{

	if (arr == nullptr) throw BadPointer();
	if (size <= 0) throw BadSize(size);
	int min_value = GetMin(arr, size);
	int max_value = GetMax(arr, size);
	int count_size = max_value - min_value + 1; // find difference max and min values of array => size of new container
	int* counting_arr = new int[count_size];
	for (int i = 0; i < count_size; ++i) counting_arr[i] = 0;

	for (size_t i = 0; i < size; ++i) ++counting_arr[arr[i] - min_value];

	size_t current = 0;
	for (size_t i = 0; i < count_size; ++i)
	{
		if (counting_arr[i] != 0)
		{
			for (size_t j = 0; j < counting_arr[i]; ++j) arr[current++] = min_value + i;
		}
	}
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
