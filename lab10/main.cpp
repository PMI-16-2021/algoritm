#include<iostream>
#include "tree.h"
using namespace std;


int main() {
    AVLTree avl;
    root = avl.insert(root, 10);
    root = avl.insert(root, 20);
    root = avl.insert(root, 30);
    root = avl.insert(root, 40);
    root = avl.insert(root, 50);
    root = avl.insert(root, 25);
    avl.search(20);
    cout << "Height: " << avl.height(root) << endl;

    avl.print(root, 1);
    cout << "\n-------------------------------------------" << endl;
    avl.deleteNode(root, 50);
    avl.deleteNode(root, 25);
    avl.deleteNode(root, 10);
    avl.print(root, 1);
    cout << endl;
    cout << "-------------------------------------------" << endl;
    system("pause");
    return 0;
}