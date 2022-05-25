#include <iostream>
using namespace std;

// Swap two elements - Utility function  
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// ������� ����������������� ������ (������ ����� ��������)
int partition(int arr[], int low, int high)
{
    // �������� ������ ������ ������� �� �������
    int pivot = arr[high];
    // �������� �� ������ �������
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // �������� ����� ������� ������
   // ��������� �� �� ������� ������
        if (arr[j] <= pivot)
        {
            // ���� �������� �������, ������ �� ������ �����
      // �������� ���� �� ������ �������, �� ���� ����� i
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    // ��������� ������ �����
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // ������ ������� ������� �����, ��
            // ��������, ����� �� ������ �����, ����������� ���� �� ������ �����
            // ��������, ����� �� ������ �����, ����������� �������� �� ������ �����
        int pivot = partition(arr, low, high);

        quickSort(arr, low, pivot - 1);
        quickSort(arr, pivot + 1, high);
    }
}

void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        cout << arr[i] << "\t";
}