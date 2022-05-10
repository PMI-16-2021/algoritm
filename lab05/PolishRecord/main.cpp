#include <iostream>
#include "funcs.h"

void Test();

int main() {
    std::cout << "Enter a record: ";
    std::string record;
    std::cin >> record;
    std::cout << '\n' << PolishRecord(record) << '\n';
    std::cout << Calculate(PolishRecord(record)) << '\n';
    Test();
}

void Test() {
    std::string notation = "12^2-(90+23)+10/2";  // result : 16
    if(Calculate(PolishRecord(notation)) == 36){
        std::cout << "Test passed\n";
    }
    else{
        std::cerr << "Test failed\n";
    }
}