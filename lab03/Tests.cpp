
#include "Tests.h"

bool TestEnQueue() {
    Queue_withP<int> Q;
    Q.enqueue(1,3);
    Q.enqueue(2,5);
    Q.enqueue(3,1);
    if(Q.getTop()==3)
    {
        return true;
    }
    return false;
}

bool TestDequeue() {
    Queue_withP<string> Q;
    Q.enqueue("c",3);
    Q.enqueue("a",1);
    Q.enqueue("b",2);
    Q.dequeue();
    if(Q.getTop()=="b")
    {
        return true;
    }
    return false;
}


bool TestIsEmpty() {
    Queue_withP<string> Q;
//    Q.enqueue("a",1);
    if(Q.isEmpty())
    {
        return true;
    }
    return false;
}


















void Test1()
{
    assert(TestEnQueue()==true);
    std::cout<<"Test on enqueue() is PASSED!\n";

}
void Test2()
{
    assert(TestDequeue()==true);
    std::cout<<"Test on dequeue() is PASSED!\n";
}
void Test3()
{
    assert(TestIsEmpty()==true);
    std::cout<<"Test on isEmpty() is PASSED!\n";
}

