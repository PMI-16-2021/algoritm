#include <iostream>
#include "sorting.h"
using namespace std;

void BubbleSort(int array[], int size)
{
	// loop to access each array element
	for (int i = 0; i < size - 1; ++i)
	{
		// loop to compare two elements
		for (int j = 0; j < size - i - 1; j++)
		{
			// compare two array elements
		
			if (array[j] > array[j + 1])
			{
				// swapping elements if elements
	            // are not in the intended order
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}


void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << "  " << array[i];
	}
	cout << "\n";
}

void QuickSort(int array[], int left, int right)
{
	//find middle element
	int middle = array[(left + right) / 2];

	int i = left;
	int j = right;

	do
	{
		//find the right element bigger than the middle element  
		while (array[j] > middle)
			--j;
		//find the left element smaller than the middle element 
		while (array[i] < middle)
			++i;
        //swap values if their indices don't cross
			if (i <= j)
			{
				swap(array[i], array[j]);
				++i;
				--j;
			}
			
	} 
	while (i <= j); //until they crossed each other

	//if the right index didn`t reach the beginning
	if (j > left)
		QuickSort(array, left, j);

	//if the left index didn`t reach the end
	if (i < right)
		QuickSort(array, i, right);

	
	
}



void ShellSort(int array[], int size)
{
	int group, i, j, count;
	group = size;

	//find the middle element
	group = group / 2;

	while (group > 0) 
	{
		//i reaches the middle element
		for (i = 0; i < size - group; ++i)
		{
			j = i;
			while (j >= 0 && array[j] > array[j + group])
			{
				//swap elements if element bigger than element+group
				count = array[j];
				array[j] = array[j + group];
				array[j + group] = count;
				--j;
			}
		}
		//decrease the interval
		group = group / 2;
	}
}

// Function to get the largest element from an array
int GetMax(int array[], int size)
{
	int max = array[0];
	for (int i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];
	return max;
}

void CountingSort(int array[], int size, int place) 
{
	
	const int max = 10;
	int output[10];
	int count[max]; 

	//Initialize count array to all zero
	for (int i = 0; i < max; ++i)
		count[i] = 0;

	// Calculate count of elements
	for (int i = 0; i < size; i++)
		count[(array[i] / place) % 10]++;

	// Calculate cumulative count of each array
	for (int i = 1; i < max; i++)
		count[i] += count[i - 1];

	//Find the index of each element of the original array in count array
	// place the elements in sorted order
	for (int i = size - 1; i >= 0; i--) 
	{
		output[count[(array[i] / place) % 10] - 1] = array[i];
		count[(array[i] / place) % 10]--;
	}

	//Copy sorted elements into original array
	for (int i = 0; i < size; i++)
		array[i] = output[i];
}

// Main function to implement radix sort
void RadixSort(int array[], int size) {
	// Get maximum element
	int max = GetMax(array, size);

	// Apply counting sort to sort elements based on place value.
	for (int place = 1; max / place > 0; place *= 10)
		CountingSort(array, size, place);
}

void ReverseArray(int array[], int size)
{
	for (int i = 0; i < size / 2; ++i)
	{
		int j = size - 1;
		int temp = array[i];
		array[i] = array[j];
		array[j] = temp;
		--j;
	}
}