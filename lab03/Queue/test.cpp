#include "test.h"
#include "priority_queue.h"

PriorityQueue<int> queue;

// v:  2 5 7 6 9 4 3 8 6
// p:  3 7 0 1 2 4 5 5 6
int prior_arr[9] = {7,6,9,2,4,3,8,6,5}; // array with prioritized values

void TestSize(){
    queue.Enqueue(1,4);
    queue.Enqueue(2,0);
    queue.Enqueue(3,4);
    bool result = true ? queue.Size() == 3 : false;
    if(result) {
        std::cout << "Size test passed\n";
    }
    else {
        std::cerr << "Size test failed\n";
    }
}

void TestTop(){
    bool result = true ? queue.Top() == 2 : false;
    if(result) {
        std::cout << "Top test passed\n";
    }
    else {
        std::cerr << "Top test failed\n";
    }
}

void TestEmpty(){
    bool result = true ? queue.IsEmpty() == false : false;
    if(result) {
        std::cout << "TestEmpty passed\n";
    }
    else {
        std::cerr << "TestEmpty failed\n";
    }
}

void TestClear(){
    queue.ClearQueue();
    bool result = queue.IsEmpty();
    if(result) {
        std::cout << "TestClear passed\n";
    }
    else {
        std::cerr << "TestClear failed\n";
    }
}

void TestEnqueue(){
    queue.Enqueue(2,3);
    queue.Enqueue(5,7);
    queue.Enqueue(7,0);
    queue.Enqueue(6,1);
    queue.Enqueue(9,2);
    queue.Enqueue(4,4);
    queue.Enqueue(3,5);
    queue.Enqueue(8,5);
    queue.Enqueue(6,6);
    bool result = true;
    for (int i = 0; i < queue.Size(); ++i) {
        if(queue.AtIndex(i).value.value != prior_arr[i]) {
            result = false;
        }
    }
    if(result) {
        std::cout << "TestEnqueue passed\n";
    }
    else {
        std::cerr << "TestEnqueue failed\n";
    }
}
void TestDequeue(){
    bool result = true;
    for (int i = 0; i < queue.Size(); ++i) {
        if(queue.Dequeue() != prior_arr[i]) {
            result = false;
        }
    }
    if(result) {
        std::cout << "TestDequeue passed\n";
    }
    else {
        std::cerr << "TestDequeue failed\n";
    }
}

