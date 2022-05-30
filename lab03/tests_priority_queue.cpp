#include "tests_priority_queue.h"

bool testIsEmpty()
{
    PriorityQueue<int> Q;
    Q.enqueue(3, 0);
    Q.dequeue();
    if (Q.getSize() == 0)
        return true;
    return false;
}

void resultIsEmpty()
{
    assert(testIsEmpty() == true);
    std::cout << "Test isEmpty is passed\n";
}

bool testSize()
{
    PriorityQueue<int> Q;
    Q.enqueue(3, 0);
    Q.enqueue(4, 1);
    if (Q.getSize() == 2)
        return true;
    return false;
}

void resultSize()
{
    assert(testSize() == true);
    std::cout << "Test getSize is passed\n";
}

bool testDelete()
{
    PriorityQueue<int> Q;
    Q.enqueue(3, 0);
    Q.enqueue(4, 1);
    Q.deleteQueue();
    if (Q.getSize() == 0)
        return true;
    return false;
}

void resultDelete()
{
    assert(testDelete() == true);
    std::cout << "Test deleteQueue is passed\n";
}

bool testTop()
{
    PriorityQueue<int> Q;
    Q.enqueue(3, 0);
    if (Q.top() == 3)
        return true;
    return false;
}

void resultTop()
{
    assert(testTop() == true);
    std::cout << "Test top is passed\n";
}

bool testEnqueue()
{
    PriorityQueue<int> Q;
    Q.enqueue(4, 1);
    Q.enqueue(3, 0);
    if (Q.getSize() == 2 && Q.top() == 3)
        return true;
    return false;
}

void resultEnqueue()
{
    assert(testEnqueue() == true);
    std::cout << "Test enqueue is passed\n";
}

bool testDequeue()
{
    PriorityQueue<int> Q;
    Q.enqueue(4, 1);
    Q.enqueue(3, 0);
    Q.dequeue();
    if (Q.getSize() == 1 && Q.top() == 4)
        return true;
    return false;
}

void resultDequeue()
{
    assert(testDequeue() == true);
    std::cout << "Test dequeue is passed\n";
}