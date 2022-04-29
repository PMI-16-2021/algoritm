#include "Tests.h"
bool TestContructor()
{
    Row r1("abba", "a");
    if(!r1.IsEmpty())
    {
        return true;
    }

    return false;
}

bool TestTableConstructor()
{

    Hash_Table H(5);
    assert(H.getCapacity()==5);
    return true;

}
bool TestAdd()
{
    Row r1("abba", "a");
    Row r2("baba","b");
    Hash_Table H(5);
    H.add(r1);
    H.add(r2);
    assert(H.getSize()==2);
    return true;

}
bool TestPop()
{
    Row r1("abba", "a");
    Row r2("baba","b");
    Hash_Table H(5);
    H.add(r1);
    H.add(r2);
    H.pop("abba");
    assert(H.getSize()==1);
    assert(H.find("abba")==false);
    return true;


}
bool TestFind()
{
    Row r1("abba", "a");
    Row r2("baba","b");
    Hash_Table H(5);
    H.add(r1);
    H.add(r2);
    assert(H.find("baba")==true);
    return true;
}

void Test1()
{
    assert(TestContructor()==true);
    cout<<"Test on row Constructor is PASSED\n";
}
void Test2()
{
    assert(TestTableConstructor()==true);
    cout<<"Test on table Constructor is PASSED\n";
}
void Test3()
{
    assert(TestAdd()==true);
    cout<<"Test on add() method is PASSED\n";
}
void Test4()
{
    assert(TestPop()==true);
    cout<<"Test on pop() method is PASSED\n";
}
void Test5()
{
    assert(TestFind()==true);
    cout<<"Test on find() method is PASSED\n";
}
