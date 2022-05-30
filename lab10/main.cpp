#include<iostream>
#include "tree.h"
using namespace std;

int main()
{
    Tree<int> T;
    cout << "Height of AVL Tree: " << T.getHeight() << "\n";
    T.insert(14);
    T.insert(11);
    T.insert(4);
    T.insert(9);
    T.print();
    cout << "Height of AVL Tree: " << T.getHeight() << "\n";
    T.insert(7);
    T.insert(1);
    T.insert(3);
    T.insert(6);
    T.print();
    cout << "Height of AVL Tree: " << T.getHeight() << "\n";
    T.remove(7);
    T.remove(3);
    T.print();
    cout << "Height of AVL Tree: " << T.getHeight() << "\n";
    
    return 0;
}