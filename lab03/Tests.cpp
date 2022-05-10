#include "Tests.h"
bool ListPushFront()
{
    List<int> L;
    L.push_front(3);
    L.push_front(1);
    assert(L.getData()==1);
    assert(L.isEmpty()==false);
    return true;
}
bool ListPushBack()
{
    List<int> L;
    L.push_back(3);
    L.push_back(1);
    assert(L.getData()==3);
    assert(L.isEmpty()==false);
    return true ;
}
bool ListPopbyIndex()
{
    List<int> L;
    L.push_back(3);
    L.push_back(1);
    L.push_back(5);
    L.push_back(4);
    L.pop(2);
    assert(L.getSize()==3);
    assert(L.getData()==3);
    return true;
}
bool ListPop()
{
    List<int> L;
    L.push_back(3);
    L.push_back(1);
    L.push_back(5);
    L.push_back(4);
    L.popFront();
    assert(L.getSize()==3);
    assert(L.getData()==1);
    return true;
}
bool ListClear()
{
    List<int> L;
    L.push_back(3);
    L.push_back(1);
    L.push_back(5);
    L.push_back(4);
    L.clear();
    assert(L.getSize()==0);
    assert(L.isEmpty()==true);
    return true;
}
bool ListgetSize()
{
    List<int> L;
    L.push_back(3);
    L.push_back(1);
    L.push_back(5);
    L.push_back(4);
    assert(L.getSize()==4);
    return true;
}

bool TestEnQueue()// test on method enqueue() - add a member of queue
{
    PQueue<int> Q;
    Q.enqueue(3,4);
    Q.enqueue(6,1);
    Q.enqueue(2,2);
    assert(Q.isEmpty()==false);
    assert(Q.getSize()==3);
    return true;
}
bool TestDequeue() // test on method dequeue() - delete the top
{
    PQueue<int> Q;
    Q.enqueue(3,4);
    Q.dequeue();
    assert(Q.isEmpty()==true);
    assert(Q.getSize()==0);
    return true;
}

bool TestonCount() // test on method isEmpty() - check if a queue is empty or not
{
    PQueue<int> Q;
    assert(Q.isEmpty()==true);
    assert(Q.getSize()==0);
    return true;
}

void Test1()
{
    assert(ListPushFront()==true);
    cout<<" Test on push_front() PASSED !!!\n";
}

void Test2()
{
    assert(ListPushBack()==true);
    cout<<" Test on push_back() PASSED !!!\n";
}
void Test3()
{
    assert( ListPopbyIndex()==true);
    cout<<" Test on pop_by_index() PASSED !!!\n";
}

void Test4()
{
    assert( ListPop()==true);
    cout<<" Test on pop_front() PASSED !!!\n";
}
void Test5()
{
    assert( ListClear()==true);
    cout<<" Test on clear() PASSED !!!\n";
}
void Test6()
{
    assert( ListgetSize()==true);
    cout<<" Test on getSize() PASSED !!!\n";
}
void Test7()
{
    assert( TestEnQueue()==true);
    cout<<" Test on enqueue() PASSED !!!\n";
}
void Test8()
{
    assert( TestDequeue() ==true);
    cout<<" Test on dequeue() PASSED !!!\n";
}
void Test9()
{
    assert( TestonCount()==true);
    cout<<" Test on isEmpty() and getSize() PASSED !!!\n";
}