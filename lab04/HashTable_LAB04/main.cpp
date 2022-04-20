#include "HashTable.h"
#include <string>
#include<vector>
#include<deque>
#include<list>
using namespace std;

int main()
{
    HashTable hash(5);
    string s, n, k;
    double m;
    int c;
    int size;
    while (1)
    {
        cout << "1.Insert element into the table" << endl;
        cout << "2.Search element from the key" << endl;
        cout << "3.Delete element at a key" << endl;
        cout << "4.Print a table" << endl;
        cout << "5.Exit" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        switch (c)
        {
        case 1:
        {
            cout << "Enter surname of student to be inserted: ";
            cin >> s;
            cout << "Enter name of student to be inserted: ";
            cin >> n;
            cout << "Enter mark at which element to be inserted: ";
            cin >> m;
            Row student(s, n, m);
            hash.add(student);
            break;
        }
        case 2:
        {
            cout << "Enter key of the element to be searched: ";
            cin >> k;
            if (hash.find(k) == -1)
            {
                cout << "No element found at key " << k << endl;
                continue;
            }
            else
            {
                cout << "Element at key " << k << " : ";
                cout << hash.find(k) << endl;
            }
            break;
        }
        case 3:
        {
            cout << "Enter key of the element to be deleted: ";
            cin >> k;
            hash.pop(k);
            break;
        }
        case 4:
        {
            cout << "Table: ";
            hash.print();
            break;
        }
        case 5:
        {
            exit(1);
        }
        default:
            cout << "\nEnter correct option\n";
        }
    }

  
   
    
   

    return 0;
}