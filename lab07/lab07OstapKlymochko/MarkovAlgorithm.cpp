#include <vector>
#include<string>
using namespace std;

struct Rule
{
    string from;
    string to;
    bool terminal;

    Rule(string from, string to, bool terminal) : from(std::move(from)), to(std::move(to)), terminal(terminal) {}
};

string markovAlgorithm(vector<Rule> rules, string text)
{
    string result = text;
    auto iter = rules.begin();

    while (iter != rules.end())
    {
        size_t pos = result.find(iter->from);
        if (pos != string::npos)
        {
            result.replace(pos, iter->from.length(), iter->to);
            if (iter->terminal)
            {
                break;
            }
            iter = rules.begin();
        }
        else
        {
            ++iter;
        }
    }
    return result;
}