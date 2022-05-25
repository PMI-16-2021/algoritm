#include "tests.h"
#include "my_set.h"

MySet<int> set;

void TestAdd() {
    set.Add(6);
    set.Add(6);
    set.Add(0);
    set.Add(9);
    if(set.Len() == 3) {
        std::cout << "TestAdd passed\n";
    }
    else {
        std::cerr << "TestAdd failed\n";
    }
}

void TestRemove() {
    set.Remove(0);
    if(!set.IsIn(0)){
        std::cout << "TestRemove passed\n";
    }
    else {
        std::cerr << "TestRemove failed\n";
    }
}

void TestUnion() {
    set.Add(2);
    set.Add(7);
    set.Add(5);
    set.Add(1);
    MySet<int> another;
    another.Add(8);
    another.Add(4);
    another.Add(9);
    another.Add(12);
    another.Add(5);
    another.Add(2);
    //set: 6 9 2 7 5 1
    //another: 8 4 9 12 5 2
    int res[] = {6, 9, 2, 7, 5, 1, 8, 4, 12};
    MySet<int> union_ = set.Union(another);
    int* union_test = union_.GetSet();
    bool test = false;
    for(int i = 0; i < union_.GetUsed(); i++) {
        if(union_test[i] == res[i]){
            test = true;
        }
        else{
            test = false;
        }
    }
    if(test){
        std::cout << "TestUnion passed\n";
    }
    else {
        std::cerr << "TestUnion failed\n";
    }
}

void TestIntersection() {
    //set: 6 9 2 7 5 1
    //another: 8 4 9 12 5 2
    MySet<int> another;
    another.Add(8);
    another.Add(4);
    another.Add(9);
    another.Add(12);
    another.Add(5);
    another.Add(2);
    int res[] = {9,2,5};
    MySet<int> intersection = set.Intersection(another);
    int* intersection_test = intersection.GetSet();
    bool test = false;
    for(int i = 0; i < intersection.GetUsed(); i++) {
        if(intersection_test[i] == res[i]){
            test = true;
        }
        else{
            test = false;
        }
    }
    if(test){
        std::cout << "TestIntersection passed\n";
    }
    else {
        std::cerr << "TestIntersection failed\n";
    }
}

void TestDifference() {
    //set:     6 9 2 7 5 1
    //another: 8 4 9 12 5 2
    MySet<int> another;
    another.Add(8);
    another.Add(4);
    another.Add(9);
    another.Add(12);
    another.Add(5);
    another.Add(2);
    int res[] = {6,7,1};
    MySet<int> difference = set.Difference(another);
    int* difference_test = difference.GetSet();
    bool test = false;
    for(int i = 0; i < difference.GetUsed(); i++) {
        if(difference_test[i] == res[i]){
            test = true;
        }
        else{
            test = false;
        }
    }
    if(test){
        std::cout << "TestDifference passed\n";
    }
    else {
        std::cerr << "TestDifference failed\n";
    }
}

void TestSymmDiff() {
    //set:     6 9 2 7 5 1
    //another: 8 4 9 12 5 2
    MySet<int> another;
    another.Add(8);
    another.Add(4);
    another.Add(9);
    another.Add(12);
    another.Add(5);
    another.Add(2);
    int res[] = {6, 7, 1, 8, 4, 12};
    MySet<int> symm_diff = set.SymmetricDifference(another);
    int* symm_test = symm_diff.GetSet();
    bool test = false;
    for(int i = 0; i < symm_diff.GetUsed(); i++) {
        if(symm_test[i] == res[i]){
            test = true;
        }
        else{
            test = false;
        }
    }
    if(test){
        std::cout << "TestSymmDiff passed\n";
    }
    else {
        std::cerr << "TestSymmDiff failed\n";
    }
}