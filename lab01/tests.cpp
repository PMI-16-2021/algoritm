
#include "tests.h"
//
// Created by Sofia Demchuk on 13.03.2022.
//
static int Array[10]={28,61,84,0,34,1,6,8,5,2};
static int sortedArray[10]={0,2,5,6,8,11,28,34,61,84};
static int contraryArray[10]={84,61,34,28,11,8,6,5,2,0};
static int orderArray[10]={0,2,5,6,8,11,28,34,61,84};



bool TestBubble1() {

    BubbleSort(Array,10);
    for(int i=0;i<10;++i){
        if(Array[i] !=sortedArray[i]) // тестуванн рандомного масиву
            return false;
    }

    return true;
}
bool TestBubble2() {
    BubbleSort(orderArray,10);
    for(int i=0;i<10;++i){
        if(orderArray[i]!=sortedArray[i]) // тестування впорядкованого масиву
            return false ;
    }
    return true;
}

bool TestBubble3() {
    BubbleSort(contraryArray,10);//тестування перевернутого масиву
    for(int i=0;i<10;++i){
        if(contraryArray[i]!=sortedArray[i])
            return false;
    }
    return true;
}

//----------------------------------------------------------------------

bool TestHeap1() {

    heapSort(Array,10);
    for(int i=0;i<10;++i){
        if(Array[i] !=sortedArray[i]) // тестуванн рандомного масиву
            return false;
    }
    return true;
}
bool TestHeap2() {
    heapSort(orderArray,10);
    for(int i=0;i<10;++i){
        if(orderArray[i]!=sortedArray[i])// тестування впорядкованого масиву
            return false;
    }
    return true;
}

bool TestHeap3() {
    heapSort(contraryArray,10);
    for(int i=0;i<10;++i){
        if(contraryArray[i]!=sortedArray[i])//тестування перевернутого масиву
            return false;
    }
    return true;
}

//----------------------------------------------------------------------

bool TestShell1() {
    shellSort(Array,10);
    for(int i=0;i<10;++i){
        if(Array[i] !=sortedArray[i]) // тестуванн рандомного масиву
            return false;
    }
    return true;
}
bool TestShell2() {
    shellSort(orderArray,10);
    for(int i=0;i<10;++i){
        if(orderArray[i]!=sortedArray[i])// тестування впорядкованого масиву
            return false;
    }
    return true;
}
bool TestShell3() {
    shellSort(contraryArray,10);
    for(int i=0;i<10;++i){
        if(contraryArray[i]!=sortedArray[i])//тестування перевернутого масиву
            return false;
    }
    return true;
}
//----------------------------------------------------------------------
bool TestBucket1() {
    BucketSort(Array,10);
    for(int i=0;i<10;++i){
        if(Array[i]!=sortedArray[i]) // тестуванн рандомного масиву
            return false;
    }
    return true;
}

bool TestBucket2() {
    BucketSort(orderArray,10);
    for(int i=0;i<10;++i){
        if(orderArray[i]!=sortedArray[i])// тестування впорядкованого масиву
            return false;
    }
    return true;
}

bool TestBucket3() {
    BucketSort(contraryArray,10);
    for(int i=0;i<10;++i){
        if(contraryArray[i]!=sortedArray[i])//тестування перевернутого масиву
            return false;
    }
    return true;
}

//----------------------------------------------------------------------

void TestBubblePass(){
    assert(TestBubble1()==true);
    cout<<"\nSorting of random array by BubbleSort PASSED!\n";
    assert(TestBubble2()==true);
    cout<<"\nSorting of ordered array by BubbleSort PASSED!\n";
    assert(TestBubble3()==true);
    cout<<"\nSorting of contrary array by BubbleSort PASSED!\n";

}
void TestHeapPass() {
    assert(TestHeap1()==true);
    cout<<"\nSorting of random array by HeapSort PASSED!\n";
    assert(TestHeap2()==true);
    cout<<"\nSorting of ordered array by HeapSort PASSED!\n";
    assert(TestHeap3()==true);
    cout<<"\nSorting of contrary array by HeapSort PASSED!\n";
}


void TestShellPass() {
    assert(TestShell1()==true);
    cout<<"\nSorting of random array by ShellSort PASSED!\n";
    assert(TestShell2()==true);
    cout<<"\nSorting of ordered array by ShellSort PASSED!\n";
    assert(TestShell3()==true);
    cout<<"\nSorting of contrary array by ShellSort PASSED!\n";

}

void TestBucketPass() {
    assert(TestBucket1()==true);
    cout<<"\nSorting of random array by BucketSort PASSED!\n";
    assert(TestBucket2()==true);
    cout<<"\nSorting of ordered array by BucketSort PASSED!\n";
    assert(TestBucket3()==true);
    cout<<"\nSorting of contrary array by BucketSort PASSED!\n";

}







