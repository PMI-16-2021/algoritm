#include "tests.h"
#include "set.h"

bool testAdd()
{
    MySet S;
    S.add('y');
    S.add('x');
    if (S.len() == 2)
        return true;
    return false;
}

void resultAdd()
{
    assert(testAdd() == true);
    std::cout << "Test add is passed\n";
}

bool testRemove()
{
    MySet S;
    S.add('y');
    S.add('x');
    S.remove('y');
    if (S.len() == 1)
        return true;
    return false;
}

void resultRemove()
{
    assert(testRemove() == true);
    std::cout << "Test remove is passed\n";
}

bool testIn()
{
    MySet S;
    S.add('y');
    if (S.in('y'))
        return true;
    return false;
}

void resultIn()
{
    assert(testIn() == true);
    std::cout << "Test in is passed\n";
}

bool testLen()
{
    MySet S;
    S.add('y');
    S.add('x');
    if (S.len() == 2)
        return true;
    return false;
}

void resultLen()
{
    assert(testLen() == true);
    std::cout << "Test len is passed\n";
}

bool testUnion()
{
    MySet S1;
    S1.add('y');
    MySet S2;
    S2.add('x');
    if (S1.unionSet(S2).len() == 2)
        return true;
    return false;
}

void resulUnion()
{
    assert(testUnion() == true);
    std::cout << "Test union is passed\n";
}

bool testIntersection()
{
    MySet S1;
    S1.add('y');
    S1.add('a');
    S1.add('b');
    MySet S2;
    S2.add('x');
    S2.add('y');
    MySet S = S1.intersection(S2);
    if (S.in('y') && S.len() == 1)
        return true;
    return false;
}

void resultIntersection()
{
    assert(testIntersection() == true);
    std::cout << "Test intersection is passed\n";
}

bool testDifference()
{
    MySet S1;
    S1.add('y');
    S1.add('a');
    MySet S2;
    S2.add('y');
    MySet S = S1.difference(S2);
    if (S.in('a') && S.len() == 1)
        return true;
    return false;
}

void resultDifference()
{
    assert(testDifference() == true);
    std::cout << "Test difference is passed\n";
}

bool testSymmetricDifference()
{
    MySet S1;
    S1.add('y');
    S1.add('a');
    MySet S2;
    S2.add('y');
    S2.add('x');
    MySet S = S1.symmetric_difference(S2);
    if (S.in('a') && S.in('x') && S.len() == 2)
        return true;
    return false;
}

void resultSymmetricDifference()
{
    assert(testSymmetricDifference() == true);
    std::cout << "Test symmetric difference is passed\n";
}