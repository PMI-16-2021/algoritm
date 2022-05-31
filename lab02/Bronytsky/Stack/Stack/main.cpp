#include<iostream>
#include"setOfStacks.h"
#include"stack.h"

int main()
{
    SetOfStacks S(2);
	S.push(3);
	S.push(3);
	S.push(12);
	S.push(13);
	S.push(78);
	S.push(91);
	S.printSetOfStacks();
	S.popAt(3);
	
	S.printSetOfStacks();

    system("pause");
    return 0;


}