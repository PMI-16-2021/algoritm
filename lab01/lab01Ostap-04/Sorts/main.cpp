#include <iostream>
#include "sorts.h"

using namespace std;

int main()
{
    const int size_of_array = 11;

    cout << "BubbleSort:\n";
    cout << "Array:        ";
    int array_1[size_of_array] = { -8, -2, -10, 1, 6, 9, 12, 0, -2, -8, 10 };
    PrintArray(array_1, size_of_array);
    BubbleSort(array_1, size_of_array);
    cout << "Sorted Array: ";
    PrintArray(array_1, size_of_array);

    cout << "QuickSort:\n";
    cout << "Array:        ";
    int array_2[size_of_array] = { -8, -2, -10, 1, 6, 9, 12, 0, -2, -8, 10 };
    PrintArray(array_2, size_of_array);
    QuickSort(array_2, 0, size_of_array - 1);
    cout << "Sorted Array: ";
    PrintArray(array_2, size_of_array);

    cout << "CountSort:\n";
    cout << "Array:        ";
    int array_3[size_of_array] = { -8, -2, -10, 1, 6, 9, 12, 0, -2, -8, 10 };
    PrintArray(array_3, size_of_array);
    CountSort(array_3, size_of_array);
    cout << "Sorted Array: ";
    PrintArray(array_3, size_of_array);

    cout << "ShellSort:\n";
    cout << "Array:        ";
    int array_4[size_of_array] = { -8, -2, -10, 1, 6, 9, 12, 0, -2, -8, 10 };
    PrintArray(array_4, size_of_array);
    ShellSort(array_4, size_of_array);
    cout << "Sorted Array: ";
    PrintArray(array_4, size_of_array);

    system("pause");
    return 0;
}