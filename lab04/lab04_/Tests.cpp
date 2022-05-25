#include "Tests.h"
bool TestTableConstructor()
{
    HTable H;
    assert(H.getSize()==0);
    return true;
}

bool TestAdd()
{
    HTable H(2);
    H.add("abba","first");
    H.add("baba","second");
    assert(H.getSize()==2);
    return true;
}

bool TestPop()
{
    HTable H(10);
    H.add("abba","first");
    H.add("baba","second");
    H.add("violet","third");
    H.add("cucumber","forth");
    H.pop("baba");
    return true;
}

bool TestFind()
{
    HTable H(5);
    H.add("abba","first");
    H.add("baba","second");
    assert(H.find("baba")==true);
    return true;
}

void Test1()
{
    assert(TestTableConstructor()==true);
    cout<<"Test on table Constructor is PASSED\n";
}
void Test2()
{
    assert(TestAdd()==true);
    cout<<"Test on add() method is PASSED\n";
}
void Test3()
{
    assert(TestPop()==true);
    cout<<"Test on pop() method is PASSED\n";
}
void Test4()
{
    assert(TestFind()==true);
    cout<<"Test on find() method is PASSED\n";
}
