#include <iostream>
#include <vector>
#include "tree.h"
using namespace std;

int main() {
    Node* root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 3);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);

    vector<int> v1;
    preOrder(root, v1);
    cout << "Prefix Order" << endl;
    for (auto element : v1) {
        cout << element << "\t";
    }

    vector<int> v2;
    cout << endl;
    postOrder(root, v2);
    cout << "Postfix Order" << endl;
    for (auto element : v2) {
        cout << element << "\t";
    }

    vector<int> v3;
    cout << endl;
    infixOrder(root, v3);
    cout << "Infix Order" << endl;
    for (auto element : v3) {
        cout << element << "\t";
    }
    cout << "\n\n";

    system("pause");
    return 0;
}