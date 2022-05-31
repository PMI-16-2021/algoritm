#pragma once
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

struct rule
{
    std::string pattern;
    std::string replacement;
    bool terminal;
    rule(std::string pat, std::string rep, bool term) :
        pattern(pat),
        replacement(rep),
        terminal(term)
    {
    }
};

std::string const whitespace = " \t";
std::string::size_type const npos = std::string::npos;

bool is_whitespace(char c)
{
    return whitespace.find(c) != npos;
}

std::vector<rule> read_rules(std::ifstream& rulefile)
{
    std::vector<rule> rules;
    std::string line;
    while (std::getline(rulefile, line))
    {
        std::string::size_type pos;

    
        pos = line.find('#');
        if (pos != npos)
            line.resize(pos);

        
        if (line.find_first_not_of(whitespace) == npos)
            continue;

       
        pos = line.find("->");
        while (pos != npos && (pos == 0 || !is_whitespace(line[pos - 1])))
            pos = line.find("->", pos + 1);

        if (pos == npos || line.length() < pos + 3 || !is_whitespace(line[pos + 2]))
        {
            std::cerr << "invalid rule: " << line << "\n";
            std::exit(EXIT_FAILURE);
        }

        std::string pattern = line.substr(0, pos - 1);
        std::string replacement = line.substr(pos + 3);

        pattern.erase(pattern.find_last_not_of(whitespace) + 1);
        replacement.erase(0, replacement.find_first_not_of(whitespace));

        bool terminal = !replacement.empty() && replacement[0] == '.';
        if (terminal)
            replacement.erase(0, 1);

        rules.push_back(rule(pattern, replacement, terminal));
    }

    return rules;
}

std::string markov(std::vector<rule> rules, std::string input)
{
    std::string& output = input;
    std::vector<rule>::iterator iter = rules.begin();

    while (iter != rules.end())
    {
        std::string::size_type pos = output.find(iter->pattern);
        if (pos != npos)
        {
            output.replace(pos, iter->pattern.length(), iter->replacement);
            if (iter->terminal)
                break;
            iter = rules.begin();
        }
        else
            ++iter;
    }

    return output;
}