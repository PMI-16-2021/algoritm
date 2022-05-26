#include"TreeAvl.h"

void menu() 
{
    cout << "\n__________________________________________";
    cout << "\n\n  --HEIGHT BALANCED BINARY SEARCH TREE--";
    cout << "\n                --(AVL)--";
    cout << "\n__________________________________________";
    cout << "\n\n1. Insert elements into the tree.";
    cout << "\n2. Get Tree Height.";
    cout << "\n3. Search for an element.";
    cout << "\n4. PRE-ORDER Tree-Walk.";
    cout << "\n5. POST-ORDER Tree-Walk.";
    cout << "\n6. Remove an element from the tree.";
    cout << "\n7. Exit.";
    cout << "\n__________________________________________";
    cout << "\nYour Choice -- ";
}

int main() 
{
    AVL_Tree demo;
    int info, input;
    menu();
    cin >> info;
    while (info != 7) 
    {
        switch (info)
        {
        case 1: cout << "\nElement to be inserted -- ";
            cin >> input; demo.insertNode(input);
            break;

        case 2: cout << "Height of the Tree -> ";
            cout << demo.getHeight(demo.getRoot()) + 1 << endl;
            break;

        case 3: cout << "\nElement to be searched -- ";
            cin >> input;
            if (demo.treeSearch(input)) { cout << "Element found.\n"; }
            else { cout << "Element not found.\n"; }
            break;

        case 4: cout << "Pre-Order Tree Walk ";
            demo.preorderTraversal(demo.getRoot());
            cout << endl;
            break;

        case 5: cout << "Post-Order Tree Walk ";
            demo.postorderTraversal(demo.getRoot());
            cout << endl;
            break;

        case 6: cout << "\nElement to be deleted? -- ";
            cin >> input;
            demo.remove(input);
            break;

        default: cout << "Wrong Choice.\n";
        }
        cout << "\nAnything Else?";
        cin >> info;
    }
    cout << "\nTerminating.... ";
    return 0;
}