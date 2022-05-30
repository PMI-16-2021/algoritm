#include "markov.h"
#include "tests.h"
using namespace std;

bool SubTest()
{
    vector<Rule> rules;
    NewStr Expression("abbbcaa");
    Rule Rule1("aa", "a", false);
    rules.push_back(Rule1);
    Rule Rule2("bb", "b", false);
    rules.push_back(Rule2);
    Rule Rule3("cc", "c", true);
    rules.push_back(Rule3);
    NewStr result = Markov(Expression, rules);
    if (result == "abca")
    {
        return true;
    }
}

bool AddTest()
{
    vector<Rule> rules;
    NewStr Expression("ab+bc is");
    Rule Rule1("+", "", true);
    rules.push_back(Rule1);
    NewStr res = Markov(Expression, rules);
    if (res == "abbc is")
    {
        return true;
    }
}

bool MultTest()
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
    if (res == "||||||||||||")
    {
        return true;
    }
}

bool BinaryTest()
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
    if (res == "||||||")
    {
        return true;
    }
}

void Test01()
{
    assert(SubTest() == true);
    cout << "Sub test passed\n";
}

void Test02()
{
    assert(AddTest() == true);
    cout << "Add test passed\n";
}

void Test03()
{
    assert(MultTest() == true);
    cout << "Mult test passed\n";

}

void Test04()
{
    assert(BinaryTest() == true);
    cout << "Binary test passed\n";
}