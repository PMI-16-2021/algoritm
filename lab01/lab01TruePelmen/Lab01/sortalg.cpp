#include<iostream>
#include "sortalg.h"
using namespace std;

void ShowArray(int arr[], int size)
{
	for (int i = 0; i < size; ++i)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
}
void BubbleSort(int arr[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = size - 1; j > i; j--)
		{
			if (arr[j] < arr[j - 1])
			{

				int temp = arr[j];
				arr[j] = arr[j - 1];
				arr[j - 1] = temp;
			}
		}
	}

}
void QuickSort(int arr[], int first, int last)
{
	int middleValue = arr[(first + last) / 2];
	int i = first;
	int j = last;
	do
	{
		while (arr[j] > middleValue)
			j--;
		while (arr[i] < middleValue)
			i++;
		if (i <= j)
		{
			swap(arr[i], arr[j]);
			i++;
			j--;
		}


	} while (i <= j);
	if (j > first)
	{
		QuickSort(arr, first, j);
	}
	if (i < last)
	{
		QuickSort(arr, i, last);
	}
}
void ShellSort(int arr[], int size) {
	for (int temp = size / 2; temp > 0; temp /= 2)
	{
		for (int i = temp; i < size; ++i)
		{
			for (int j = i; j >= temp && arr[j - temp] > arr[j]; j -= temp)
			{
				swap(arr[j], arr[j - temp]);
			}
		}
	}
}
void CountSort(int* arr, int size)
{
	int max = 0;
	for (int i = 0; i < size; i++)
	{
		if (max < arr[i])
		{
			max = arr[i];
		}
	}
	int* arr1 = new int[max + 1];
	for (int i = 0; i < max + 1; i++)
	{
		arr1[i] = 0;
	}
	for (int i = 0; i < size; i++)
	{
		++arr1[arr[i]];
	}
	for (int i = 0, j = 0; i <= max; ++i)
	{
		while (arr1[i] > 0)
		{
			arr[j] = i;
			++j;
			--arr1[i];
		}
	}
	delete[] arr1;
}