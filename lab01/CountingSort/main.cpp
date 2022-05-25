#include <iostream>
#include "algorithm3.h"

int main() {
    int array[] = { 4, 2, 2, 8, 3, 3, 1 };
    int n = sizeof(array) / sizeof(array[0]);
    countSort(array, n);
    printArray(array, n);
}