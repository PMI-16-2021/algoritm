#pragma once
#include<iostream>
#include<vector>
using namespace std;

class NewStr
{
private:
    char* line;
    int size;
public:
    NewStr() :line(nullptr), size(0) {}
    NewStr(const char* in);
    int length();
    int length(const char* in);
    int FindPosition(NewStr substring);
    void Replace(NewStr changed, NewStr replaced);
    NewStr operator +(const NewStr& A);
    bool operator ==(const NewStr& A);
    char& operator [](const int i);
    NewStr operator =(NewStr& A);
    NewStr operator =(const char* A);
    friend ostream& operator<<(ostream& os, const NewStr& A);
    friend istream& operator>>(istream& is, NewStr& A);
};

struct Rule
{
    NewStr change_string;
    NewStr replace_string;
    bool is_last;

    Rule() : change_string(" "), replace_string(" "), is_last(false)
    {
    }
    Rule(NewStr pattern, NewStr replace_str, bool is_last)
    {
        change_string = pattern;
        this->replace_string = replace_str;
        this->is_last = is_last;
    }
};

NewStr Markov(NewStr string_, vector<Rule> rules);