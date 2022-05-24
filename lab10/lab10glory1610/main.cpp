#include<iostream>
#include "Tree.h"
using namespace std;

int main()
{
    AVL t;
    cout << "Height:" << t.height() << "\n";
    t.insert(20);
    t.insert(25);
    t.insert(15);
    t.insert(10);
    t.print();
    cout << "Height:" << t.height() << "\n";
    t.insert(30);
    t.insert(5);
    t.insert(35);
    t.insert(67);
    t.print();
    cout << "Height:" << t.height() << "\n";
    t.remove(5);
    t.remove(35);
    t.print();
    cout << "Height:" << t.height() << "\n";

    system("pause");
    return 0;
}