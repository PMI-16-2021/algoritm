#include "my_set.h"
int main() {
    MySet<int> S;
    S.Add(1);
    S.Add(2);
    S.Add(3);
    S.Add(4);
    S.Add(5);
    S.Add(6);
    S.Add(7);
    S.Add(8);
    S.Add(9);
    std::cout << "Set: ";
    S.Print();
    std::cout <<'\n';
    MySet<int> other;
    other.Add(1);
    other.Add(3);
    other.Add(5);
    other.Add(7);
    other.Add(9);
    other.Add(10);
    other.Add(17);
    other.Add(19);
    std::cout << "Another Set: ";
    other.Print();
    std::cout << '\n';
    MySet<int> union_set = S.Union(other);
    std::cout << "Union: ";
    union_set.Print();
    std::cout <<'\n';
    MySet<int> intersection_set = S.Intersection(other);
    std::cout << "Intersection: ";
    intersection_set.Print();
    std::cout <<'\n';
    MySet<int> difference_set = S.Difference(other);
    std::cout << "Difference: ";
    difference_set.Print();
    std::cout <<'\n';
    MySet<int> symmetric_difference_set = S.SymmetricDifference(other);
    std::cout << "Symmetric difference: ";
    symmetric_difference_set.Print();

    system("pause");
    return 0;
}