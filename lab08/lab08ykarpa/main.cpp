#include <iostream>
#include "mnozhyna.h"
using namespace std;

int main() {
    MySet S1;
    S1.add('1'); 
    S1.add('3'); 
    S1.add('5');
    MySet S2;
    S2.add('3'); 
    S2.add('7'); 
    S2.add('9'); 
    S2.add('5');
    cout << "S1 = "; S1.print();
    cout << "S2 = "; S2.print();

    cout << "S1 U S2 = ";
    S1.Union(S2).print();
    cout << "Peretun S1 i S2 = ";
    S1.intersection(S2).print();
    cout << "S1 - S2 = ";
    S1.difference(S2).print();
    cout << "S2 - S1 = ";
    S2.difference(S1).print();
    cout << "(S1 - S2) U (S2 - S1) = ";
    S1.symmetric_difference(S2).print();

    system("pause");
    return 0;
}