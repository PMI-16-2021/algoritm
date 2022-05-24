#include "Test.h"

bool TestAdd()
{
    Set set;
    set.add('a');
    set.add('b');
    assert(set.len()==2);
    return true;

}
bool TestDel()
{
    Set set;
    set.add('a');
    set.add('b');
    set.add('3');
    set.del('b');
    assert(set.len()==2);
    return true;
}
bool TestContain()
{
    Set set;
    set.add('a');
    set.add('b');
    set.add('3');
    set.del('b');
    assert(set.inSet('a')==true);
    assert(set.inSet('b')==false);
    return true;
}
bool TestUnion()
{
    Set set;
    set.add('a');
    set.add('2');
    set.add('3');
    Set set2;
    set2.add('r');
    set2.add('2');
    set2.add('s');
    Set set3 = set.unionSet(set2);
    char array[5]={'a','2','3','r','s'};
    for(int i=0;i<set3.len();++i)
    {
        assert(set3[i]==array[i]);
    }
    return true;

}
bool TestIntersection()
{
    Set set;
    set.add('a');
    set.add('2');
    set.add('3');
    Set set2;
    set2.add('r');
    set2.add('2');
    set2.add('l');
    set2.add('3');
    Set set3=  set.intersection(set2);
    char array[2]={'2','3'};
    for(int i=0;i<set3.len();++i)
    {
        assert(set3[i]==array[i]);
    }
    return true;

}
bool TestDifference()
{
    Set set;
    set.add('a');
    set.add('2');
    set.add('3');
    Set set2;
    set2.add('r');
    set2.add('2');
    set2.add('l');
    set2.add('3');
    Set set3= set.difference(set2);
    char array[2]={'a'};
    for(int i=0;i<set3.len();++i)
    {
        assert(set3[i]==array[i]);
    }
    return true;
}
bool TestSymDiff()
{
    Set set;
    set.add('a');
    set.add('2');
    set.add('3');
    Set set2;
    set2.add('r');
    set2.add('2');
    set2.add('l');
    set2.add('3');
    Set set3= set.symmetricDifference(set2);
    char array[3]={'a','r','l'};
    for(int i=0;i<set3.len();++i)
    {
        assert(set3[i]==array[i]);
    }
    return true;
}

void Test1()
{
    assert(TestAdd()==true);
    cout<< "Test on method add() is PASSED!\n";

}
void Test2()
{
    assert(TestDel()==true);
    cout<< "Test on method del() is PASSED!\n";
}
void Test3()
{
    assert(TestContain()==true);
    cout<< "Test on method inSet() is PASSED!\n";
}
void Test4()
{
    assert(TestUnion()==true);
    cout<< "Test on method union() is PASSED!\n";
}
void Test5()
{
    assert(TestIntersection()==true);
    cout<< "Test on method intersection() is PASSED!\n";
}
void Test6()
{
    assert(TestDifference()==true);
    cout<< "Test on method difference() is PASSED!\n";
}
void Test7()
{
    assert(TestSymDiff()==true);
    cout<< "Test on method symmetricDifference() is PASSED!\n";
}