#include <iostream>
#include <string>
#include"HashTable.h"
using namespace std;
int main()
{
    HashTable a;
    cout << "Empty:" << a.isEmpty() << endl;
    a.add("Abracadabra", 123);
    cout << "Empty:" << a.isEmpty() << endl;
    cout << "Get :" << a.get("Abracadabra") << endl;
    a.pop("Abracadabra");
    cout << "Empty:" << a.isEmpty() << endl;
    a.add("abc", 123);
    a.add("def", 321);
    a.add("ghi", 456);
    a.values();

   
    system("pause");
    return 0;
}