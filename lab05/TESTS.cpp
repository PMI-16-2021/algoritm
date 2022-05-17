#include "TESTS.h"

bool TestIsNumber()
{
    char numbers[10] = {'1', '2', '3', '4', '5' ,'6' ,'7', '8','9'};
    for(int i=0;i<10;++i)
    {
        assert(IsNum(numbers[i])==true);
        return true;
    }
}
bool TestIsOperator()
{
    char operators[5] = { '+', '-', '*', '/', '^' };
    for(int i=0;i<5;++i)
    {
        assert(IsOperator(operators[i])==true);
        return true;
    }
}
bool TestPriority()
{
    assert(priority('-')==1);
    assert(priority('+')==1);
    assert(priority('*')==2);
    assert(priority('/')==2);
    assert(priority('^')==3);
    return true;

}
bool TestAdd()
{
    string temp="12 9 +";
    int result = CountExpression(temp);
    assert(result==21);
    return true;

}
bool TestMin()
{
    string temp="12 9 -";
    int result = CountExpression(temp);
    assert(result==3);
    return true;
}
bool TestDiv()
{
    string temp="20 2 /";
    int result = CountExpression(temp);
    assert(result==10);
    return true;
}
bool TestSub()
{
    string temp="5 3 *";
    int result = CountExpression(temp);
    assert(result==15);
    return true;
}


void test1()
{
    assert(TestIsNumber()==true);
    cout<<"Test on method IsNumber() is PASSED!\n";
}
void test2()
{
    assert(TestIsOperator()==true);
    cout<<"Test on method IsNumber() is PASSED!\n";
}
void test3()
{
    assert(TestPriority()==true);
    cout<<"Test on method IsNumber() is PASSED!\n";
}
void test4()
{
    assert(TestMin()==true);
    cout<<"Test on method IsNumber() is PASSED!\n";
}
void test5()
{
    assert(TestAdd()==true);
    cout<<"Test on method IsNumber() is PASSED!\n";
}
void test6()
{
    assert(TestDiv()==true);
    cout<<"Test on method IsNumber() is PASSED!\n";
}
void test7()
{
    assert(TestSub()==true);
    cout<<"Test on method IsNumber() is PASSED!\n";
}
