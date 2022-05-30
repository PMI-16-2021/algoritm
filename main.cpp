#include <iostream>
#include "set.h"
#include "tests.h"
using namespace std;

int main() {

    resultAdd();
    resultRemove();
    resultIn();
    resultLen();
    resulUnion();
    resultIntersection();
    resultDifference();
    resultSymmetricDifference();
    cout << "\n";
    MySet s;
    s.add('a');
    s.add('d');
    s.add('f');
    s.add('w');
    s.add('p');
    s.add('k');
    cout << "Set:\n";
    s.print();
    s.remove('a');
    cout << "Set without a:\n";
    s.print();
    MySet s1;
    s1.add('f');
    s1.add('w');
    s1.add('c');
    s1.add('a');
    s1.add('m');
    cout << "Other set:\n";
    s1.print();
    cout << "Similar items:\n";
    s.intersection(s1).print();
    cout << "Different items:\n";
    s.difference(s1).print();
    cout << "Symmetrically different items:\n";
    s.symmetric_difference(s1).print();

    return 0;
}
