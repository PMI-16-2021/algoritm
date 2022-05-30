#include <iostream>
#include "Tree.h"
using namespace std;

int main()
{
    Tree T;
    cout << "Height:" << T.height() << "\n";
    T.insert(3);
    T.insert(7);
    T.insert(1);
    T.print();
    cout << "Height:" << T.height() << "\n\n";
    T.remove(3);
    T.remove(1);
    T.print();
    cout << "Height:" << T.height() << "\n\n";

    system("pause");
    return 0;
}
