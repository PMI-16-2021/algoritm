#include <iostream>
#include "AVLTree.h"

using namespace std;

int main() {
    int choice, item;
    avlTree avl;
    while (1) {
        cout << "\n---------------------AVL Tree Implementation---------------------\n" << endl;
        cout << "Choose the option: \n";
        cout << "1.Insert element into the tree\n";
        cout << "2.Delete element from the tree\n";
        cout << "3.Display Tree\n";
        cout << "4.InOrder traversal\n";
        cout << "5.PreOrder traversal\n";
        cout << "6.PostOrder traversal\n";
        cout << "7.Exit\n" << endl;
        cout << "Enter your Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to be inserted: ";
                cin >> item;
                avl.root = avl.insert(avl.root, item);
                break;
            case 2:
                cout << "Enter value to be deleted: ";
                cin >> item;
                avl.root = avl.remove(avl.root, item);
                break;
            case 3:
                if (avl.root == nullptr) {
                    cout << "Tree is Empty" << endl;
                    continue;
                }
                cout << "Balanced AVL Tree:" << endl;
                avl.display(avl.root, 1);
                break;
            case 4:
                cout << "Inorder Traversal:" << endl;
                avl.inorder(avl.root);
                cout << endl;
                break;
            case 5:
                cout << "Preorder Traversal:" << endl;
                avl.preorder(avl.root);
                cout << endl;
                break;
            case 6:
                cout << "Postorder Traversal:" << endl;
                avl.postorder(avl.root);
                cout << endl;
                break;
            case 7:
                exit(1);
                break;
            default:
                cout << "Wrong Choice" << endl;
        }
    }
    return 0;
}
