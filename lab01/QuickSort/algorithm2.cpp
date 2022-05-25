#include <iostream>
using namespace std;

// Swap two elements - Utility function  
void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

// функція перевпорядкування масиву (знайти точку розбиття)
int partition(int arr[], int low, int high)
{
    // вибираємо крайній правий елемент як опорний
    int pivot = arr[high];
    // вказівник на більший елемент
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++)
    {
        // обходимо кожен елемент масиву
   // порівнюємо їх із опорною точкою
        if (arr[j] <= pivot)
        {
            // якщо знайдено елемент, менший за опорну точку
      // поміняємо його на більший елемент, на який вказує i
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    // повертаємо опорну точку
    return (i + 1);
}


void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        // знайти опорний елемент такий, що
            // Елементи, менші за опорну точку, знаходяться зліва від опорної точки
            // Елементи, більші ніж опорна точка, знаходяться праворуч від опорної точки
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