#include <iostream>
using namespace std;
#include <string>
#include "header.h"
#include "Tests.h"
int main() {
  Queue_withP<string> Q;
  Q.enqueue("f",5);
  Q.enqueue("a11",1);
  Q.enqueue("a1",1);
  Q.enqueue("c",3);
  Q.enqueue("d",4);
  Q.enqueue("b",2);
  Q.print();


  Q.print();



  Test1();
  Test2();
  Test3();
  Test4();
    return 0;
}
