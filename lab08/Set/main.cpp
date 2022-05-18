#include "my_set.h"
#include "tests.h"
int main() {
    /*MySet<int> set;
    set.Add(14);
    set.Add(2);
    set.Add(6);
    set.Add(90);
    set.Add(9);
    set.Add(7);
    set.Add(12);
    set.Add(5);
    set.Add(13);
    set.Print();
    std::cout <<'\n';
    MySet<int> another;
    another.Add(45);
    another.Add(14);
    another.Add(8);
    another.Add(90);
    another.Add(11);
    another.Add(12);
    another.Add(1);
    another.Add(5);

    MySet<int> Union = set.Union(another);
    std::cout << "Union: ";
    Union.Print();
    std::cout <<'\n';
    MySet<int> intersection = set.Intersection(another);
    std::cout << "Intersection: ";
    intersection.Print();
    std::cout <<'\n';
    MySet<int> difference = set.Difference(another);
    std::cout << "Difference: ";
    difference.Print();
    std::cout <<'\n';
    MySet<int> sym_diff = set.SymmetricDifference(another);
    std::cout << "Symmetric difference: ";
    sym_diff.Print();*/
    TestAdd();
    TestRemove();
    TestUnion();
    TestIntersection();
    TestDifference();
    TestSymmDiff();
}