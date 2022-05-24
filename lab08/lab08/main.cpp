#include<iostream>
#include "set.h"
#include "Test.h"
using namespace std;

int main()
{
    Set mySet1;
    mySet1.add('3');mySet1.add('q');mySet1.add('t');
    Set mySet2;
    mySet2.add('2');mySet2.add('q');mySet2.add('t');mySet2.add('a');
    cout<< "UNION SET - ";
    Set unionSet = mySet1.unionSet(mySet2);
    unionSet.print();
    cout<< "INTERSECTION SET - ";
    Set intersection = mySet1.intersection(mySet2);
    intersection.print();
    cout<< "DIFFERENCE SET - ";
    Set difference = mySet1.difference(mySet2);
    difference.print();
    cout<< "SYMETRIC DIFFERENCE SET - ";
    Set symmetricDifference = mySet1.symmetricDifference(mySet2);
    symmetricDifference.print();

//-------TESTS-------
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();



    return 0;
}