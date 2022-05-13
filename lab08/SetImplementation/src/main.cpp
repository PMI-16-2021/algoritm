#include <iostream>
#include "MySet.h"

int main() {
    MySet<int> mySet1;
    mySet1.Add(1);
    mySet1.Add(2);
    mySet1.Add(3);
    mySet1.Add(4);
    mySet1.Add(5);

    MySet<int> mySet2;
    mySet2.Add(10);
    mySet2.Add(11);
    mySet2.Add(12);
    mySet2.Add(13);
    mySet2.Add(14);
    mySet2.Add(5);
    mySet2.Add(3);

    MySet<int> unionSet = mySet1.UnionSet(mySet2);
    unionSet.Print();

    MySet<int> intersection = mySet1.Intersection(mySet2);
    intersection.Print();

    MySet<int> difference = mySet1.Difference(mySet2);
    difference.Print();

    MySet<int> symmetricDifference = mySet1.SymmetricDifference(mySet2);
    symmetricDifference.Print();

    return 0;
}
