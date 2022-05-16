#include<iostream>
#include<vector>
#define Size 10
#include"Stack.h"

using namespace std;

int main()
{
    /*
    Stack a;
    a.push(5);
    a.push(3);
    a.push(6);
    a.push(8);
    a.push(1);
    a.push(5);
    a.push(8);
    a.push(9);
    a.push(3);
    a.push(2);
    a.print();
    cout << a.showtop() << endl;
    int arr[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    a.swap(arr);
    a.print();
    cout << a.showtop() << endl;
    */

    Set b;
    b.push(5);
    b.push(3);
    b.push(6);
    b.push(8);
    b.push(1);
    b.push(5);
    b.push(8);
    b.push(9);
    b.push(3);
    b.push(2);
    b.push(5);
    b.push(3);
    b.push(6);
    b.push(8);
    b.push(1);
    b.push(5);
    b.push(8);
    b.push(9);
    b.push(3);
    b.push(2);
    b.push(5);
    b.push(8);
    b.push(9);
    b.push(3);
    b.printSet();
    b.popAt(0);
    b.printSet();
    b.pop();
    b.pop();
    b.pop();
    b.pop();
    b.pop();
    b.pop();
    b.pop();
    b.pop();
    b.pop();
    b.printSet();

    system("pause");
    return 0;
}