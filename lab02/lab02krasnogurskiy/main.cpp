#include<iostream>
#include"stack.h"
#include"set_of_stacks.h"
using namespace std;

int main(){

    int a = 7; 
    Stack S2(9);
    S2.push(2);
    S2.push(1);
    S2.push(0);
    S2.push(6);
    S2.push(4);
    S2.push(1);
    
    S2.emplace(a);
    S2.print();
    cout << "\n" << S2.topVal();
    cout << '\n';
    

	system("pause");
	return 0;
}