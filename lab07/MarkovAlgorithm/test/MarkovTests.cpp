#include <gtest/gtest.h>
#include "MyString.h"
#include "BadRuleException.h"

TEST(StringMethodsTestSuite, getLengthTest) {
    MyString myString1 = "Ukraine";
    EXPECT_EQ(7, myString1.getLength());
    MyString myString2;
    EXPECT_EQ(0, myString2.getLength());
}

TEST(StringMethodsTestSuite, findMethodTest) {
    MyString myString1 = "Ukraine";
    EXPECT_EQ(3, myString1.find("aine"));
    EXPECT_EQ(-1, myString1.find(""));
    EXPECT_EQ(-1, myString1.find("air"));
    EXPECT_EQ(6, myString1.find("e"));
}

TEST(StringMethodsTestSuite, substrTest) {
    MyString myString1 = "Ukraine";
    MyString newMyString = myString1.substr(1, 2);
    MyString correctString = "kr";
    EXPECT_EQ(newMyString, correctString);
}

TEST(StringMethodsTestSuite, replaceTest) {
    MyString myString1 = "Ukraine";
    myString1.replace("Ukraine", "I am Ukrainian");
    MyString correctString = "I am Ukrainian";
    EXPECT_EQ(correctString, myString1);
}

TEST(StringMethodsTestSuite, comparisonOperator) {
    MyString myString1 = "Ukraine";
    MyString myString2 = "Petro";
    MyString myString3 = "Ukraine";
    EXPECT_TRUE(myString1 == myString3);
    EXPECT_FALSE(myString1 == myString2);
}

TEST(MarkovAlgorithmTestSuite, test1) {
    std::vector<Rule> rules;
    Rule a1("|b", "ba|");
    Rule a2("ab", "ba");
    Rule a3("b", "");
    Rule a4("*|", "b*");
    Rule a5("*", "c");
    Rule a6("|c", "c");
    Rule a7("ac", "c|");
    Rule a8("c", "", true);
    rules.push_back(a1);
    rules.push_back(a2);
    rules.push_back(a3);
    rules.push_back(a4);
    rules.push_back(a5);
    rules.push_back(a6);
    rules.push_back(a7);
    rules.push_back(a8);
    MyString result = markovAlgorithm(rules, "|*||");
    MyString correctResult = "||";
    EXPECT_EQ(result, correctResult);
}

TEST(MarkovAlgorithmTestSuite, test2) {
    std::vector<Rule> rules;
    Rule a1("F", "food");
    Rule a2("T", "tesla");
    Rule a3("A", "apple");
    Rule a4("", "", true);
    rules.push_back(a1);
    rules.push_back(a2);
    rules.push_back(a3);
    rules.push_back(a4);

    MyString result = markovAlgorithm(rules, "She bought an A in F store.");
    MyString correctResult = "She bought an apple in food store.";
    EXPECT_EQ(result, correctResult);
}

TEST(MarkovAlgorithmTestSuite, test3) {
    std::vector<Rule> rules;
    Rule a1("A0", "1B");
    Rule a2("0A1", "C01");
    Rule a3("1A1", "C11");
    Rule a4("0B0", "A01");
    Rule a5("1B0", "A11");
    Rule a6("B1", "1B");
    Rule a7("0C0", "B01");
    Rule a8("1C0", "B11");
    Rule a9("0C1", "H01");
    Rule a10("1C1", "H11");
    rules.push_back(a1);
    rules.push_back(a2);
    rules.push_back(a3);
    rules.push_back(a4);
    rules.push_back(a5);
    rules.push_back(a6);
    rules.push_back(a7);
    rules.push_back(a8);
    rules.push_back(a9);
    rules.push_back(a10);
    MyString result = markovAlgorithm(rules, "000000A000000");
    MyString correctResult = "00011H1111000";
    EXPECT_EQ(result, correctResult);
}