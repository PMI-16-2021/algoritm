#include "tests.h"

void TestSubstitution() {
    const std::vector<std::pair<String,String>> rules {  // <антицедент,консеквент>
            std::make_pair("ab", "b"),
            std::make_pair("ac", "c"),
            std::make_pair("aa", "a"),
    };
    String result = MarkovAlgoritm(rules, "bacaabaa");
    if(result == "bcba") {
        std::cout << "Test Substitution passed\n";
    }
    else {
        std::cerr << "Test Substitution failed\n";
    }
}

void TestMultiply() {
    const std::vector<std::pair<String,String>> rules {  // <антицедент,консеквент>
            std::make_pair("|b", "ba|"),
            std::make_pair("ab", "ba"),
            std::make_pair("b", ""),
            std::make_pair("*|", "b*"),
            std::make_pair("*", "c"),
            std::make_pair("|c", "c"),
            std::make_pair("ac", "c|"),
            std::make_pair("c", ""),
    };
    String result = MarkovAlgoritm(rules, "||||*|||");
    if(result == "||||||||||||") {
        std::cout << "Test Multiply passed\n";
    }
    else {
        std::cerr << "Test Multiply failed\n";
    }
}

void TestToBinary() {
    const std::vector<std::pair<String,String>> rules {  // <антицедент,консеквент>
            std::make_pair("|0", "0||"),
            std::make_pair("1", "0|"),
            std::make_pair("0", "")
    };
    String result = MarkovAlgoritm(rules, "101");
    if(result == "|||||") {
        std::cout << "Test To Binary passed\n";
    }
    else {
        std::cerr << "Test To Binary failed\n";
    }
}