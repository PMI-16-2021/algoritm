#include "tests.h"
#include "priorityQueue.h"
using namespace std;

PriorityQueue<int> queue;
int prior_arr[9] = { 7,6,9,2,4,3,8,6,5 };

void sizeTest()
{
    queue.Enqueue(1, 4);
    queue.Enqueue(2, 0);
    queue.Enqueue(3, 4);
    bool result = true ? queue.Size() == 3 : false;
    if (result)
    {
        cout << "Size test passed\n";
    }
    else
    {
        cout << "Size test failed\n";
    }
}

void topTest()
{
    bool result = true ? queue.Top() == 2 : false;
    if (result)
    {
        cout << "Top test passed\n";
    }
    else
    {
        cout << "Top test failed\n";
    }
}

void emptyTest()
{
    bool result = true ? queue.IsEmpty() == false : false;
    if (result)
    {
        cout << "Empty test passed\n";
    }
    else {
        cout << "Empty test failed\n";
    }
}

void clearTest()
{
    queue.ClearQueue();
    bool result = queue.IsEmpty();
    if (result)
    {
        cout << "Clear test passed\n";
    }
    else
    {
        cout << "Clear test failed\n";
    }
}

void enqueueTest() {
    queue.Enqueue(2, 3);
    queue.Enqueue(5, 7);
    queue.Enqueue(7, 0);
    queue.Enqueue(6, 1);
    queue.Enqueue(9, 2);
    queue.Enqueue(4, 4);
    queue.Enqueue(3, 5);
    queue.Enqueue(8, 5);
    queue.Enqueue(6, 6);
    bool result = true;
    for (int i = 0; i < queue.Size(); ++i)
    {
        if (queue.AtIndex(i).value.value != prior_arr[i])
        {
            result = false;
        }
    }
    if (result)
    {
        cout << "Enqueue test passed\n";
    }
    else {
        cout << "Enqueue test failed\n";
    }
}
void dequeueTest()
{
    bool result = true;
    for (int i = 0; i < queue.Size(); ++i)
    {
        if (queue.Dequeue() != prior_arr[i])
        {
            result = false;
        }
    }
    if (result)
    {
        cout << "Dequeue test passed\n";
    }
    else {
        cout << "Dequeue test failed\n";
    }
}