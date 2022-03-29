
#include "sort.h"


void printOn(const int *arr, int n) {
    for(int i=0;i<n;++i){
        cout<<arr[i]<<" ";
    }

}

void BubbleSort(int *arr, int n) {
    for (int i = 0; i < n; i++) {

        for (int j = 0; j < n-1; j++) {
            if (arr[j] > arr[j + 1]) {
                int b = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = b;
            }
        }
    }
    cout<<"\nSorted array by BubbleSort:";
    printOn(arr,n);
}
void heapify(int arr[], int n, int i) // створюємо дерево бінарне
{
    int max = i;

    int left = 2*i + 1;
    int right = 2*i + 2;


    if (left < n && arr[left] > arr[max])
        max = left;

    if (right < n && arr[right] > arr[max])
        max = right;

    if (max != i){
        swap(arr[i], arr[max]);
        heapify(arr, n, max);
    }
}
void heapSort(int *arr, int n){
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);


    for (int i=n-1; i>=0; i--){

        swap(arr[0], arr[i]); //міняємо нульовий і макс елемень т

        heapify(arr, i, 0);//тим самим відрізаючи гілку з макс елемн
    }
    cout<<"\nSorted array by HeapSort : ";
    printOn(arr,n);
}

int getMax(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;

}



void shellSort(int* arr, int n) {

    for (int interval = n / 2; interval > 0; interval /= 2) { // кожен раз /2
        for (int i = interval; i < n; i += 1) {
            int temp = arr[i];//створюємо тимчасову звінну куди закидаємо елемент
            int j;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            arr[j] = temp;
        }
    }
    cout<<"\nSorted array by ShellSort: ";
    printOn(arr,n);
}

void BucketSort(int *arr, int n) {
    int max= getMax(arr,n);
    int bucket[max];
    for(int i=0;i<=max;++i){//зануляємо
        bucket[i]=0;
    }
    for(int i=0;i<n;++i) {
        bucket[arr[i]]++;
    }
    for(int i = 0, j = 0; i <= max; i++){
        while (bucket[i] > 0){
            arr[j++] = i;//працюємо з двома масивами
            bucket[i]--;
        }
    }
    cout<<"\nSorted array by BucketSort:";
    printOn(arr,n);
}




