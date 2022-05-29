#include "Tests.h"

bool TestSubstitution()
{
    vector<Rule> rules;
    NewStr Expression("abbbcaa"); //abbbcaa->abbca-> abca
    Rule Rule1("aa", "a", false);
    rules.push_back(Rule1);
    Rule Rule2("bb", "b", false);
    rules.push_back(Rule2);
    Rule Rule3("cc", "c", true);
    rules.push_back(Rule3);
    NewStr result = Markov(Expression, rules);
    if(result == "abca")
        return true;
}
bool TestAdd()
{
    vector<Rule> rules;
    NewStr Expression("lo+ve is");
    Rule Rule1("+", "", true);
    rules.push_back(Rule1);
    NewStr res = Markov(Expression, rules);
    if(res=="love is")
        return true;
}
bool TestMultiply()
{
    vector<Rule> rules1;
    NewStr Expression1("||||*|||");
    Rule rule1("|b", "ba|", false);
    rules1.push_back(rule1);
    Rule rule2("ab", "ba", false);
    rules1.push_back(rule2);
    Rule rule3("b", "", false);
    rules1.push_back(rule3);
    Rule rule4("*|", "b*", false);
    rules1.push_back(rule4);
    Rule rule5("*", "c", false);
    rules1.push_back(rule5);
    Rule rule6("|c", "c", false);
    rules1.push_back(rule6);
    Rule rule7("ac", "c|", false);
    rules1.push_back(rule7);
    Rule rule8("c", "\0", true);
    rules1.push_back(rule8);
    NewStr res = Markov(Expression1, rules1);
    if(res=="||||||||||||")
        return true;
}
bool TestToBinary()
{
    vector<Rule> rules1;
    NewStr Expression1("110");
    Rule rule1("|0", "0||", false);
    rules1.push_back(rule1);
    Rule rule2("1", "0|", false);
    rules1.push_back(rule2);
    Rule rule3("0", "", false);
    rules1.push_back(rule3);
    NewStr res = Markov(Expression1, rules1);
    if(res=="||||||")
        return true;
}

void Test1()
{
    assert(TestSubstitution()==true);
    cout<<"Test on substitution is PASSED!\n";
}
void Test2()
{
    assert(TestAdd()==true);
    cout<<"Test on addition is PASSED!\n";
}
void Test3()
{
    assert(TestMultiply()==true);
    cout<<"Test on multiply is PASSED!\n";

}
void Test4()
{
    assert(TestToBinary()==true);
    cout<<"Test to binary is PASSED!\n";
}
