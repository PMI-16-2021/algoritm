#include <iostream>
#include "sorts.h"
#include "tests.h"
using std::cout;

int main(){
    int arr_int[] = {91, 6, 58, 81, 83, 68, 45, 24, 90, 60};
    const size_t arrSize = sizeof(arr_int)/sizeof(arr_int[0]);
    StartSorting(arr_int, arrSize);
    cout<<"\n\n";
    InsertionSortTest();
    cout<<"\n\n";
    QuickSortTest();
    cout<<"\n\n";
    CountingSortTest();
    cout<<"\n\n";
    MergeSortTest();
    return 0;
}

