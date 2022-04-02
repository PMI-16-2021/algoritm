#include "sorts.h"
#include <iostream>
void PrintArr(const int* arr, int lenght){
    for(int i = 0; i < lenght; ++i){
        std::cout<<'['<<i<<"] : "<<arr[i]<<'\t';
    }
}
void StartSorting(int* arr, int lenght){
    std::cout<<"Sorting Algorythms menu\n";
    std::cout<<"Insertion Sort — press 1\n";
    std::cout<<"Quick Sort — press 2\n";
    std::cout<<"Counting Sort — press 3\n";
    std::cout<<"Merge Sort — press 4\n";
    std::cout<<": ";
    short int choice;
    std::cin >> choice;
    switch (choice) {
        case 1:
            std::cout<<"Unsorted array:\n";
            PrintArr(arr, lenght);
            std::cout<<"\n";
            InsertionSort(arr, lenght);
            std::cout<<"Sorted array:\n";
            PrintArr(arr, lenght);
            std::cout<<"\n";
            break;
        case 2:
            std::cout<<"Unsorted array:\n";
            PrintArr(arr, lenght);
            std::cout<<"\n";
            QuickSort(arr, 0, lenght-1);
            std::cout<<"Sorted array:\n";
            PrintArr(arr, lenght);
            std::cout<<"\n";
            break;
        case 3:
            std::cout<<"Unsorted array:\n";
            PrintArr(arr, lenght);
            std::cout<<"\n";
            CountingSort(arr, lenght);
            std::cout<<"Sorted array:\n";
            PrintArr(arr, lenght);
            std::cout<<"\n";
            break;
        case 4:
            std::cout<<"Unsorted array:\n";
            PrintArr(arr, lenght);
            std::cout<<"\n";
            MergeSort(arr, 0, lenght-1);
            std::cout<<"Sorted array:\n";
            PrintArr(arr, lenght);
            std::cout<<"\n";
            break;
        default:
            std::cout<<"Unknown command\n";
            break;
    }
}
//---------------------InsertionSort-------------------------
void InsertionSort(int* arr, const int lenght){
    int fixed_element;
    int outterIndex, inner_index;
    for(outterIndex = 1; outterIndex < lenght; ++outterIndex){
        fixed_element = arr[outterIndex];
        inner_index = outterIndex - 1;
        while(inner_index >= 0 && arr[inner_index] > fixed_element){
            arr[inner_index + 1] = arr[inner_index];
            --inner_index;
        }
        arr[inner_index + 1] = fixed_element;
    }
}
//------------------------------------------------------------
//---------------------QuickSort------------------------------
void SwapElements(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
// 71 74 98 3 83 9 50 92
int Partition(int* arr, int bottom, int top){
    int pivot  = arr[top];
    int i = bottom - 1;
    int j = bottom;
    for(; j < top; j++){
        if(arr[j] <= pivot){
            i++;
            SwapElements(&arr[i], &arr[j]);
        }
    }
    SwapElements(&arr[i+1], &arr[top]);
    return i+1;
}
void QuickSort(int* arr, int bottom, int top){
    if(bottom < top){
        int sub_wall = Partition(arr, bottom, top);

       QuickSort(arr, bottom, sub_wall-1); // sorting left subarray
       QuickSort(arr, sub_wall+1, top); // sorting right subarray
    }
}
//------------------------------------------------------------
//---------------------CountingSort------------------------------
int FindMax(int* arr, int lenght){
    if(lenght > 0){
        int max  = 0;
        for(int i = 0; i < lenght; i++){
            if(arr[i] > max)
                max = arr[i];
        }
        return max;
    }
    return 0;
}
void CountingSort(int* arr, int lenght){

    int counters_size = FindMax(arr, lenght) + 1;
    int counters_arr[counters_size];
    int result_arr[lenght];

    for (int i = 0; i < counters_size; ++i){
        counters_arr[i] = 0;
    }
    for (int i = 0; i < lenght; i++){
        counters_arr[arr[i]]++;
    }
    for (int i = 1; i <= counters_size; i++){
        counters_arr[i] += counters_arr[i-1];

    }
    for (int i = 0; i < lenght ; i++) {
        result_arr[counters_arr[arr[i]] - 1] = arr[i];
        counters_arr[arr[i]]--;
    }
    for (int i = 0; i < lenght; i++){
        arr[i] = result_arr[i];
    }
}
//------------------------------------------------------------
//---------------------MergeSort------------------------------
void Merge(int* arr, int start, int middle, int end){
    int l_size = middle - start + 1;
    int r_size = end - middle;
    int left_arr[l_size];
    int right_arr[r_size];

    for (int i = 0; i < l_size; i++) {
        left_arr[i] = arr[start + i];
    }
    for (int i = 0; i < r_size; i++) {
        right_arr[i] = arr[middle + 1 + i];
    }
    //Start indexes of sub-arrays and main array
    int i = 0; int j = 0; int k = start;
    while(i < l_size && j < r_size){
        if(left_arr[i] <= right_arr[j]){
            arr[k] = left_arr[i];
            ++i;
        }
        else{
            arr[k] = right_arr[j];
            ++j;
        }
        ++k;
    }
    // 2 more cycles for picking up remained elements
    while(i < l_size){
        arr[k] = left_arr[i];
        ++i;
        ++k;
    }
    while(j < r_size){
        arr[k] = right_arr[j];
        ++j;
        ++k;
    }
}
void MergeSort(int* arr, int start, int end){
    if(start > end)
        return;
    if(start < end){
        int middle = (start + end) / 2;
        MergeSort(arr, start, middle);
        MergeSort(arr, middle + 1, end);
        Merge(arr, start, middle, end);
    }
}
//------------------------------------------------------------
