#include "pch.h"
#include <gtest/gtest.h>
#include"..//MarkovAlgorithm/MarkovAlgorithm.cpp"
Rule a1("ab", "b", false);
Rule a2("b", "", false);
Rule a3("df", "ab", false);
Rule a4("ca", "l", false);
Rule a5("", "aa", true);

vector<Rule>rules;
string text;

TEST(Markov, MarkovTest1)
{
    rules.emplace_back(a1);
    rules.emplace_back(a2);
    rules.emplace_back(a3);
    rules.emplace_back(a4);
    rules.emplace_back(a5);

    text = "abbabbbabcadfca";

    EXPECT_EQ(markovAlgorithm(rules, text), "aacl");
}

TEST(Markov, MarkovTest2)
{
    a1.from = "1"; a1.to = "0|";
    a2.from = "|0"; a2.to = "0||";
    a3.from = "0"; a3.to = "";
    rules.clear();

    rules.emplace_back(a1);
    rules.emplace_back(a2);
    rules.emplace_back(a3);

    text = "101";

    EXPECT_EQ(markovAlgorithm(rules, text), "|||||");

}

TEST(Markov, MarkovTest3)
{
    a1.from = "ba"; a1.to = "ab";
    a2.from = "cb"; a2.to = "bc";
    a3.from = "ca"; a3.to = "ac";
    rules.clear();

    rules.emplace_back(a1);
    rules.emplace_back(a2);
    rules.emplace_back(a3);

    text = "cbabca";

    EXPECT_EQ(markovAlgorithm(rules, text), "aabbcc");

}

TEST(Markov, MarkovTest4)
{
    a1.from = "ab"; a1.to = "d";
    a2.from = "dc"; a2.to = "ab";
    rules.clear();

    rules.emplace_back(a1);
    rules.emplace_back(a2);
    rules.emplace_back(a3);

    text = "abc";

    EXPECT_EQ(markovAlgorithm(rules, text), "d");

}

int main(int argc, char** argv)
{
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}