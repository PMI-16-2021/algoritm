#include "tests_priority_queue.h"
#include "priority_queue.h"
using namespace std;

int main() {

    resultSize();
    resultIsEmpty();
    resultDelete();
    resultTop();
    resultEnqueue();
    resultDequeue();
    cout << "\n";
    PriorityQueue<char> queue;
    queue.enqueue('a', 3);
    queue.enqueue('l', 0);
    queue.enqueue('f', 4);
    queue.enqueue('e', 1);
    queue.print();
    queue.dequeue();
    queue.print();
    queue.dequeue();
    queue.print();
    queue.dequeue();
    queue.print();



    return 0;
}
