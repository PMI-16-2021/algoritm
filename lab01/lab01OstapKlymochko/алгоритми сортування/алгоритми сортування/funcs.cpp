#include"funcs.h"
#include<iostream>
void swap(int* a, int* b)
{
	int c = *a;
	*a = *b;
	*b = c;
}

void print(int* arr, unsigned n)
{
	for (unsigned i = 0;i < n;++i)
	{
		std::cout << arr[i] << ' ';
	}
	std::cout << '\n';
}

void bubbleSort(int* arr, unsigned n)
{
	for (int i = 1;i < n;++i)
	{
		for (int j = 0;j < n;++j)
		{
			if (arr[j] > arr[i])
			{
				swap(&arr[i], &arr[j]);

			}
		}
	}
}

void randArray(int* arr, unsigned n)
{
	for (int i = 0;i < n;++i)
	{
		arr[i] = rand();
	}
}


void quickSort(int* arr, unsigned int n, int left, int right)
{
	int i = left,
		j = right;

	int middle = (right + left) / 2;

	int x = arr[middle];


	do
	{
		while (arr[i] < x)
		{
			++i;
		}

		while (x < arr[j])
		{
			--j;
		}

		if (i <= j)
		{
			/*w = Array[iter];
			Array[iter] = Array[jter];
			Array[jter] = w;*/
			swap(&arr[i], &arr[j]);

			++i;
			--j;
		}
		print(arr, n);
	} while (i < j);

	if (left < j)
	{
		quickSort(arr, n, left, j);
	}

	if (i < right)
	{
		quickSort(arr, n, i, right);
	}
}

void countingSort(int* arr, unsigned n, int place)
{
	int output[1000];
	int count[10]{ 0 };
	for (int i = 0;i < n;++i)
	{
		count[(arr[i] / place) % 10]++;
	}
	for (int i = 1;i < 10;++i)
	{
		count[i] += count[i - 1];
	}
	for (int i = n - 1;i >= 0;--i)
	{
		output[count[(arr[i] / place) % 10] - 1] = arr[i];
		count[(arr[i] / place) % 10]--;
	}
	for (int i = 0;i < n;++i)
	{
		arr[i] = output[i];
	}
}

void shellSort(int* arr, unsigned n)
{
	int group, i, j;
	group = n / 2;
	while (group > 0)
	{
		for (i = 0;i < n - group;++i)
		{
			j = i;
			while (j >= 0 && arr[j] > arr[j + group])
			{
				swap(&arr[j], &arr[j + group]);
				--j;
			}
		}
		group /= 2;
	}
}

void reverseArray(int* arr, unsigned n)
{
	int j = n - 1;
	for (int i = 0;i < n / 2;++i)
	{
		swap(&arr[i], &arr[j]);
		--j;
	}
}



