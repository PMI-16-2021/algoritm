#include <iostream>
using namespace std;
#include <string>
#include "cassert"
#include "Queue.h"
#include "list.h"


bool ListPushBack();// test on method push_back() - add a value from the end
bool ListPushFront();// test on method push_front()-add a value from the top
bool ListPopbyIndex();// test on method pop() - delete a value by index
bool ListPop();// test on method pop_front()- delete from front
bool ListClear();// test on method clear() - clear all list
bool ListgetSize();// test on method getSize()

bool TestEnQueue(); // test on method enqueue() - add a member of queue
bool TestDequeue(); // test on method dequeue() - delete the top
bool TestonCount(); // test on method isEmpty() - check if a queue is empty or not


void Test1();
void Test2();
void Test3();
void Test4();
void Test5();
void Test6();
void Test7();
void Test8();
void Test9();