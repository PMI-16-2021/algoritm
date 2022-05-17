#include "hashtable_test.h"

HashTable<int> table_test;

void TestHash() {
    std::string tester = "kyiv";
    if(table_test._hash(tester) == 0) { // k=107, y=121. result=(107*7+121)%10 = 3
        std::cout<<"TestHash passed✅\n";
    }
    else {
        std::cerr<<"TestHash failed❌\n";
    }
}

void TestAdd() {
    TableElem<int> elem("jonsonuk", 48);
    table_test.Add(elem);
    if(table_test.Get("jonsonuk") == elem.value) {
        std::cout<<"TestAdd passed✅\n";
    }
    else {
        std::cerr<<"TestAdd failed❌\n";
    }
}

void TestGet(){
    TableElem<int> elem1("ACDC", 1020);
    TableElem<int> elem2("Metalica", 1030);
    table_test.Add(elem1);
    table_test.Add(elem2);
    if(table_test.Get("Metalica") == 1030) {
        try{
            table_test.Get("Queen");
        }
        catch(HashTable<int>::NotFound) {
            std::cout<<"TestGet passed✅\n";
        }
    }
    else {
        std::cerr<<"TestGet failed❌\n";
    }
}

void TestPop() {
    if(table_test.Pop("jonsonuk") == 48) {
        std::cout<<"TestPop passed✅\n";
    }
    else {
        std::cerr<<"TestPop failed❌\n";
    }
}