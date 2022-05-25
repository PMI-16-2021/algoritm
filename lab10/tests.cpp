#include "tests.h"

Tree<int> tree;

void TestInsert() {
    tree.Insert(6);
    tree.Insert(7);
    tree.Insert(4);
    tree.Insert(10);
    tree.Insert(8);
    if(tree.Get(8) == 8 && tree.TreeHeight() == 2) {
        std::cout << "Insertion Test passed\n";
    }
    else {
        std::cerr << "Insertion Test failed\n";
    }
}

void TestIsIn() {
    if(tree.IsIn(100500) == false && tree.IsIn(10) == true) {
        std::cout << "IsIn Test passed\n";
    }
    else {
        std::cerr << "IsIn Test failed\n";
    }
}

void TestRemove() {
    tree.Remove(8);
    tree.Remove(7);
    if(!tree.IsIn(8) && !tree.IsIn(7)  && tree.TreeHeight() == 1) {
        std::cout << "Remove Test passed\n";
    }
    else {
        std::cerr << "Remove Test failed\n";
    }
}

void TestGet() {
    if(tree.Get(8) == -404 && tree.Get(4) == 4) {
        std::cout << "Get Test passed\n";
    }
    else {
        std::cerr << "Get Test failed\n";
    }
}

void TestHeight() {
    tree.Insert(9);
    tree.Insert(12);
    tree.Insert(9);
    tree.Insert(8);
    tree.Insert(3);
    tree.Insert(2);
    tree.Insert(34);
    tree.Insert(14);
    tree.Insert(65);
    tree.Insert(43);
    tree.Insert(78);
    tree.Insert(0);
    if(tree.TreeHeight() == 3) {
        std::cout << "Height Test passed\n";
    }
    else {
        std::cerr << "Height Test failed\n";
    }
}
