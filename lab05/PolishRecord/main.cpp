#include <iostream>
#include "funcs.h"
#include "tests.h"

int main() {
    std::cout << "Enter a record: ";
    std::string record;
    std::cin >> record;
    std::cout << '\n' << PolishRecord(record) << '\n';
    std::cout << Calculate(PolishRecord(record)) << '\n';
    TestResult();
    TestBrackets();
    RecordTest();
}

