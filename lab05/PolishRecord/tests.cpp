#include "tests.h"
#include "funcs.h"

void TestResult() {
    std::string notation = "12^2-(90+23)+10/2";  // result : 36
    if(Calculate(PolishRecord(notation)) == 36){
        std::cout << "TestResult passed\n";
    }
    else{
        std::cerr << "TestResult failed\n";
    }
}

void TestBrackets() {
    std::string notation = "12^2-((90+23)+10/2))";
    if(CheckBrackets(notation) == false) {
        std::cout << "TestBrackets passed\n";
    }
    else{
        std::cerr << "TestBrackets failed\n";
    }
}

void RecordTest() {
    std::string notation = "12^2-((90+23)+10/2)";  // result : 36
    std::string expected = "12_2_^90_23_+10_2_/+-";
    if(PolishRecord(notation) == expected) {
        std::cout << "RecordTest passed\n";
    }
    else{
        std::cerr << "RecordTest failed\n";
    }
}