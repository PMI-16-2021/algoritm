
#include "Tests.h"


bool TestOnInsert()
{
    Tree<int> tree;
    tree.Insert(6);
    tree.Insert(3);
    tree.Insert(2);
    tree.Insert(1);
    tree.Insert(10);
    tree.Insert(11);
    assert(tree.Contain(3)==true);
    assert(tree.Contain(11)==true);
    return true;

}
bool TestOnFind()
 {
     Tree<int> tree;
     assert(tree.Contain(3)==false);
     assert(tree.Contain(11)==false);
     return true;
 }
bool TestOnRemove()
 {
     Tree<int> tree;
     tree.Insert(6);
     tree.Insert(3);
     tree.Insert(2);
     assert(tree.Contain(3)==true);
     tree.Remove(3);
     assert(tree.Contain(3)==false);
     return true;
 }
bool TestOnBalance()
 {
     Tree<int> tree;
     tree.Insert(6);
     tree.Insert(3);
     tree.Insert(2);
     tree.Insert(1);
     assert(tree.Is_Balanced()==true);
     return true;
 }

void Test1()
{
    assert(TestOnInsert()==true);
    cout<<"Test in method insert() is PASSED\n";

}
void Test2()
{
    assert(TestOnFind()==true);
    cout<<"Test in method find() is PASSED\n";

}
void Test3()
{
    assert(TestOnRemove()==true);
    cout<<"Test in method remove() is PASSED\n";
}
void Test4()
{
    assert(TestOnBalance()==true);
    cout<<"Test in method balance() is PASSED\n";
}
