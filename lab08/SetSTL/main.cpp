#include "Set.h"

int main()
{
    MySet<int> A;
    A.add(1);
    A.add(2);
    A.add(3);
    A.add(5);
    A.remove(5);
    A.print();
    MySet<int> B;
    B.add(6);
    B.add(7);
    B.add(5);
    B.add(1);
    MySet<int> C = A.unionSet(B);
    C.print();
    MySet<int> D = A.intersection(B);
    D.print();
    MySet<int> E = A.difference(B);
    E.print();
    MySet<int> H = A.symmetricDifference(B);
    H.print();

    return 0;
}