#include "markov.h"

Rule::Rule() : before(""), after(".") {}

Rule::Rule(const std::string& b, const std::string& a) : before(b), after(a) {}

Rule::~Rule() {}

bool Rule::apply(std::string& word)
{
    if (word.find(before) != std::string::npos)
    {
        word.replace(word.find(before), before.length(), after);
        return true;
    }
    return false;
}

bool Rule::terminal()
{
    if (this->after[0] == '.')
    {
        after.erase(0);
        return true;
    }
    return false;
}

void algorithm(std::string& word, std::vector<Rule>& rules)
{
    std::vector<Rule>::iterator itr = rules.begin();
    while (itr != rules.end())
    {
        if (itr == rules.end()--)
        {
            if (!itr->apply(word))
            {
                break;
            }
        }

        if (!itr->terminal())
        {
            if (itr->apply(word))
            {
                itr = rules.begin();
            }
            else
            {
                itr++;
            }
        }
        else
        {
            itr->apply(word);
            break;
        }
    }
}
