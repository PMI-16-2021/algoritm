#include <iostream>
#include "markov.h"
using namespace std;

String::String(const char* letters) 
{
    this->letters = _strdup(letters);
    for (length = 0; *(letters + length) != '\0'; length++);
}

int String::getLength()
{
    return length;
}

char* String::getLetters()
{
    return letters;
}

char* String::find(String& substring) 
{
    if (substring.getLetters()[0] == '\0')
    {
        return getLetters();
    }
    if (substring.length <= length)
    {
        for (int i = 0; i <= length - substring.length; ++i)
        {
            for (int j = 0; j < substring.length; ++j)
            {
                if (letters[i + j] != substring.letters[j])
                {
                    break;
                }
                else 
                {
                    if (j == substring.length - 1)
                    {
                        return letters + i;
                    }
                }
            }
        }
    }
    return nullptr;
}

void String::replace(String& a, String& b) 
{
    if (a.letters[0] != '\0') 
    {
        String start(find(a));
        String tail(start.getLetters() + a.length);
        int lng = length - start.length + b.length + tail.length + 1;
        char* link = new char[lng];
        for (int i = 0; i < length - start.length; ++i) 
        {
            link[i] = getLetters()[i];
        }
        for (int i = 0; i < b.length; ++i) 
        {
            link[i + length - start.length] = b.getLetters()[i];
        }
        for (int i = 0; i < tail.length + 1; ++i) 
        {
            link[i + length - start.length + b.length] = tail.getLetters()[i];
        }
        letters = link;
        length = lng - 1;
    }
    else 
    {
        int lng = b.length + length + 1;
        char* link = new char[lng];
        for (int i = 0; i < b.length; ++i) 
        {
            link[i] = b.letters[i];
        }
        for (int i = 0; i < length + 1; ++i) 
        {
            link[b.length + i] = letters[i];
        }
        letters = link;
        length = lng - 1;
    }
}

void String::markov(std::vector<std::pair<String, String>>& rules) 
{
    for (int i = 0; i < rules.size();)
    {
        if (find(rules[i].first))
        {
            if (rules[i].second.getLetters()[0] == '.')
            {
                String temp = rules[i].second.letters + 1;
                replace(rules[i].first, temp);
                break;
            }
            replace(rules[i].first, rules[i].second);
            i = 0;
            continue;
        }
        ++i;
    }
}