#include "tests.h"

void TestSubstitution() {
    const std::vector<std::pair<String,String>> rules {
            std::make_pair("ab", "b"),
            std::make_pair("ac", "c"),
            std::make_pair("aa", "a"),
    };
    String result = MarkovAlgorithm(rules, "bacaabaa"); // bacabaa-> bacbaa-> bcbaa-> bcba
    if(result == "bcba") {
        std::cout << "Test Substitution passed\n";
    }
    else {
        std::cerr << "Test Substitution failed\n";
    }
}

void TestAddition() {
    const std::vector<std::pair<String,String>> rules {
            std::make_pair("+", "")
    };
    String result = MarkovAlgorithm(rules, "wat+er+ +is+ +health");
    if(result == "water is health") {
        std::cout << "Test Addition passed\n";
    }
    else {
        std::cerr << "Test Addition failed\n";
    }
}

void TestMultiply() {
    const std::vector<std::pair<String,String>> rules {
            std::make_pair("|b", "ba|"),
            std::make_pair("ab", "ba"),
            std::make_pair("b", ""),
            std::make_pair("*|", "b*"),
            std::make_pair("*", "c"),
            std::make_pair("|c", "c"),
            std::make_pair("ac", "c|"),
            std::make_pair("c", ""),
    };
    String result = MarkovAlgorithm(rules, "||||*|||");
    if(result == "||||||||||||") {
        std::cout << "Test Multiply passed\n";
    }
    else {
        std::cerr << "Test Multiply failed\n";
    }
}

void TestToBinary() {
    const std::vector<std::pair<String,String>> rules {
            std::make_pair("|0", "0||"),
            std::make_pair("1", "0|"),
            std::make_pair("0", "")
    };
    String result = MarkovAlgorithm(rules, "101");
    if(result == "|||||") {
        std::cout << "Test To Binary passed\n";
    }
    else {
        std::cerr << "Test To Binary failed\n";
    }
}

void TestSentence() {
    const std::vector<std::pair<String,String>> rules {
            std::make_pair("A", "apple"),
            std::make_pair("B", "bag"),
            std::make_pair("S", "shop"),
            std::make_pair("T", "the"),
            std::make_pair("the shop", "my brother"),
            std::make_pair("a never used", "terminating rule")
    };
    String result = MarkovAlgorithm(rules, "I bought a B of As from T S.");
    if(result == "I bought a bag of apples from my brother.") {
        std::cout << "Test Sentence passed\n";
    }
    else {
        std::cerr << "Test Sentence failed\n";
    }
}
