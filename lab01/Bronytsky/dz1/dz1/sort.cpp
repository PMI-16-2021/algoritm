#include<iostream>
#include"sort.h"




void print(int* arr, const int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << "\n";
}
void value(int* arr, const int size) 
{
	for (int i = 0; i < size; ++i) 
	{
		std::cin >> arr[i];
	}
}
void sortBubl(int* arr, const int size)
{
	int temp = 0;
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			if (arr[j] >= arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}

int partition(int arr[], int low, int high)
{
	int temp = 0;
	int pivot = arr[high];
	int i = (low - 1);
	for (int j = low; j < high; ++j)
	{
		if (arr[j] <= pivot)
		{
			++i;
			temp = arr[j];
			arr[j] = arr[i];
			arr[i] = temp;
		}
	}
	temp = arr[i + 1];
	arr[i + 1] = arr[high];
	arr[high] = temp;
	return (i + 1);
}
void quickSort(int arr[], int low, int high)
{
	if (low < high)
	{
		int pi = partition(arr, low, high);
		quickSort(arr, low, pi - 1);
		quickSort(arr, pi + 1, high);
	}
}
void countSort(int arr[], const int size, const int range)
{
	int* output_array = new int[size];
	int* count_array = new int[range];


	for (int i = 0; i < range; i++)
	{
		count_array[i] = 0;
	}

	for (int i = 0; i < size; i++)
	{
		++count_array[arr[i]];
	}

	for (int i = 1; i < range; i++)
	{
		count_array[i] = count_array[i] + count_array[i - 1];
	}

	for (int i = 0; i < size; i++)
	{
		output_array[--count_array[arr[i]]] = arr[i];
	}


	for (int i = 0; i < size; i++)
	{
		arr[i] = output_array[i];
	}
}

void sortShell(int* arr, int size)
{
	int temp = 0;
	for (int i = size / 2; i >= 1; i /= 2)
	{
		for (int j = i; j < size; ++j)
		{
			for (int k = j; k >= i; k -= i)
			{
				if (arr[k - i] > arr[k])
				{
					temp = arr[k];
					arr[k] = arr[k - i];
					arr[k - i] = temp;
				}
			}
		}
	}
}
